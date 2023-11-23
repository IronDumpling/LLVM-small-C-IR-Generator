//
//  ASTVisitorBase.h
//  ECE467 Lab 3
//
//  Created by Tarek Abdelrahman on 2023-09-13.
//  Based on code written by Ao (Dino) Li for ECE467.
//  Copyright © 2023 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE467 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

#ifndef ASTVISITORBASE_H
#define ASTVISITORBASE_H

namespace smallc {

    // Forward class declaration
    class ASTNode;
    class ArgumentNode;
    class DeclNode;
    class ArrayDeclNode;
    class FunctionDeclNode;
    class ScalarDeclNode;
    class ExprNode;
    class BinaryExprNode;
    class BoolExprNode;
    class CallExprNode;
    class ConstantExprNode;
    class BoolConstantNode;
    class IntConstantNode;
    class IntExprNode;
    class ReferenceExprNode;
    class UnaryExprNode;
    class IdentifierNode;
    class ParameterNode;
    class ProgramNode;
    class StmtNode;
    class AssignStmtNode;
    class ExprStmtNode;
    class IfStmtNode;
    class ReturnStmtNode;
    class ScopeNode;
    class WhileStmtNode;
    class TypeNode;
    class PrimitiveTypeNode;
    class ArrayTypeNode;

    // The AST Visitor Base class
    class ASTVisitorBase {
    public:
        virtual void visitASTNode(ASTNode *node);
        virtual void visitArgumentNode(ArgumentNode *arg);
        virtual void visitDeclNode(DeclNode *decl);
        virtual void visitArrayDeclNode(ArrayDeclNode *array);
        virtual void visitFunctionDeclNode(FunctionDeclNode *func);
        virtual void visitScalarDeclNode(ScalarDeclNode *scalar);
        virtual void visitExprNode(ExprNode *exp);
        virtual void visitBinaryExprNode(BinaryExprNode *bin);
        virtual void visitBoolExprNode(BoolExprNode *boolExpr);
        virtual void visitCallExprNode(CallExprNode *call);
        virtual void visitConstantExprNode(ConstantExprNode *constant);
        virtual void visitBoolConstantNode(BoolConstantNode *boolConst);
        virtual void visitIntConstantNode(IntConstantNode *intConst);
        virtual void visitIntExprNode(IntExprNode *intExpr);
        virtual void visitReferenceExprNode(ReferenceExprNode *ref);
        virtual void visitUnaryExprNode(UnaryExprNode *unary);
        virtual void visitIdentifierNode(IdentifierNode *id);
        virtual void visitParameterNode(ParameterNode *param);
        virtual void visitProgramNode(ProgramNode *prg);
        virtual void visitStmtNode(StmtNode *stmt);
        virtual void visitAssignStmtNode(AssignStmtNode *assign);
        virtual void visitExprStmtNode(ExprStmtNode *expr);
        virtual void visitIfStmtNode(IfStmtNode *ifStmt);
        virtual void visitReturnStmtNode(ReturnStmtNode *ret);
        virtual void visitScopeNode(ScopeNode *scope);
        virtual void visitWhileStmtNode(WhileStmtNode *whileStmt);
        virtual void visitTypeNode(TypeNode *type);
        virtual void visitPrimitiveTypeNode(PrimitiveTypeNode *type);
        virtual void visitArrayTypeNode(ArrayTypeNode *type);
    };
} // namespace smallc
#endif // ASTVISITORBASE_H
