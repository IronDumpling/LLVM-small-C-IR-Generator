
#include "ASTNodes.h"
#include <iostream>
#include <string>


// Generated from smallC.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "smallCParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by smallCParser.
 */
class  smallCVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by smallCParser.
   */
    virtual antlrcpp::Any visitProgram(smallCParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitPreamble(smallCParser::PreambleContext *context) = 0;

    virtual antlrcpp::Any visitDecls(smallCParser::DeclsContext *context) = 0;

    virtual antlrcpp::Any visitScalarDeclList(smallCParser::ScalarDeclListContext *context) = 0;

    virtual antlrcpp::Any visitScalarDecl(smallCParser::ScalarDeclContext *context) = 0;

    virtual antlrcpp::Any visitArrDeclList(smallCParser::ArrDeclListContext *context) = 0;

    virtual antlrcpp::Any visitArrDecl(smallCParser::ArrDeclContext *context) = 0;

    virtual antlrcpp::Any visitFcnProto(smallCParser::FcnProtoContext *context) = 0;

    virtual antlrcpp::Any visitFcnDecl(smallCParser::FcnDeclContext *context) = 0;

    virtual antlrcpp::Any visitVarType(smallCParser::VarTypeContext *context) = 0;

    virtual antlrcpp::Any visitRetType(smallCParser::RetTypeContext *context) = 0;

    virtual antlrcpp::Any visitConstant(smallCParser::ConstantContext *context) = 0;

    virtual antlrcpp::Any visitBoolConst(smallCParser::BoolConstContext *context) = 0;

    virtual antlrcpp::Any visitScope(smallCParser::ScopeContext *context) = 0;

    virtual antlrcpp::Any visitStmt(smallCParser::StmtContext *context) = 0;

    virtual antlrcpp::Any visitAssignStmt(smallCParser::AssignStmtContext *context) = 0;

    virtual antlrcpp::Any visitIfStmt(smallCParser::IfStmtContext *context) = 0;

    virtual antlrcpp::Any visitWhileStmt(smallCParser::WhileStmtContext *context) = 0;

    virtual antlrcpp::Any visitRetStmt(smallCParser::RetStmtContext *context) = 0;

    virtual antlrcpp::Any visitExpr(smallCParser::ExprContext *context) = 0;

    virtual antlrcpp::Any visitIntExpr(smallCParser::IntExprContext *context) = 0;

    virtual antlrcpp::Any visitVar(smallCParser::VarContext *context) = 0;

    virtual antlrcpp::Any visitParams(smallCParser::ParamsContext *context) = 0;

    virtual antlrcpp::Any visitParamEntry(smallCParser::ParamEntryContext *context) = 0;

    virtual antlrcpp::Any visitParamList(smallCParser::ParamListContext *context) = 0;

    virtual antlrcpp::Any visitArgs(smallCParser::ArgsContext *context) = 0;

    virtual antlrcpp::Any visitArgEntry(smallCParser::ArgEntryContext *context) = 0;

    virtual antlrcpp::Any visitArgList(smallCParser::ArgListContext *context) = 0;

    virtual antlrcpp::Any visitVarName(smallCParser::VarNameContext *context) = 0;

    virtual antlrcpp::Any visitArrName(smallCParser::ArrNameContext *context) = 0;

    virtual antlrcpp::Any visitFcnName(smallCParser::FcnNameContext *context) = 0;

    virtual antlrcpp::Any visitIntConst(smallCParser::IntConstContext *context) = 0;


};

