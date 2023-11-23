
#include "ASTNodes.h"
#include <iostream>
#include <string>


// Generated from smallC.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "smallCVisitor.h"


/**
 * This class provides an empty implementation of smallCVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  smallCBaseVisitor : public smallCVisitor {
public:

  virtual antlrcpp::Any visitProgram(smallCParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPreamble(smallCParser::PreambleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecls(smallCParser::DeclsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScalarDeclList(smallCParser::ScalarDeclListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScalarDecl(smallCParser::ScalarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrDeclList(smallCParser::ArrDeclListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrDecl(smallCParser::ArrDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFcnProto(smallCParser::FcnProtoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFcnDecl(smallCParser::FcnDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarType(smallCParser::VarTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRetType(smallCParser::RetTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstant(smallCParser::ConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBoolConst(smallCParser::BoolConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScope(smallCParser::ScopeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStmt(smallCParser::StmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignStmt(smallCParser::AssignStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfStmt(smallCParser::IfStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileStmt(smallCParser::WhileStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRetStmt(smallCParser::RetStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr(smallCParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntExpr(smallCParser::IntExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVar(smallCParser::VarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParams(smallCParser::ParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParamEntry(smallCParser::ParamEntryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParamList(smallCParser::ParamListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArgs(smallCParser::ArgsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArgEntry(smallCParser::ArgEntryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArgList(smallCParser::ArgListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarName(smallCParser::VarNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrName(smallCParser::ArrNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFcnName(smallCParser::FcnNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntConst(smallCParser::IntConstContext *ctx) override {
    return visitChildren(ctx);
  }


};

