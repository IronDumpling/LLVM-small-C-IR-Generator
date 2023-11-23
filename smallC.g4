//
//  smallC.g4
//  ECE467 Lab 4
//
//  Created by Tarek Abdelrahman on 2023-09-13.
//  Based on code written by Ao (Dino) Li for ECE467.
//  Copyright © 2023 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE467 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

grammar smallC;

@header {
#include "ASTNodes.h"
#include <iostream>
#include <string>
}

program returns [smallc::ProgramNode *prg]
@init {
    $prg = new smallc::ProgramNode();
    $prg->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}:  (preamble{$prg->setIo(true);} | ) 
    (decls{
        for(unsigned int i = 0; i < $decls.declarations.size();i++) 
            $prg->addChild($decls.declarations[i]); 
    })* EOF ;

preamble:  '#include' '"scio.h"';

decls returns[std::vector<smallc::DeclNode*> declarations]:
    scalarDeclList{
        for(unsigned int i = 0; i < $scalarDeclList.scalars.size();i++)
            $declarations.push_back($scalarDeclList.scalars[i]);
    }
    | arrDeclList{
        for(unsigned int i = 0; i < $arrDeclList.arrays.size();i++)
            $declarations.push_back($arrDeclList.arrays[i]);
    }
    | fcnProto{
        $declarations.push_back($fcnProto.decl);
    }
    | fcnDecl{
        $declarations.push_back($fcnDecl.decl);
    }
;

scalarDeclList returns [std::vector<smallc::ScalarDeclNode*> scalars]:
    scalarDecl{
        $scalars.push_back($scalarDecl.decl);
    }
    | scalarDecl{
        $scalars.push_back($scalarDecl.decl);
    } scalarDeclList{
        for(unsigned int i = 0; i < $scalarDeclList.scalars.size(); i++)
            $scalars.push_back($scalarDeclList.scalars[i]);
    }
;

scalarDecl returns [smallc::ScalarDeclNode* decl]:
    varType varName ';'{
        $decl = new smallc::ScalarDeclNode($varType.type, $varName.name);
        $decl->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
;

arrDeclList returns [std::vector<smallc::ArrayDeclNode*> arrays]:
    arrDecl {
        $arrays.push_back($arrDecl.decl);
    }
    | arrDecl{
        $arrays.push_back($arrDecl.decl);
    } arrDeclList{
        for(unsigned int i = 0; i < $arrDeclList.arrays.size(); i++)
            $arrays.push_back($arrDeclList.arrays[i]);
    }
;

arrDecl returns [smallc::ArrayDeclNode* decl] locals [smallc::ArrayTypeNode* arrtype]:
    varType arrName '[' intConst ']' ';'{
        $arrtype = new smallc::ArrayTypeNode($varType.type, $intConst.val->getVal());
        $decl = new smallc::ArrayDeclNode($arrtype, $arrName.name);
        $decl->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
;

fcnProto returns [smallc::FunctionDeclNode* decl]:
    retType fcnName '(' params ')' ';'{
        $decl = new smallc::FunctionDeclNode();
        $decl->setRetType($retType.type);
        $decl->setName($fcnName.name);
        $decl->setParameter($params.parameters);
        $decl->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
;

fcnDecl returns[smallc::FunctionDeclNode* decl]:
    retType fcnName '(' params ')' scope{
        $decl = new smallc::FunctionDeclNode();
        $decl->setRetType($retType.type);
        $decl->setName($fcnName.name);
        $decl->setParameter($params.parameters);
        $decl->setBody($scope.scope_);
        $decl->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
;

varType returns[smallc::PrimitiveTypeNode* type]:
    'bool' {
        $type = new smallc::PrimitiveTypeNode();
        $type->setType(smallc::TypeNode::Bool);
        $type->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
    | 'int'{
        $type = new smallc::PrimitiveTypeNode();
        $type->setType(smallc::TypeNode::Int);
        $type->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
;

retType returns[smallc::PrimitiveTypeNode* type]
@init{
    $type = new smallc::PrimitiveTypeNode();
}:
    'void'{
        $type->setType(smallc::TypeNode::Void);
        $type->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
    | varType{
        $type = $varType.type;
    }
;

constant returns [smallc::ConstantExprNode* val]:
    boolConst{
        $val = $boolConst.val;
    }
    | intConst{
        $val = $intConst.val;
    };

boolConst returns[smallc::BoolConstantNode* val]:
    BOOL{
        $val = new smallc::BoolConstantNode($BOOL.text);
        $val->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
;

scope returns[smallc::ScopeNode* scope_]
@init{
    $scope_ = new smallc::ScopeNode();
    $scope_->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}:
    '{' (scalarDecl{$scope_->addDeclaration($scalarDecl.decl);}|arrDecl{$scope_->addDeclaration($arrDecl.decl);})* (stmt{$scope_->addChild($stmt.statement);})* '}'

;

stmt returns[smallc::StmtNode *statement]:
    expr ';'{
        $statement = new smallc::ExprStmtNode($expr.exp);
        $statement->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
    | assignStmt{
        $statement = $assignStmt.statement;
    }
    | ifStmt{
        $statement = $ifStmt.statement;
    }
    | whileStmt{
        $statement = $whileStmt.statement;
    }
    | retStmt{
        $statement = $retStmt.statement;
    }
    | scope{
        $statement = $scope.scope_;
    }
;

assignStmt returns[smallc::AssignStmtNode* statement]:
    var '=' expr ';'{
        $statement = new smallc::AssignStmtNode($var.ref, $expr.exp);
        $statement->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
;

ifStmt returns[smallc::IfStmtNode *statement]:
    'if' '(' expr ')' stmt{
        $statement = new smallc::IfStmtNode($expr.exp, $stmt.statement);
        $statement->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
    | 'if' '(' expr ')' then=stmt 'else' e=stmt{
        $statement = new smallc::IfStmtNode($expr.exp, $then.statement, $e.statement);
        $statement->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
;

whileStmt returns[smallc::WhileStmtNode *statement]:
    'while' '(' expr ')' stmt{
        $statement = new smallc::WhileStmtNode($expr.exp, $stmt.statement);
        $statement->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
;

retStmt returns[smallc::ReturnStmtNode *statement]:
    'return' expr ';'{
        $statement = new smallc::ReturnStmtNode($expr.exp);
        $statement->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
    |'return' ';'{
        $statement = new smallc::ReturnStmtNode();
        $statement->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
;

expr returns[smallc::ExprNode* exp] locals[smallc::BoolExprNode* boolvar, smallc::UnaryExprNode* unary, smallc::BinaryExprNode* bin, smallc::CallExprNode* call]:
    intExpr{
        $exp = $intExpr.exp;
    }
    | '(' expr ')'{
        $exp = $expr.exp;
    }
    | fcnName '(' args ')'{
        $call = new smallc::CallExprNode($fcnName.name, $args.arglist);
        $call->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        $exp = $call;
    }
    | op=('!' | '-') expr{
        $unary = new smallc::UnaryExprNode($expr.exp);
        $unary->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        $unary->setOpcode($op.text);
        $exp = $unary;
    }
    | l=expr op=('<' | '<=' | '>' | '>=') r=expr{
        $bin = new smallc::BinaryExprNode($l.exp, $r.exp);
        $bin->setOpcode($op.text);
        $bin->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        $boolvar = new smallc::BoolExprNode($bin);
        $exp = $boolvar;
    } // bool expr
    | l=expr op=('==' | '!=') r=expr{
        $bin = new smallc::BinaryExprNode($l.exp, $r.exp);
        $bin->setOpcode($op.text);
        $bin->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        $boolvar = new smallc::BoolExprNode($bin);
        $exp = $boolvar;
    } // bool expr
    | l=expr op='||' r=expr{
        $bin = new smallc::BinaryExprNode($l.exp, $r.exp);
        $bin->setOpcode($op.text);
        $bin->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        $boolvar = new smallc::BoolExprNode($bin);
        $exp = $boolvar;
    } // bool expr
    | l=expr op='&&' r=expr{
        $bin = new smallc::BinaryExprNode($l.exp, $r.exp);
        $bin->setOpcode($op.text);
        $bin->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        $boolvar = new smallc::BoolExprNode($bin);
        $exp = $boolvar;
    } // bool expr
;

intExpr returns[smallc::IntExprNode *exp] locals[smallc::BinaryExprNode *bin]:
    var{
        $exp = new smallc::IntExprNode($var.ref);
    }
    | constant{
        $exp = new smallc::IntExprNode($constant.val);
    }
    | l=intExpr op=('*' | '/' ) r=intExpr{
        $bin = new smallc::BinaryExprNode($l.exp, $r.exp);
        $bin->setOpcode($op.text);
        $bin->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        $exp = new smallc::IntExprNode($bin);
    }
    | l=intExpr op=('+' | '-' ) r=intExpr{
        $bin = new smallc::BinaryExprNode($l.exp, $r.exp);
        $bin->setOpcode($op.text);
        $bin->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        $exp = new smallc::IntExprNode($bin);
    }
    | '(' self=intExpr ')'{
        $exp = $self.exp;
    }
;

var returns  [smallc::ReferenceExprNode* ref]:
    varName{
        $ref = new smallc::ReferenceExprNode($varName.name);
        $ref->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
    | arrName '[' intExpr ']'{
        $ref = new smallc::ReferenceExprNode($arrName.name, $intExpr.exp);
        $ref->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
;

params returns[std::vector<smallc::ParameterNode*> parameters]:
    paramList{
        $parameters = $paramList.parameters;
    }
    | ;

paramEntry returns [smallc::ParameterNode* param] locals [smallc::ArrayTypeNode* arrType]:
    varType varName {
        $param = new smallc::ParameterNode($varType.type, $varName.name);
        $param->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
    | varType arrName '[]' {
        $arrType = new smallc::ArrayTypeNode($varType.type);
        $param = new smallc::ParameterNode($arrType, $arrName.name);
        $param->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
;

paramList returns [std::vector<smallc::ParameterNode*> parameters]:
    paramEntry{
        $parameters.push_back($paramEntry.param);
    }
    | paramEntry {
        $parameters.push_back($paramEntry.param);
    } ',' paramList {for(unsigned int i = 0; i < $paramList.parameters.size(); i++) $parameters.push_back($paramList.parameters[i]);};

args returns [std::vector<smallc::ArgumentNode*> arglist]:
    argList {$arglist = $argList.arglist;}
    |
;

argEntry returns[smallc::ArgumentNode* arg]:
    expr{
        $arg = new smallc::ArgumentNode($expr.exp);
        $arg->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
;

argList returns [std::vector<smallc::ArgumentNode*> arglist]:
    argEntry{$arglist.push_back($argEntry.arg);}
    | argEntry{$arglist.push_back($argEntry.arg);} ',' argList{for(unsigned int i = 0; i < $argList.arglist.size(); i++) $arglist.push_back($argList.arglist[i]);};

varName returns [smallc::IdentifierNode* name]: ID {
    $name = new smallc::IdentifierNode($ID.text);
    $name->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
};

arrName returns [smallc::IdentifierNode* name]: ID {
    $name = new smallc::IdentifierNode($ID.text);
    $name->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
};

fcnName returns [smallc::IdentifierNode* name]: ID {
    $name = new smallc::IdentifierNode($ID.text);
    $name->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
};

intConst returns [smallc::IntConstantNode* val] locals [string neg]: INT {
    $neg = $INT.text;
    $val = new smallc::IntConstantNode($INT.text);
    //$val = new smallc::IntConstantNode($INT.text);
    $val->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
| '-' INT {
    $neg = "-" + $INT.text;
    $val = new smallc::IntConstantNode($neg);
    //$val = new smallc::IntConstantNode($INT.text);
    $val->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
};

BOOL: 'true' | 'false';
ID: [a-zA-Z][a-zA-Z0-9_]* ;
INT:    [0] | ([1-9][0-9]*);
WS:     [ \t\r\n]+ -> skip;
COMMENT: '//' (~[\r\n])* -> skip;
