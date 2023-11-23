//
//  ASTNodes.h
//  ECE467 Lab 3
//
//  Created by Tarek Abdelrahman on 2023-09-13.
//  Based on code written by Ao (Dino) Li for ECE467.
//  Copyright © 2023 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE467 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

#ifndef ASTNodes_h
#define ASTNodes_h

#include <iostream>
using namespace std;

#include <vector>
#include <string>
#include <sstream>
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Verifier.h"

#include "ASTVisitorBase.h"
#include "SymTable.h"

using namespace llvm;

namespace smallc {

class ProgramNode;

/**********************************************************************************/
/* The ASTNode Class   (abstract)                                                 */
/**********************************************************************************/
class ASTNode {
private:
    // Vector of this node's children
    vector<ASTNode*> children;
    
    // Pointer to this node's parents
    ASTNode* parent;
    
    std::pair<unsigned int, unsigned int> location;
    
    // Pointer to the program this node belongs to
    ProgramNode* root;
    
protected:
    ASTNode(); // Constructor
    
public:
    virtual ~ASTNode(); // Destructor
    // Accessors
    ASTNode* getParent(); // Get parent of this node in the AST
    ASTNode* getChild(unsigned int i); // Get child at iundex i
    unsigned int getNumChildren(); // Get number of children
    unsigned int getLine();   // Get line number of node in source
    unsigned int getCol();    // Get column number of node in line
    std::pair<unsigned int, unsigned int> getLocation(); // Get location
    ProgramNode* getRoot(); // Get the root program
    virtual bool hasVarTable(); // Does the node have a variable symbol table?
    FunctionDeclNode* getFunction (); // Get the function associated with the node, or nullptr
    
    // Mutators
    void addChild(ASTNode* child); // Add a child
    void setParent(ASTNode* p);    // Set the parent
    void setRoot(ProgramNode* r);  // Set the root pointer
    void setLine(unsigned int line); // Set the line number of the node in source
    void setColumn(unsigned int column); // Set the column number of node in line
    void setLocation(unsigned int line, unsigned int column); // set location <line,column>
    void setLocation(std::pair<unsigned int, unsigned int> loc); // set location <line,column>

    // Visit the node using the visitor object
    // NOTE: this is an abstract class!
    virtual void visit(ASTVisitorBase* visitor) = 0;
};

/**********************************************************************************/
/* The ProgramNode Class                                                          */
/**********************************************************************************/
class ProgramNode : public ASTNode {
private:
    bool iolib;                    // Is the I/O lib used?
    SymTable<FunctionEntry>* fenv; // Pointer to function symbol table
    SymTable<VariableEntry>* venv; // Pointer to variable symbol table

public:
    ProgramNode();         // Constructor
    void setIo(bool flag); // Set the I/O flag
    bool useIo();          // Get the I/O flag
    SymTable<FunctionEntry>* getFuncTable (); // Get the function table
    SymTable<VariableEntry>* getVarTable();   // Get the variable table
    bool hasVarTable() override; // Check if there is a variable symbol table
    
    void visit(ASTVisitorBase* visitor) override;
};

/**********************************************************************************/
/* The TypeNode Class   (abstract)                                                */
/**********************************************************************************/
class TypeNode: public ASTNode{
public:
    enum TypeEnum {Void = 0, Int, Bool};  // The types
    virtual void setType(TypeEnum);       // Set the type
    virtual TypeEnum getTypeEnum() const;       // Get the type
    virtual bool isArray();
    void visit(ASTVisitorBase* visitor) override = 0;
};

/**********************************************************************************/
/* The PrimitiveTypeNode Class                                                    */
/**********************************************************************************/
class PrimitiveTypeNode : public TypeNode {
private:
    TypeEnum type;
    
public:
    PrimitiveTypeNode();
    explicit PrimitiveTypeNode(TypeEnum type_);
    void setType(TypeEnum type_) override;
    TypeEnum getTypeEnum() const override;
    bool operator == (const PrimitiveTypeNode& t);
    bool operator != (const PrimitiveTypeNode& t);
    void visit(ASTVisitorBase* visitor) override;
};

/**********************************************************************************/
/* The ArrayTypeNode Class                                                        */
/**********************************************************************************/
class ArrayTypeNode : public TypeNode {
private:
    PrimitiveTypeNode* type; // The element type
    int size;   // The size of the array, leaving as signed to check for size in Sema
    
public:
    ArrayTypeNode();
    explicit ArrayTypeNode(PrimitiveTypeNode *type_);
    ArrayTypeNode(PrimitiveTypeNode* type_, int size_);
    void setType(TypeEnum type_) override;
    TypeEnum getTypeEnum() const override;
    void setSize(int size_);
    int getSize();
    bool operator == (const ArrayTypeNode& t);
    bool operator != (const ArrayTypeNode& t);
    bool isArray() override;
    void visit(ASTVisitorBase* visitor) override;
};

/**********************************************************************************/
/* The IdentifierNode Class                                                       */
/**********************************************************************************/
class IdentifierNode : public ASTNode {
private:
    std::string name;
    
public:
    IdentifierNode();
    explicit IdentifierNode(const std::string &text);
    const std::string& getName();
    void visit(ASTVisitorBase* visitor) override;
};

/**********************************************************************************/
/* The ParameterNode Class                                                        */
/**********************************************************************************/
class ParameterNode : public ASTNode {
private:
    TypeNode *type;            // Type of identifier
    IdentifierNode *name;      // Name of Identifier
    
public:
    ParameterNode();
    ParameterNode(TypeNode *type_, IdentifierNode *name_);
    void setType(TypeNode *type_);
    TypeNode*& getType();
    void setIdent(IdentifierNode *&name_);
    IdentifierNode*& getIdent();
    void visit(ASTVisitorBase* visitor) override;
};

/**********************************************************************************/
/* The Expression Class      (abstract)                                           */
/**********************************************************************************/
class ExprNode : public ASTNode {
private:
    PrimitiveTypeNode *type;
    llvm::Value* value;
    
protected:
    ExprNode();
    
public:
    enum Opcode {
        Addition = 0,
        Subtraction,
        Multiplication,
        Division,
        Not,
        Minus,
        And,
        Or,
        Equal,
        NotEqual,
        LessThan,
        LessorEqual,
        Greater,
        GreaterorEqual,
        Unset = -1
    };
    
    void setType(PrimitiveTypeNode* type_);
    void setTypeInt();
    void setTypeBool();
    void setTypeVoid();
    PrimitiveTypeNode* getType();
    static std::string codeToStr(int code) {
        switch (code) {
            case Addition:
                return "+";
            case Subtraction:
                return "-";
            case Multiplication:
                return "*";
            case Division:
                return "/";
            case Not:
                return "!";
            case Minus:
                return "-";
            case And:
                return "&&";
            case Or:
                return "||";
            case Equal:
                return "==";
            case NotEqual:
                return "!=";
            case LessThan:
                return "<";
            case LessorEqual:
                return "<=";
            case Greater:
                return ">";
            case GreaterorEqual:
                return ">=";
            default:
                return "unset";
        }
    }
    
    void setLLVMValue(llvm::Value* val);

    llvm::Value* getLLVMValue();

    void visit(ASTVisitorBase* visitor) override = 0;
};

/**********************************************************************************/
/* The Unary Expression Class                                                     */
/**********************************************************************************/
class UnaryExprNode : public ExprNode {
private:
    ExprNode *operand;
    Opcode opcode;
    
public:
    UnaryExprNode();
    explicit UnaryExprNode(ExprNode *expr);
    UnaryExprNode(ExprNode *expr, Opcode code);
    ExprNode* getOperand();
    void setOperand(ExprNode *operand_);
    Opcode getOpcode();
    void setOpcode(Opcode code);
    void setOpcode(std::string code);
    void visit(ASTVisitorBase* visitor) override;
};

/**********************************************************************************/
/* The Binary Expression Class                                                    */
/**********************************************************************************/
class BinaryExprNode : public ExprNode {
private:
    ExprNode* left;
    ExprNode* right;
    Opcode opcode;
    
public:
    BinaryExprNode();
    BinaryExprNode(ExprNode *l, ExprNode *r);
    BinaryExprNode(ExprNode *l, ExprNode *r, Opcode code);
    ExprNode* getLeft();
    void setLeft(ExprNode *l);
    ExprNode* getRight();
    void setRight(ExprNode* r);
    Opcode getOpcode();
    void setOpcode(Opcode code);
    void setOpcode(std::string code);
    void visit(ASTVisitorBase* visitor) override;
};

/**********************************************************************************/
/* The Boolean Expression Class                                                   */
/**********************************************************************************/
class BoolExprNode : public ExprNode {
private:
    ExprNode* value;
    
public:
    BoolExprNode();
    explicit BoolExprNode(ExprNode *val);
    ExprNode* getValue();
    void setValue(ExprNode *val);
    Opcode getOpcode();
    void visit(ASTVisitorBase* visitor) override;
};

/**********************************************************************************/
/* The Integer Expression Class                                                   */
/**********************************************************************************/
class IntExprNode : public ExprNode {
private:
    ExprNode* value;
    
public:
    IntExprNode();
    explicit IntExprNode(ExprNode *val);
    ExprNode* getValue();
    void setValue(ExprNode *val);
    Opcode getOpcode();
    void visit(ASTVisitorBase* visitor) override;
};

/**********************************************************************************/
/* The Constant Expression Class (abstract)                                       */
/**********************************************************************************/
class ConstantExprNode : public ExprNode {
private:
    std::string source;
    int val;
    
public:
    explicit ConstantExprNode(const std::string &source_);
    void setSource(const std::string &source_);
    int getVal();
    void visit(ASTVisitorBase* visitor) override = 0;
};

/**********************************************************************************/
/* The Boolean Constant Class                                                     */
/**********************************************************************************/
class BoolConstantNode : public ConstantExprNode {
public:
    explicit BoolConstantNode(const std::string &source);
    void visit(ASTVisitorBase* visitor) override;
};

/**********************************************************************************/
/* The Integer Constant Class                                                     */
/**********************************************************************************/
class IntConstantNode : public ConstantExprNode {
public:
    explicit IntConstantNode(const std::string &source);
    void visit(ASTVisitorBase* visitor) override;
};

/**********************************************************************************/
/* The Function Argument Class                                                    */
/**********************************************************************************/
class ArgumentNode : public ASTNode {
private:
    ExprNode* expr;
    
public:
    ArgumentNode();
    explicit ArgumentNode(ExprNode *expr);
    ExprNode* getExpr();
    void setExpr(ExprNode *expr_);
    void visit(ASTVisitorBase* visitor) override;
};


/**********************************************************************************/
/* The Call Expression Class                                                      */
/**********************************************************************************/
class CallExprNode : public ExprNode {
private:
    IdentifierNode *name;
    std::vector<ArgumentNode*> args;
    
public:
    CallExprNode();
    
    explicit CallExprNode(IdentifierNode *callee);
    CallExprNode(IdentifierNode *callee, std::vector<ArgumentNode*> arglist);
    ArgumentNode *getArgument(unsigned int i);
    std::vector<ArgumentNode *> getArguments();
    void addArgument(ArgumentNode *arg) ;
    void setArguments(std::vector<ArgumentNode *> args_) ;
    void setIdent(IdentifierNode *callee) ;
    IdentifierNode *getIdent() ;
    void visit(ASTVisitorBase* visitor) override;
};

/**********************************************************************************/
/* The Reference Expression Class                                                 */
/**********************************************************************************/
class ReferenceExprNode : public ExprNode {
private:
    IdentifierNode *name;
    IntExprNode* index;
    
public:
    ReferenceExprNode();
    explicit ReferenceExprNode(IdentifierNode *name_);
    ReferenceExprNode(IdentifierNode *name_, IntExprNode *exp);
    IdentifierNode* getIdent();
    void setIdent(IdentifierNode *name_);
    void setIndex(IntExprNode *index_);
    IntExprNode* getIndex();
    void visit(ASTVisitorBase* visitor) override;
};

/**********************************************************************************/
/* The Declaration Class (abstract)                                               */
/**********************************************************************************/
class DeclNode : public ASTNode {
private:
    TypeNode* type;
    IdentifierNode *name;
    
public:
    DeclNode();
    DeclNode(TypeNode* type_, IdentifierNode* name_);
    void setName(IdentifierNode* name_);
    void setType(TypeNode* type_);
    IdentifierNode* getIdent();
    virtual TypeNode* getType();
    bool isGlobal();
    void visit(ASTVisitorBase* visitor) override = 0;
};

/**********************************************************************************/
/* The Scalar Declaration Class                                                   */
/**********************************************************************************/
class ScalarDeclNode : public DeclNode {
public:
    ScalarDeclNode();
    ScalarDeclNode(PrimitiveTypeNode*& type_, IdentifierNode*& name_);
    PrimitiveTypeNode* getType() override;
    void visit(ASTVisitorBase* visitor) override;
};

/**********************************************************************************/
/* The Array Declaration Class                                                    */
/**********************************************************************************/
class ArrayDeclNode : public DeclNode {
public:
    ArrayDeclNode();
    ArrayDeclNode(ArrayTypeNode* type_, IdentifierNode* name_);
    ArrayTypeNode* getType() override;
    void visit(ASTVisitorBase* visitor) override;
};

/**********************************************************************************/
/* The Stmt Class (abstract)                                                      */
/**********************************************************************************/
class StmtNode : public ASTNode {
protected:
    StmtNode();
    
public:
    void visit(ASTVisitorBase* visitor) override = 0;
};


/**********************************************************************************/
/* The Scope Class                                                                */
/**********************************************************************************/
class ScopeNode : public StmtNode {
private:
    std::vector<DeclNode*> decls;
    SymTable<VariableEntry>* env;
    
public:
    ScopeNode();
    void addDeclaration(DeclNode *decl);
    std::vector<DeclNode*> getDeclarations();
    SymTable<VariableEntry>* getVarTable();
    bool hasVarTable() override;
    void visit(ASTVisitorBase* visitor) override;
};


/**********************************************************************************/
/* The Function Declaration Class                                                 */
/**********************************************************************************/
class FunctionDeclNode : public DeclNode {
private:
    bool isProto;
    ScopeNode* body;
    std::vector<ParameterNode* > params;
    
public:
    FunctionDeclNode();
    void setProto(bool val);
    void setBody(ScopeNode* val);
    void setRetType(PrimitiveTypeNode* type);
    void setParameter(std::vector<ParameterNode* > parameters);
    void addParameter(ParameterNode* param);
    bool getProto();
    ScopeNode* getBody();
    PrimitiveTypeNode* getRetType();
    std::vector<ParameterNode*> getParams();
    unsigned int getNumParameters();
    PrimitiveTypeNode *getType() override;
    void visit(ASTVisitorBase* visitor) override;
};

/**********************************************************************************/
/* The Expression Statement Class                                                 */
/**********************************************************************************/
class ExprStmtNode : public StmtNode {
private:
    ExprNode* expr;
    
public:
    ExprStmtNode();
    explicit ExprStmtNode(ExprNode* exp);
    void setExpr(ExprNode* expr_);
    ExprNode* getExpr();
    void visit(ASTVisitorBase* visitor) override;
};

/**********************************************************************************/
/* The Assignment Statement Class                                                 */
/**********************************************************************************/
class AssignStmtNode : public StmtNode {
private:
    ReferenceExprNode *target;
    ExprNode* val;
    
public:
    AssignStmtNode();
    AssignStmtNode(ReferenceExprNode* target_, ExprNode* val_);
    ReferenceExprNode *getTarget();
    void setTarget(ReferenceExprNode* name);
    ExprNode* getValue();
    void setValue(ExprNode* value);
    void visit(ASTVisitorBase* visitor) override;
};

/**********************************************************************************/
/* The If Statement Class                                                         */
/**********************************************************************************/
class IfStmtNode : public StmtNode {
    ExprNode *condition;
    bool hasElse;
    StmtNode *Then;
    StmtNode *Else;
public:
    IfStmtNode();
    IfStmtNode(ExprNode* cond, StmtNode* then_);
    IfStmtNode(ExprNode* cond, StmtNode* then_, StmtNode* else_);
    ExprNode* getCondition();
    void setCondition(ExprNode* condition_);
    bool getHasElse();
    void setHasElse(bool hasElse_);
    StmtNode *getThen();
    void setThen(StmtNode* then_);
    StmtNode *getElse();
    void setElse(StmtNode* else_);
    void visit(ASTVisitorBase* visitor) override;
};

/**********************************************************************************/
/* The While Statement Class                                                      */
/**********************************************************************************/
class WhileStmtNode : public StmtNode {
    ExprNode *condition;
    StmtNode *body;
public:
    WhileStmtNode();
    WhileStmtNode(ExprNode* cond, StmtNode* body_);
    ExprNode* getCondition();
    void setCondition(ExprNode* cond);
    StmtNode* getBody();
    void setBody(StmtNode* body_);
    void visit(ASTVisitorBase* visitor) override;
};

/**********************************************************************************/
/* The Return Statement Class                                                     */
/**********************************************************************************/
class ReturnStmtNode : public StmtNode {
    ExprNode* ret;
public:
    ReturnStmtNode();
    explicit ReturnStmtNode(ExprNode* exp);
    ExprNode* getReturn();
    void setReturn(ExprNode* value);
    bool returnVoid();
    void visit(ASTVisitorBase* visitor) override;
};

} // namespace smallc

#endif /* ASTNodes_h */
