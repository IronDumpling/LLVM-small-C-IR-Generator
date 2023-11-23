//
//  SemanticAnalyzer.h
//  ECE467 Lab 3
//
//  Created by Tarek Abdelrahman on 2023-09-13.
//  Based on code written by Ao (Dino) Li for ECE467.
//  Copyright © 2023 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE467 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

#ifndef SemanticAnalyzer_h
#define SemanticAnalyzer_h

#include <iostream>
using namespace std;

#include "ASTNodes.h"
#include "ASTVisitorBase.h"

namespace smallc {
class SemaError {
public:
    // List of error types
    enum ErrorEnum{

        IdentReDefined=0,
        IdentUnDefined,
        NoMatchingDef,
        MisMatchedReturn,
        InconsistentDef,
        InvalidCond,
        TypeMisMatch,
        InvalidArraySize,
        
        InvalidAccess,
    };
    
    // The error code
    ErrorEnum code;
    
    // The location of the error (line and column in line)
    std::pair<unsigned int, unsigned int> location;
    
    // Message corresponding to error code
    std::string msg;
    
    // Constructors
    SemaError(ErrorEnum code_, std::pair<unsigned int, unsigned int> location_);
    SemaError(ErrorEnum code_, std::pair<unsigned int, unsigned int> location_, std::string msg_);
};


class SemanticAnalyzer : public smallc::ASTVisitorBase {
private:
    smallc::ProgramNode* prog;
    std::vector<SemaError> errors;
    
public:
    // Constructor
    SemanticAnalyzer ();
    
    // Print all the error messages at once
    void printErrorMsgs ();
    
    // Add an error to the list of errors
    void addError(const SemaError& err);
    
    // The semantic analysis visitors
    // These are the methods that perform semantic analysis
    // The methods override their counterparts in the
    // ASTVisitorBase class
    void visitASTNode(ASTNode *node) override;
    void visitArgumentNode(ArgumentNode *arg) override;
    void visitDeclNode(DeclNode *decl) override;
    void visitArrayDeclNode(ArrayDeclNode *array) override;
    void visitFunctionDeclNode(FunctionDeclNode *func) override;
    void visitScalarDeclNode(ScalarDeclNode *scalar) override;
    void visitExprNode(ExprNode *exp) override;
    void visitBinaryExprNode(BinaryExprNode *bin) override;
    void visitBoolExprNode(BoolExprNode *boolExpr) override;
    void visitCallExprNode(CallExprNode *call) override;
    void visitConstantExprNode(ConstantExprNode *constant) override;
    void visitBoolConstantNode(BoolConstantNode *boolConst) override;
    void visitIntConstantNode(IntConstantNode *intConst) override;
    void visitIntExprNode(IntExprNode *intExpr) override;
    void visitReferenceExprNode(ReferenceExprNode *ref) override;
    void visitUnaryExprNode(UnaryExprNode *unary) override;
    void visitIdentifierNode(IdentifierNode *id) override;
    void visitParameterNode(ParameterNode *param) override;
    void visitProgramNode(ProgramNode *prg) override;
    void visitStmtNode(StmtNode *stmt) override;
    void visitAssignStmtNode(AssignStmtNode *assign) override;
    void visitExprStmtNode(ExprStmtNode *expr) override;
    void visitIfStmtNode(IfStmtNode *ifStmt) override;
    void visitReturnStmtNode(ReturnStmtNode *ret) override;
    void visitScopeNode(ScopeNode *scope) override;
    void visitWhileStmtNode(WhileStmtNode *whileStmt) override;
    void visitTypeNode(TypeNode *type) override;
    void visitPrimitiveTypeNode(PrimitiveTypeNode *type) override;
    void visitArrayTypeNode(ArrayTypeNode *type) override;
    
    // Checks if there are errors
    bool success();
};

} // namespace smallc
#endif /* SemanticAnalyzer_h */
