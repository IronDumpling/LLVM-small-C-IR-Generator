//
//  ASTVisitorBase.cpp
//  ECE467 Lab 3
//
//  Created by Tarek Abdelrahman on 2023-09-13.
//  Based on code written by Ao (Dino) Li for ECE467.
//  Copyright © 2023 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE467 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

#include "ASTNodes.h"
#include "ASTVisitorBase.h"
#include <iostream>

namespace smallc{

void 
ASTVisitorBase::visitASTNode (ASTNode* node) {
    for (unsigned int i = 0; i < node->getNumChildren(); ++i){
        auto child = node->getChild(i);
        if (child) child->visit(this);
    }
}

void 
ASTVisitorBase::visitArgumentNode (ArgumentNode* arg) {
    this->visitASTNode (arg);
}

void 
ASTVisitorBase::visitDeclNode (DeclNode* decl) {
    this->visitASTNode (decl);
}

void 
ASTVisitorBase::visitArrayDeclNode (ArrayDeclNode* array) {
    this->visitDeclNode (array);
}

void 
ASTVisitorBase::visitFunctionDeclNode (FunctionDeclNode* func) {
    this->visitDeclNode (func);
}

void 
ASTVisitorBase::visitScalarDeclNode (ScalarDeclNode* scalar) {
    this->visitDeclNode (scalar);
}

void 
ASTVisitorBase::visitExprNode (ExprNode* exp) {
    this->visitASTNode (exp);
}

void 
ASTVisitorBase::visitBinaryExprNode (BinaryExprNode* bin) {
    this->visitExprNode (bin);
}

void 
ASTVisitorBase::visitBoolExprNode (BoolExprNode* boolExpr) {
    this->visitExprNode (boolExpr);
}

void 
ASTVisitorBase::visitCallExprNode (CallExprNode* call) {
    this->visitExprNode (call);
}

void 
ASTVisitorBase::visitConstantExprNode (ConstantExprNode* constant) {
    this->visitExprNode (constant);
}

void 
ASTVisitorBase::visitBoolConstantNode (BoolConstantNode* boolConst) {
    this->visitConstantExprNode (boolConst);
}

void 
ASTVisitorBase::visitIntConstantNode (IntConstantNode* intConst) {
    this->visitConstantExprNode (intConst);
}

void 
ASTVisitorBase::visitIntExprNode (IntExprNode* intExpr) {
    this->visitExprNode (intExpr);
}

void 
ASTVisitorBase::visitReferenceExprNode (ReferenceExprNode* ref) {
    this->visitExprNode (ref);
}

void 
ASTVisitorBase::visitUnaryExprNode (UnaryExprNode* unary) {
    this->visitExprNode (unary);
}

void 
ASTVisitorBase::visitIdentifierNode (IdentifierNode* id) {
    this->visitASTNode (id);
}

void 
ASTVisitorBase::visitParameterNode (ParameterNode* param) {
    this->visitASTNode (param);
}

void 
ASTVisitorBase::visitProgramNode (ProgramNode* prg) {
    this->visitASTNode (prg);
}

void 
ASTVisitorBase::visitStmtNode (StmtNode* stmt) {
    this->visitASTNode (stmt);
}

void 
ASTVisitorBase::visitAssignStmtNode (AssignStmtNode* assign) {
    this->visitStmtNode (assign);
}

void 
ASTVisitorBase::visitExprStmtNode (ExprStmtNode* expr) {
    this->visitStmtNode (expr);
}

void 
ASTVisitorBase::visitIfStmtNode (IfStmtNode* ifStmt) {
    this->visitStmtNode (ifStmt);
}

void 
ASTVisitorBase::visitReturnStmtNode (ReturnStmtNode* ret) {
    this->visitStmtNode (ret);
}

void 
ASTVisitorBase::visitScopeNode (ScopeNode* scope) {
    this->visitStmtNode (scope);
}

void 
ASTVisitorBase::visitWhileStmtNode (WhileStmtNode* whileStmt) {
    this->visitStmtNode (whileStmt);
}

void 
ASTVisitorBase::visitTypeNode (TypeNode* type) {
    this->visitASTNode (type);
}

void 
ASTVisitorBase::visitPrimitiveTypeNode (PrimitiveTypeNode* type) {
    this->visitTypeNode (type);
}

void 
ASTVisitorBase::visitArrayTypeNode (ArrayTypeNode* type) {
    this->visitTypeNode (type);
}
} // namespace smallc
