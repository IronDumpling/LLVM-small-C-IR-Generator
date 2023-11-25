//
//  IRGen.h
//  ECE467 Lab 4
//
//  Created by Tarek Abdelrahman on 2023-10-13.
//  Based on code written by Ao (Dino) Li for ECE467.
//  Copyright © 2023 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE467 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

#ifndef IRGen_h
#define IRGen_h

#include <iostream>
using namespace std;

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Verifier.h"

#include "ASTNodes.h"
#include "ASTVisitorBase.h"

using namespace llvm;

namespace smallc {

class IRGen : public smallc::ASTVisitorBase {
private:
    smallc::ProgramNode* prog;
    std::unique_ptr<llvm::LLVMContext> TheContext;
    std::unique_ptr<llvm::Module> TheModule;
    std::unique_ptr<llvm::IRBuilder<>> Builder;
    const std::string ModuleName;
    std::string currFunctionName;
    
public:
    // Constructor
    explicit IRGen(const std::string moduleName);
    
    // Utility methods
    unique_ptr<llvm::Module> getModule();
    llvm::Type* convertType(TypeNode* type);
    SymTable<VariableEntry>* findTable(IdentifierNode* id);

    llvm::Type * arrayToPrimitiveType(TypeNode * array);
    void createFuncProto(string name, FunctionEntry & func);
    void createVarInst(ReferenceExprNode* ref, bool isValue);

    // The IR Generation visitors
    // These are the methods that perform the IR code generation 
    // The methods override their counterparts in the ASTVisitorBase class
    void visitASTNode(ASTNode *node) override;
    void visitArgumentNode(ArgumentNode* arg) override;
    void visitDeclNode(DeclNode* decl) override;
    void visitArrayDeclNode(ArrayDeclNode* array) override;
    void visitFunctionDeclNode(FunctionDeclNode* func) override;
    void visitScalarDeclNode(ScalarDeclNode* scalar) override;
    void visitExprNode(ExprNode* exp) override;
    void visitBinaryExprNode(BinaryExprNode* bin) override;
    void visitBoolExprNode(BoolExprNode* boolExpr) override;
    void visitCallExprNode(CallExprNode* call) override;
    void visitConstantExprNode(ConstantExprNode* constant) override;
    void visitBoolConstantNode(BoolConstantNode* boolConst) override;
    void visitIntConstantNode(IntConstantNode* intConst) override;
    void visitIntExprNode(IntExprNode* intExpr) override;
    void visitReferenceExprNode(ReferenceExprNode* ref) override;
    void visitUnaryExprNode(UnaryExprNode* unary) override;
    void visitIdentifierNode(IdentifierNode* id) override;
    void visitParameterNode(ParameterNode* param) override;
    void visitProgramNode(ProgramNode* prg) override;
    void visitStmtNode(StmtNode* stmt) override;
    void visitAssignStmtNode(AssignStmtNode* assign) override;
    void visitExprStmtNode(ExprStmtNode* expr) override;
    void visitIfStmtNode(IfStmtNode* ifStmt) override;
    void visitReturnStmtNode(ReturnStmtNode* ret) override;
    void visitScopeNode(ScopeNode* scope) override;
    void visitWhileStmtNode(WhileStmtNode* whileStmt) override;
    void visitTypeNode(TypeNode* type) override;
    void visitPrimitiveTypeNode(PrimitiveTypeNode* type) override;
    void visitArrayTypeNode(ArrayTypeNode* type) override;
};

} // namespace smallc
#endif /* IRGen_h */
