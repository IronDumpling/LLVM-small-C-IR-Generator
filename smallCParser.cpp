
#include "ASTNodes.h"
#include <iostream>
#include <string>


// Generated from smallC.g4 by ANTLR 4.7.2


#include "smallCVisitor.h"

#include "smallCParser.h"


using namespace antlrcpp;
using namespace antlr4;

smallCParser::smallCParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

smallCParser::~smallCParser() {
  delete _interpreter;
}

std::string smallCParser::getGrammarFileName() const {
  return "smallC.g4";
}

const std::vector<std::string>& smallCParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& smallCParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

smallCParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* smallCParser::ProgramContext::EOF() {
  return getToken(smallCParser::EOF, 0);
}

smallCParser::PreambleContext* smallCParser::ProgramContext::preamble() {
  return getRuleContext<smallCParser::PreambleContext>(0);
}

std::vector<smallCParser::DeclsContext *> smallCParser::ProgramContext::decls() {
  return getRuleContexts<smallCParser::DeclsContext>();
}

smallCParser::DeclsContext* smallCParser::ProgramContext::decls(size_t i) {
  return getRuleContext<smallCParser::DeclsContext>(i);
}


size_t smallCParser::ProgramContext::getRuleIndex() const {
  return smallCParser::RuleProgram;
}


antlrcpp::Any smallCParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ProgramContext* smallCParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, smallCParser::RuleProgram);

      dynamic_cast<ProgramContext *>(_localctx)->prg =  new smallc::ProgramNode();
      _localctx->prg->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(68);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case smallCParser::T__0: {
        setState(64);
        preamble();
        _localctx->prg->setIo(true);
        break;
      }

      case smallCParser::EOF:
      case smallCParser::T__7:
      case smallCParser::T__8:
      case smallCParser::T__9: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(75);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << smallCParser::T__7)
      | (1ULL << smallCParser::T__8)
      | (1ULL << smallCParser::T__9))) != 0)) {
      setState(70);
      dynamic_cast<ProgramContext *>(_localctx)->declsContext = decls();

              for(unsigned int i = 0; i < dynamic_cast<ProgramContext *>(_localctx)->declsContext->declarations.size();i++) 
                  _localctx->prg->addChild(dynamic_cast<ProgramContext *>(_localctx)->declsContext->declarations[i]); 
          
      setState(77);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(78);
    match(smallCParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PreambleContext ------------------------------------------------------------------

smallCParser::PreambleContext::PreambleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t smallCParser::PreambleContext::getRuleIndex() const {
  return smallCParser::RulePreamble;
}


antlrcpp::Any smallCParser::PreambleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitPreamble(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::PreambleContext* smallCParser::preamble() {
  PreambleContext *_localctx = _tracker.createInstance<PreambleContext>(_ctx, getState());
  enterRule(_localctx, 2, smallCParser::RulePreamble);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(80);
    match(smallCParser::T__0);
    setState(81);
    match(smallCParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclsContext ------------------------------------------------------------------

smallCParser::DeclsContext::DeclsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ScalarDeclListContext* smallCParser::DeclsContext::scalarDeclList() {
  return getRuleContext<smallCParser::ScalarDeclListContext>(0);
}

smallCParser::ArrDeclListContext* smallCParser::DeclsContext::arrDeclList() {
  return getRuleContext<smallCParser::ArrDeclListContext>(0);
}

smallCParser::FcnProtoContext* smallCParser::DeclsContext::fcnProto() {
  return getRuleContext<smallCParser::FcnProtoContext>(0);
}

smallCParser::FcnDeclContext* smallCParser::DeclsContext::fcnDecl() {
  return getRuleContext<smallCParser::FcnDeclContext>(0);
}


size_t smallCParser::DeclsContext::getRuleIndex() const {
  return smallCParser::RuleDecls;
}


antlrcpp::Any smallCParser::DeclsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitDecls(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::DeclsContext* smallCParser::decls() {
  DeclsContext *_localctx = _tracker.createInstance<DeclsContext>(_ctx, getState());
  enterRule(_localctx, 4, smallCParser::RuleDecls);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(95);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(83);
      dynamic_cast<DeclsContext *>(_localctx)->scalarDeclListContext = scalarDeclList();

              for(unsigned int i = 0; i < dynamic_cast<DeclsContext *>(_localctx)->scalarDeclListContext->scalars.size();i++)
                  _localctx->declarations.push_back(dynamic_cast<DeclsContext *>(_localctx)->scalarDeclListContext->scalars[i]);
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(86);
      dynamic_cast<DeclsContext *>(_localctx)->arrDeclListContext = arrDeclList();

              for(unsigned int i = 0; i < dynamic_cast<DeclsContext *>(_localctx)->arrDeclListContext->arrays.size();i++)
                  _localctx->declarations.push_back(dynamic_cast<DeclsContext *>(_localctx)->arrDeclListContext->arrays[i]);
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(89);
      dynamic_cast<DeclsContext *>(_localctx)->fcnProtoContext = fcnProto();

              _localctx->declarations.push_back(dynamic_cast<DeclsContext *>(_localctx)->fcnProtoContext->decl);
          
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(92);
      dynamic_cast<DeclsContext *>(_localctx)->fcnDeclContext = fcnDecl();

              _localctx->declarations.push_back(dynamic_cast<DeclsContext *>(_localctx)->fcnDeclContext->decl);
          
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScalarDeclListContext ------------------------------------------------------------------

smallCParser::ScalarDeclListContext::ScalarDeclListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ScalarDeclContext* smallCParser::ScalarDeclListContext::scalarDecl() {
  return getRuleContext<smallCParser::ScalarDeclContext>(0);
}

smallCParser::ScalarDeclListContext* smallCParser::ScalarDeclListContext::scalarDeclList() {
  return getRuleContext<smallCParser::ScalarDeclListContext>(0);
}


size_t smallCParser::ScalarDeclListContext::getRuleIndex() const {
  return smallCParser::RuleScalarDeclList;
}


antlrcpp::Any smallCParser::ScalarDeclListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitScalarDeclList(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ScalarDeclListContext* smallCParser::scalarDeclList() {
  ScalarDeclListContext *_localctx = _tracker.createInstance<ScalarDeclListContext>(_ctx, getState());
  enterRule(_localctx, 6, smallCParser::RuleScalarDeclList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(105);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(97);
      dynamic_cast<ScalarDeclListContext *>(_localctx)->scalarDeclContext = scalarDecl();

              _localctx->scalars.push_back(dynamic_cast<ScalarDeclListContext *>(_localctx)->scalarDeclContext->decl);
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(100);
      dynamic_cast<ScalarDeclListContext *>(_localctx)->scalarDeclContext = scalarDecl();

              _localctx->scalars.push_back(dynamic_cast<ScalarDeclListContext *>(_localctx)->scalarDeclContext->decl);
          
      setState(102);
      dynamic_cast<ScalarDeclListContext *>(_localctx)->scalarDeclListContext = scalarDeclList();

              for(unsigned int i = 0; i < dynamic_cast<ScalarDeclListContext *>(_localctx)->scalarDeclListContext->scalars.size(); i++)
                  _localctx->scalars.push_back(dynamic_cast<ScalarDeclListContext *>(_localctx)->scalarDeclListContext->scalars[i]);
          
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScalarDeclContext ------------------------------------------------------------------

smallCParser::ScalarDeclContext::ScalarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::VarTypeContext* smallCParser::ScalarDeclContext::varType() {
  return getRuleContext<smallCParser::VarTypeContext>(0);
}

smallCParser::VarNameContext* smallCParser::ScalarDeclContext::varName() {
  return getRuleContext<smallCParser::VarNameContext>(0);
}


size_t smallCParser::ScalarDeclContext::getRuleIndex() const {
  return smallCParser::RuleScalarDecl;
}


antlrcpp::Any smallCParser::ScalarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitScalarDecl(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ScalarDeclContext* smallCParser::scalarDecl() {
  ScalarDeclContext *_localctx = _tracker.createInstance<ScalarDeclContext>(_ctx, getState());
  enterRule(_localctx, 8, smallCParser::RuleScalarDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(107);
    dynamic_cast<ScalarDeclContext *>(_localctx)->varTypeContext = varType();
    setState(108);
    dynamic_cast<ScalarDeclContext *>(_localctx)->varNameContext = varName();
    setState(109);
    match(smallCParser::T__2);

            dynamic_cast<ScalarDeclContext *>(_localctx)->decl =  new smallc::ScalarDeclNode(dynamic_cast<ScalarDeclContext *>(_localctx)->varTypeContext->type, dynamic_cast<ScalarDeclContext *>(_localctx)->varNameContext->name);
            _localctx->decl->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrDeclListContext ------------------------------------------------------------------

smallCParser::ArrDeclListContext::ArrDeclListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ArrDeclContext* smallCParser::ArrDeclListContext::arrDecl() {
  return getRuleContext<smallCParser::ArrDeclContext>(0);
}

smallCParser::ArrDeclListContext* smallCParser::ArrDeclListContext::arrDeclList() {
  return getRuleContext<smallCParser::ArrDeclListContext>(0);
}


size_t smallCParser::ArrDeclListContext::getRuleIndex() const {
  return smallCParser::RuleArrDeclList;
}


antlrcpp::Any smallCParser::ArrDeclListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitArrDeclList(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ArrDeclListContext* smallCParser::arrDeclList() {
  ArrDeclListContext *_localctx = _tracker.createInstance<ArrDeclListContext>(_ctx, getState());
  enterRule(_localctx, 10, smallCParser::RuleArrDeclList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(120);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(112);
      dynamic_cast<ArrDeclListContext *>(_localctx)->arrDeclContext = arrDecl();

              _localctx->arrays.push_back(dynamic_cast<ArrDeclListContext *>(_localctx)->arrDeclContext->decl);
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(115);
      dynamic_cast<ArrDeclListContext *>(_localctx)->arrDeclContext = arrDecl();

              _localctx->arrays.push_back(dynamic_cast<ArrDeclListContext *>(_localctx)->arrDeclContext->decl);
          
      setState(117);
      dynamic_cast<ArrDeclListContext *>(_localctx)->arrDeclListContext = arrDeclList();

              for(unsigned int i = 0; i < dynamic_cast<ArrDeclListContext *>(_localctx)->arrDeclListContext->arrays.size(); i++)
                  _localctx->arrays.push_back(dynamic_cast<ArrDeclListContext *>(_localctx)->arrDeclListContext->arrays[i]);
          
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrDeclContext ------------------------------------------------------------------

smallCParser::ArrDeclContext::ArrDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::VarTypeContext* smallCParser::ArrDeclContext::varType() {
  return getRuleContext<smallCParser::VarTypeContext>(0);
}

smallCParser::ArrNameContext* smallCParser::ArrDeclContext::arrName() {
  return getRuleContext<smallCParser::ArrNameContext>(0);
}

smallCParser::IntConstContext* smallCParser::ArrDeclContext::intConst() {
  return getRuleContext<smallCParser::IntConstContext>(0);
}


size_t smallCParser::ArrDeclContext::getRuleIndex() const {
  return smallCParser::RuleArrDecl;
}


antlrcpp::Any smallCParser::ArrDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitArrDecl(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ArrDeclContext* smallCParser::arrDecl() {
  ArrDeclContext *_localctx = _tracker.createInstance<ArrDeclContext>(_ctx, getState());
  enterRule(_localctx, 12, smallCParser::RuleArrDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(122);
    dynamic_cast<ArrDeclContext *>(_localctx)->varTypeContext = varType();
    setState(123);
    dynamic_cast<ArrDeclContext *>(_localctx)->arrNameContext = arrName();
    setState(124);
    match(smallCParser::T__3);
    setState(125);
    dynamic_cast<ArrDeclContext *>(_localctx)->intConstContext = intConst();
    setState(126);
    match(smallCParser::T__4);
    setState(127);
    match(smallCParser::T__2);

            dynamic_cast<ArrDeclContext *>(_localctx)->arrtype =  new smallc::ArrayTypeNode(dynamic_cast<ArrDeclContext *>(_localctx)->varTypeContext->type, dynamic_cast<ArrDeclContext *>(_localctx)->intConstContext->val->getVal());
            dynamic_cast<ArrDeclContext *>(_localctx)->decl =  new smallc::ArrayDeclNode(_localctx->arrtype, dynamic_cast<ArrDeclContext *>(_localctx)->arrNameContext->name);
            _localctx->decl->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FcnProtoContext ------------------------------------------------------------------

smallCParser::FcnProtoContext::FcnProtoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::RetTypeContext* smallCParser::FcnProtoContext::retType() {
  return getRuleContext<smallCParser::RetTypeContext>(0);
}

smallCParser::FcnNameContext* smallCParser::FcnProtoContext::fcnName() {
  return getRuleContext<smallCParser::FcnNameContext>(0);
}

smallCParser::ParamsContext* smallCParser::FcnProtoContext::params() {
  return getRuleContext<smallCParser::ParamsContext>(0);
}


size_t smallCParser::FcnProtoContext::getRuleIndex() const {
  return smallCParser::RuleFcnProto;
}


antlrcpp::Any smallCParser::FcnProtoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitFcnProto(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::FcnProtoContext* smallCParser::fcnProto() {
  FcnProtoContext *_localctx = _tracker.createInstance<FcnProtoContext>(_ctx, getState());
  enterRule(_localctx, 14, smallCParser::RuleFcnProto);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(130);
    dynamic_cast<FcnProtoContext *>(_localctx)->retTypeContext = retType();
    setState(131);
    dynamic_cast<FcnProtoContext *>(_localctx)->fcnNameContext = fcnName();
    setState(132);
    match(smallCParser::T__5);
    setState(133);
    dynamic_cast<FcnProtoContext *>(_localctx)->paramsContext = params();
    setState(134);
    match(smallCParser::T__6);
    setState(135);
    match(smallCParser::T__2);

            dynamic_cast<FcnProtoContext *>(_localctx)->decl =  new smallc::FunctionDeclNode();
            _localctx->decl->setRetType(dynamic_cast<FcnProtoContext *>(_localctx)->retTypeContext->type);
            _localctx->decl->setName(dynamic_cast<FcnProtoContext *>(_localctx)->fcnNameContext->name);
            _localctx->decl->setParameter(dynamic_cast<FcnProtoContext *>(_localctx)->paramsContext->parameters);
            _localctx->decl->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FcnDeclContext ------------------------------------------------------------------

smallCParser::FcnDeclContext::FcnDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::RetTypeContext* smallCParser::FcnDeclContext::retType() {
  return getRuleContext<smallCParser::RetTypeContext>(0);
}

smallCParser::FcnNameContext* smallCParser::FcnDeclContext::fcnName() {
  return getRuleContext<smallCParser::FcnNameContext>(0);
}

smallCParser::ParamsContext* smallCParser::FcnDeclContext::params() {
  return getRuleContext<smallCParser::ParamsContext>(0);
}

smallCParser::ScopeContext* smallCParser::FcnDeclContext::scope() {
  return getRuleContext<smallCParser::ScopeContext>(0);
}


size_t smallCParser::FcnDeclContext::getRuleIndex() const {
  return smallCParser::RuleFcnDecl;
}


antlrcpp::Any smallCParser::FcnDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitFcnDecl(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::FcnDeclContext* smallCParser::fcnDecl() {
  FcnDeclContext *_localctx = _tracker.createInstance<FcnDeclContext>(_ctx, getState());
  enterRule(_localctx, 16, smallCParser::RuleFcnDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(138);
    dynamic_cast<FcnDeclContext *>(_localctx)->retTypeContext = retType();
    setState(139);
    dynamic_cast<FcnDeclContext *>(_localctx)->fcnNameContext = fcnName();
    setState(140);
    match(smallCParser::T__5);
    setState(141);
    dynamic_cast<FcnDeclContext *>(_localctx)->paramsContext = params();
    setState(142);
    match(smallCParser::T__6);
    setState(143);
    dynamic_cast<FcnDeclContext *>(_localctx)->scopeContext = scope();

            dynamic_cast<FcnDeclContext *>(_localctx)->decl =  new smallc::FunctionDeclNode();
            _localctx->decl->setRetType(dynamic_cast<FcnDeclContext *>(_localctx)->retTypeContext->type);
            _localctx->decl->setName(dynamic_cast<FcnDeclContext *>(_localctx)->fcnNameContext->name);
            _localctx->decl->setParameter(dynamic_cast<FcnDeclContext *>(_localctx)->paramsContext->parameters);
            _localctx->decl->setBody(dynamic_cast<FcnDeclContext *>(_localctx)->scopeContext->scope_);
            _localctx->decl->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarTypeContext ------------------------------------------------------------------

smallCParser::VarTypeContext::VarTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t smallCParser::VarTypeContext::getRuleIndex() const {
  return smallCParser::RuleVarType;
}


antlrcpp::Any smallCParser::VarTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitVarType(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::VarTypeContext* smallCParser::varType() {
  VarTypeContext *_localctx = _tracker.createInstance<VarTypeContext>(_ctx, getState());
  enterRule(_localctx, 18, smallCParser::RuleVarType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(150);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case smallCParser::T__7: {
        enterOuterAlt(_localctx, 1);
        setState(146);
        match(smallCParser::T__7);

                dynamic_cast<VarTypeContext *>(_localctx)->type =  new smallc::PrimitiveTypeNode();
                _localctx->type->setType(smallc::TypeNode::Bool);
                _localctx->type->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
            
        break;
      }

      case smallCParser::T__8: {
        enterOuterAlt(_localctx, 2);
        setState(148);
        match(smallCParser::T__8);

                dynamic_cast<VarTypeContext *>(_localctx)->type =  new smallc::PrimitiveTypeNode();
                _localctx->type->setType(smallc::TypeNode::Int);
                _localctx->type->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RetTypeContext ------------------------------------------------------------------

smallCParser::RetTypeContext::RetTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::VarTypeContext* smallCParser::RetTypeContext::varType() {
  return getRuleContext<smallCParser::VarTypeContext>(0);
}


size_t smallCParser::RetTypeContext::getRuleIndex() const {
  return smallCParser::RuleRetType;
}


antlrcpp::Any smallCParser::RetTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitRetType(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::RetTypeContext* smallCParser::retType() {
  RetTypeContext *_localctx = _tracker.createInstance<RetTypeContext>(_ctx, getState());
  enterRule(_localctx, 20, smallCParser::RuleRetType);

      dynamic_cast<RetTypeContext *>(_localctx)->type =  new smallc::PrimitiveTypeNode();


  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(157);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case smallCParser::T__9: {
        enterOuterAlt(_localctx, 1);
        setState(152);
        match(smallCParser::T__9);

                _localctx->type->setType(smallc::TypeNode::Void);
                _localctx->type->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
            
        break;
      }

      case smallCParser::T__7:
      case smallCParser::T__8: {
        enterOuterAlt(_localctx, 2);
        setState(154);
        dynamic_cast<RetTypeContext *>(_localctx)->varTypeContext = varType();

                dynamic_cast<RetTypeContext *>(_localctx)->type =  dynamic_cast<RetTypeContext *>(_localctx)->varTypeContext->type;
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantContext ------------------------------------------------------------------

smallCParser::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::BoolConstContext* smallCParser::ConstantContext::boolConst() {
  return getRuleContext<smallCParser::BoolConstContext>(0);
}

smallCParser::IntConstContext* smallCParser::ConstantContext::intConst() {
  return getRuleContext<smallCParser::IntConstContext>(0);
}


size_t smallCParser::ConstantContext::getRuleIndex() const {
  return smallCParser::RuleConstant;
}


antlrcpp::Any smallCParser::ConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitConstant(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ConstantContext* smallCParser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 22, smallCParser::RuleConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(165);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case smallCParser::BOOL: {
        enterOuterAlt(_localctx, 1);
        setState(159);
        dynamic_cast<ConstantContext *>(_localctx)->boolConstContext = boolConst();

                dynamic_cast<ConstantContext *>(_localctx)->val =  dynamic_cast<ConstantContext *>(_localctx)->boolConstContext->val;
            
        break;
      }

      case smallCParser::T__18:
      case smallCParser::INT: {
        enterOuterAlt(_localctx, 2);
        setState(162);
        dynamic_cast<ConstantContext *>(_localctx)->intConstContext = intConst();

                dynamic_cast<ConstantContext *>(_localctx)->val =  dynamic_cast<ConstantContext *>(_localctx)->intConstContext->val;
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BoolConstContext ------------------------------------------------------------------

smallCParser::BoolConstContext::BoolConstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* smallCParser::BoolConstContext::BOOL() {
  return getToken(smallCParser::BOOL, 0);
}


size_t smallCParser::BoolConstContext::getRuleIndex() const {
  return smallCParser::RuleBoolConst;
}


antlrcpp::Any smallCParser::BoolConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitBoolConst(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::BoolConstContext* smallCParser::boolConst() {
  BoolConstContext *_localctx = _tracker.createInstance<BoolConstContext>(_ctx, getState());
  enterRule(_localctx, 24, smallCParser::RuleBoolConst);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(167);
    dynamic_cast<BoolConstContext *>(_localctx)->boolToken = match(smallCParser::BOOL);

            dynamic_cast<BoolConstContext *>(_localctx)->val =  new smallc::BoolConstantNode((dynamic_cast<BoolConstContext *>(_localctx)->boolToken != nullptr ? dynamic_cast<BoolConstContext *>(_localctx)->boolToken->getText() : ""));
            _localctx->val->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScopeContext ------------------------------------------------------------------

smallCParser::ScopeContext::ScopeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<smallCParser::ScalarDeclContext *> smallCParser::ScopeContext::scalarDecl() {
  return getRuleContexts<smallCParser::ScalarDeclContext>();
}

smallCParser::ScalarDeclContext* smallCParser::ScopeContext::scalarDecl(size_t i) {
  return getRuleContext<smallCParser::ScalarDeclContext>(i);
}

std::vector<smallCParser::ArrDeclContext *> smallCParser::ScopeContext::arrDecl() {
  return getRuleContexts<smallCParser::ArrDeclContext>();
}

smallCParser::ArrDeclContext* smallCParser::ScopeContext::arrDecl(size_t i) {
  return getRuleContext<smallCParser::ArrDeclContext>(i);
}

std::vector<smallCParser::StmtContext *> smallCParser::ScopeContext::stmt() {
  return getRuleContexts<smallCParser::StmtContext>();
}

smallCParser::StmtContext* smallCParser::ScopeContext::stmt(size_t i) {
  return getRuleContext<smallCParser::StmtContext>(i);
}


size_t smallCParser::ScopeContext::getRuleIndex() const {
  return smallCParser::RuleScope;
}


antlrcpp::Any smallCParser::ScopeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitScope(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ScopeContext* smallCParser::scope() {
  ScopeContext *_localctx = _tracker.createInstance<ScopeContext>(_ctx, getState());
  enterRule(_localctx, 26, smallCParser::RuleScope);

      dynamic_cast<ScopeContext *>(_localctx)->scope_ =  new smallc::ScopeNode();
      _localctx->scope_->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(170);
    match(smallCParser::T__10);
    setState(179);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == smallCParser::T__7

    || _la == smallCParser::T__8) {
      setState(177);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
      case 1: {
        setState(171);
        dynamic_cast<ScopeContext *>(_localctx)->scalarDeclContext = scalarDecl();
        _localctx->scope_->addDeclaration(dynamic_cast<ScopeContext *>(_localctx)->scalarDeclContext->decl);
        break;
      }

      case 2: {
        setState(174);
        dynamic_cast<ScopeContext *>(_localctx)->arrDeclContext = arrDecl();
        _localctx->scope_->addDeclaration(dynamic_cast<ScopeContext *>(_localctx)->arrDeclContext->decl);
        break;
      }

      }
      setState(181);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(187);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << smallCParser::T__5)
      | (1ULL << smallCParser::T__10)
      | (1ULL << smallCParser::T__13)
      | (1ULL << smallCParser::T__15)
      | (1ULL << smallCParser::T__16)
      | (1ULL << smallCParser::T__17)
      | (1ULL << smallCParser::T__18)
      | (1ULL << smallCParser::BOOL)
      | (1ULL << smallCParser::ID)
      | (1ULL << smallCParser::INT))) != 0)) {
      setState(182);
      dynamic_cast<ScopeContext *>(_localctx)->stmtContext = stmt();
      _localctx->scope_->addChild(dynamic_cast<ScopeContext *>(_localctx)->stmtContext->statement);
      setState(189);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(190);
    match(smallCParser::T__11);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

smallCParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ExprContext* smallCParser::StmtContext::expr() {
  return getRuleContext<smallCParser::ExprContext>(0);
}

smallCParser::AssignStmtContext* smallCParser::StmtContext::assignStmt() {
  return getRuleContext<smallCParser::AssignStmtContext>(0);
}

smallCParser::IfStmtContext* smallCParser::StmtContext::ifStmt() {
  return getRuleContext<smallCParser::IfStmtContext>(0);
}

smallCParser::WhileStmtContext* smallCParser::StmtContext::whileStmt() {
  return getRuleContext<smallCParser::WhileStmtContext>(0);
}

smallCParser::RetStmtContext* smallCParser::StmtContext::retStmt() {
  return getRuleContext<smallCParser::RetStmtContext>(0);
}

smallCParser::ScopeContext* smallCParser::StmtContext::scope() {
  return getRuleContext<smallCParser::ScopeContext>(0);
}


size_t smallCParser::StmtContext::getRuleIndex() const {
  return smallCParser::RuleStmt;
}


antlrcpp::Any smallCParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::StmtContext* smallCParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 28, smallCParser::RuleStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(211);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(192);
      dynamic_cast<StmtContext *>(_localctx)->exprContext = expr(0);
      setState(193);
      match(smallCParser::T__2);

              dynamic_cast<StmtContext *>(_localctx)->statement =  new smallc::ExprStmtNode(dynamic_cast<StmtContext *>(_localctx)->exprContext->exp);
              _localctx->statement->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(196);
      dynamic_cast<StmtContext *>(_localctx)->assignStmtContext = assignStmt();

              dynamic_cast<StmtContext *>(_localctx)->statement =  dynamic_cast<StmtContext *>(_localctx)->assignStmtContext->statement;
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(199);
      dynamic_cast<StmtContext *>(_localctx)->ifStmtContext = ifStmt();

              dynamic_cast<StmtContext *>(_localctx)->statement =  dynamic_cast<StmtContext *>(_localctx)->ifStmtContext->statement;
          
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(202);
      dynamic_cast<StmtContext *>(_localctx)->whileStmtContext = whileStmt();

              dynamic_cast<StmtContext *>(_localctx)->statement =  dynamic_cast<StmtContext *>(_localctx)->whileStmtContext->statement;
          
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(205);
      dynamic_cast<StmtContext *>(_localctx)->retStmtContext = retStmt();

              dynamic_cast<StmtContext *>(_localctx)->statement =  dynamic_cast<StmtContext *>(_localctx)->retStmtContext->statement;
          
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(208);
      dynamic_cast<StmtContext *>(_localctx)->scopeContext = scope();

              dynamic_cast<StmtContext *>(_localctx)->statement =  dynamic_cast<StmtContext *>(_localctx)->scopeContext->scope_;
          
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignStmtContext ------------------------------------------------------------------

smallCParser::AssignStmtContext::AssignStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::VarContext* smallCParser::AssignStmtContext::var() {
  return getRuleContext<smallCParser::VarContext>(0);
}

smallCParser::ExprContext* smallCParser::AssignStmtContext::expr() {
  return getRuleContext<smallCParser::ExprContext>(0);
}


size_t smallCParser::AssignStmtContext::getRuleIndex() const {
  return smallCParser::RuleAssignStmt;
}


antlrcpp::Any smallCParser::AssignStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitAssignStmt(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::AssignStmtContext* smallCParser::assignStmt() {
  AssignStmtContext *_localctx = _tracker.createInstance<AssignStmtContext>(_ctx, getState());
  enterRule(_localctx, 30, smallCParser::RuleAssignStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(213);
    dynamic_cast<AssignStmtContext *>(_localctx)->varContext = var();
    setState(214);
    match(smallCParser::T__12);
    setState(215);
    dynamic_cast<AssignStmtContext *>(_localctx)->exprContext = expr(0);
    setState(216);
    match(smallCParser::T__2);

            dynamic_cast<AssignStmtContext *>(_localctx)->statement =  new smallc::AssignStmtNode(dynamic_cast<AssignStmtContext *>(_localctx)->varContext->ref, dynamic_cast<AssignStmtContext *>(_localctx)->exprContext->exp);
            _localctx->statement->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStmtContext ------------------------------------------------------------------

smallCParser::IfStmtContext::IfStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ExprContext* smallCParser::IfStmtContext::expr() {
  return getRuleContext<smallCParser::ExprContext>(0);
}

std::vector<smallCParser::StmtContext *> smallCParser::IfStmtContext::stmt() {
  return getRuleContexts<smallCParser::StmtContext>();
}

smallCParser::StmtContext* smallCParser::IfStmtContext::stmt(size_t i) {
  return getRuleContext<smallCParser::StmtContext>(i);
}


size_t smallCParser::IfStmtContext::getRuleIndex() const {
  return smallCParser::RuleIfStmt;
}


antlrcpp::Any smallCParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::IfStmtContext* smallCParser::ifStmt() {
  IfStmtContext *_localctx = _tracker.createInstance<IfStmtContext>(_ctx, getState());
  enterRule(_localctx, 32, smallCParser::RuleIfStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(235);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(219);
      match(smallCParser::T__13);
      setState(220);
      match(smallCParser::T__5);
      setState(221);
      dynamic_cast<IfStmtContext *>(_localctx)->exprContext = expr(0);
      setState(222);
      match(smallCParser::T__6);
      setState(223);
      dynamic_cast<IfStmtContext *>(_localctx)->stmtContext = stmt();

              dynamic_cast<IfStmtContext *>(_localctx)->statement =  new smallc::IfStmtNode(dynamic_cast<IfStmtContext *>(_localctx)->exprContext->exp, dynamic_cast<IfStmtContext *>(_localctx)->stmtContext->statement);
              _localctx->statement->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(226);
      match(smallCParser::T__13);
      setState(227);
      match(smallCParser::T__5);
      setState(228);
      dynamic_cast<IfStmtContext *>(_localctx)->exprContext = expr(0);
      setState(229);
      match(smallCParser::T__6);
      setState(230);
      dynamic_cast<IfStmtContext *>(_localctx)->then = stmt();
      setState(231);
      match(smallCParser::T__14);
      setState(232);
      dynamic_cast<IfStmtContext *>(_localctx)->e = stmt();

              dynamic_cast<IfStmtContext *>(_localctx)->statement =  new smallc::IfStmtNode(dynamic_cast<IfStmtContext *>(_localctx)->exprContext->exp, dynamic_cast<IfStmtContext *>(_localctx)->then->statement, dynamic_cast<IfStmtContext *>(_localctx)->e->statement);
              _localctx->statement->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
          
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStmtContext ------------------------------------------------------------------

smallCParser::WhileStmtContext::WhileStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ExprContext* smallCParser::WhileStmtContext::expr() {
  return getRuleContext<smallCParser::ExprContext>(0);
}

smallCParser::StmtContext* smallCParser::WhileStmtContext::stmt() {
  return getRuleContext<smallCParser::StmtContext>(0);
}


size_t smallCParser::WhileStmtContext::getRuleIndex() const {
  return smallCParser::RuleWhileStmt;
}


antlrcpp::Any smallCParser::WhileStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitWhileStmt(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::WhileStmtContext* smallCParser::whileStmt() {
  WhileStmtContext *_localctx = _tracker.createInstance<WhileStmtContext>(_ctx, getState());
  enterRule(_localctx, 34, smallCParser::RuleWhileStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(237);
    match(smallCParser::T__15);
    setState(238);
    match(smallCParser::T__5);
    setState(239);
    dynamic_cast<WhileStmtContext *>(_localctx)->exprContext = expr(0);
    setState(240);
    match(smallCParser::T__6);
    setState(241);
    dynamic_cast<WhileStmtContext *>(_localctx)->stmtContext = stmt();

            dynamic_cast<WhileStmtContext *>(_localctx)->statement =  new smallc::WhileStmtNode(dynamic_cast<WhileStmtContext *>(_localctx)->exprContext->exp, dynamic_cast<WhileStmtContext *>(_localctx)->stmtContext->statement);
            _localctx->statement->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RetStmtContext ------------------------------------------------------------------

smallCParser::RetStmtContext::RetStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ExprContext* smallCParser::RetStmtContext::expr() {
  return getRuleContext<smallCParser::ExprContext>(0);
}


size_t smallCParser::RetStmtContext::getRuleIndex() const {
  return smallCParser::RuleRetStmt;
}


antlrcpp::Any smallCParser::RetStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitRetStmt(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::RetStmtContext* smallCParser::retStmt() {
  RetStmtContext *_localctx = _tracker.createInstance<RetStmtContext>(_ctx, getState());
  enterRule(_localctx, 36, smallCParser::RuleRetStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(252);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(244);
      match(smallCParser::T__16);
      setState(245);
      dynamic_cast<RetStmtContext *>(_localctx)->exprContext = expr(0);
      setState(246);
      match(smallCParser::T__2);

              dynamic_cast<RetStmtContext *>(_localctx)->statement =  new smallc::ReturnStmtNode(dynamic_cast<RetStmtContext *>(_localctx)->exprContext->exp);
              _localctx->statement->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(249);
      match(smallCParser::T__16);
      setState(250);
      match(smallCParser::T__2);

              dynamic_cast<RetStmtContext *>(_localctx)->statement =  new smallc::ReturnStmtNode();
              _localctx->statement->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
          
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

smallCParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::IntExprContext* smallCParser::ExprContext::intExpr() {
  return getRuleContext<smallCParser::IntExprContext>(0);
}

std::vector<smallCParser::ExprContext *> smallCParser::ExprContext::expr() {
  return getRuleContexts<smallCParser::ExprContext>();
}

smallCParser::ExprContext* smallCParser::ExprContext::expr(size_t i) {
  return getRuleContext<smallCParser::ExprContext>(i);
}

smallCParser::FcnNameContext* smallCParser::ExprContext::fcnName() {
  return getRuleContext<smallCParser::FcnNameContext>(0);
}

smallCParser::ArgsContext* smallCParser::ExprContext::args() {
  return getRuleContext<smallCParser::ArgsContext>(0);
}


size_t smallCParser::ExprContext::getRuleIndex() const {
  return smallCParser::RuleExpr;
}


antlrcpp::Any smallCParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}


smallCParser::ExprContext* smallCParser::expr() {
   return expr(0);
}

smallCParser::ExprContext* smallCParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  smallCParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  smallCParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, smallCParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(273);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      setState(255);
      dynamic_cast<ExprContext *>(_localctx)->intExprContext = intExpr(0);

              dynamic_cast<ExprContext *>(_localctx)->exp =  dynamic_cast<ExprContext *>(_localctx)->intExprContext->exp;
          
      break;
    }

    case 2: {
      setState(258);
      match(smallCParser::T__5);
      setState(259);
      dynamic_cast<ExprContext *>(_localctx)->exprContext = expr(0);
      setState(260);
      match(smallCParser::T__6);

              dynamic_cast<ExprContext *>(_localctx)->exp =  dynamic_cast<ExprContext *>(_localctx)->exprContext->exp;
          
      break;
    }

    case 3: {
      setState(263);
      dynamic_cast<ExprContext *>(_localctx)->fcnNameContext = fcnName();
      setState(264);
      match(smallCParser::T__5);
      setState(265);
      dynamic_cast<ExprContext *>(_localctx)->argsContext = args();
      setState(266);
      match(smallCParser::T__6);

              dynamic_cast<ExprContext *>(_localctx)->call =  new smallc::CallExprNode(dynamic_cast<ExprContext *>(_localctx)->fcnNameContext->name, dynamic_cast<ExprContext *>(_localctx)->argsContext->arglist);
              _localctx->call->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              dynamic_cast<ExprContext *>(_localctx)->exp =  _localctx->call;
          
      break;
    }

    case 4: {
      setState(269);
      dynamic_cast<ExprContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == smallCParser::T__17

      || _la == smallCParser::T__18)) {
        dynamic_cast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(270);
      dynamic_cast<ExprContext *>(_localctx)->exprContext = expr(5);

              dynamic_cast<ExprContext *>(_localctx)->unary =  new smallc::UnaryExprNode(dynamic_cast<ExprContext *>(_localctx)->exprContext->exp);
              _localctx->unary->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              _localctx->unary->setOpcode((dynamic_cast<ExprContext *>(_localctx)->op != nullptr ? dynamic_cast<ExprContext *>(_localctx)->op->getText() : ""));
              dynamic_cast<ExprContext *>(_localctx)->exp =  _localctx->unary;
          
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(297);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(295);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->l = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(275);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(276);
          dynamic_cast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << smallCParser::T__19)
            | (1ULL << smallCParser::T__20)
            | (1ULL << smallCParser::T__21)
            | (1ULL << smallCParser::T__22))) != 0))) {
            dynamic_cast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(277);
          dynamic_cast<ExprContext *>(_localctx)->r = dynamic_cast<ExprContext *>(_localctx)->exprContext = expr(5);

                            dynamic_cast<ExprContext *>(_localctx)->bin =  new smallc::BinaryExprNode(dynamic_cast<ExprContext *>(_localctx)->l->exp, dynamic_cast<ExprContext *>(_localctx)->r->exp);
                            _localctx->bin->setOpcode((dynamic_cast<ExprContext *>(_localctx)->op != nullptr ? dynamic_cast<ExprContext *>(_localctx)->op->getText() : ""));
                            _localctx->bin->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                            dynamic_cast<ExprContext *>(_localctx)->boolvar =  new smallc::BoolExprNode(_localctx->bin);
                            dynamic_cast<ExprContext *>(_localctx)->exp =  _localctx->boolvar;
                        
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->l = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(280);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(281);
          dynamic_cast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == smallCParser::T__23

          || _la == smallCParser::T__24)) {
            dynamic_cast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(282);
          dynamic_cast<ExprContext *>(_localctx)->r = dynamic_cast<ExprContext *>(_localctx)->exprContext = expr(4);

                            dynamic_cast<ExprContext *>(_localctx)->bin =  new smallc::BinaryExprNode(dynamic_cast<ExprContext *>(_localctx)->l->exp, dynamic_cast<ExprContext *>(_localctx)->r->exp);
                            _localctx->bin->setOpcode((dynamic_cast<ExprContext *>(_localctx)->op != nullptr ? dynamic_cast<ExprContext *>(_localctx)->op->getText() : ""));
                            _localctx->bin->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                            dynamic_cast<ExprContext *>(_localctx)->boolvar =  new smallc::BoolExprNode(_localctx->bin);
                            dynamic_cast<ExprContext *>(_localctx)->exp =  _localctx->boolvar;
                        
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->l = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(285);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(286);
          dynamic_cast<ExprContext *>(_localctx)->op = match(smallCParser::T__25);
          setState(287);
          dynamic_cast<ExprContext *>(_localctx)->r = dynamic_cast<ExprContext *>(_localctx)->exprContext = expr(3);

                            dynamic_cast<ExprContext *>(_localctx)->bin =  new smallc::BinaryExprNode(dynamic_cast<ExprContext *>(_localctx)->l->exp, dynamic_cast<ExprContext *>(_localctx)->r->exp);
                            _localctx->bin->setOpcode((dynamic_cast<ExprContext *>(_localctx)->op != nullptr ? dynamic_cast<ExprContext *>(_localctx)->op->getText() : ""));
                            _localctx->bin->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                            dynamic_cast<ExprContext *>(_localctx)->boolvar =  new smallc::BoolExprNode(_localctx->bin);
                            dynamic_cast<ExprContext *>(_localctx)->exp =  _localctx->boolvar;
                        
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->l = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(290);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(291);
          dynamic_cast<ExprContext *>(_localctx)->op = match(smallCParser::T__26);
          setState(292);
          dynamic_cast<ExprContext *>(_localctx)->r = dynamic_cast<ExprContext *>(_localctx)->exprContext = expr(2);

                            dynamic_cast<ExprContext *>(_localctx)->bin =  new smallc::BinaryExprNode(dynamic_cast<ExprContext *>(_localctx)->l->exp, dynamic_cast<ExprContext *>(_localctx)->r->exp);
                            _localctx->bin->setOpcode((dynamic_cast<ExprContext *>(_localctx)->op != nullptr ? dynamic_cast<ExprContext *>(_localctx)->op->getText() : ""));
                            _localctx->bin->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                            dynamic_cast<ExprContext *>(_localctx)->boolvar =  new smallc::BoolExprNode(_localctx->bin);
                            dynamic_cast<ExprContext *>(_localctx)->exp =  _localctx->boolvar;
                        
          break;
        }

        } 
      }
      setState(299);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- IntExprContext ------------------------------------------------------------------

smallCParser::IntExprContext::IntExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::VarContext* smallCParser::IntExprContext::var() {
  return getRuleContext<smallCParser::VarContext>(0);
}

smallCParser::ConstantContext* smallCParser::IntExprContext::constant() {
  return getRuleContext<smallCParser::ConstantContext>(0);
}

std::vector<smallCParser::IntExprContext *> smallCParser::IntExprContext::intExpr() {
  return getRuleContexts<smallCParser::IntExprContext>();
}

smallCParser::IntExprContext* smallCParser::IntExprContext::intExpr(size_t i) {
  return getRuleContext<smallCParser::IntExprContext>(i);
}


size_t smallCParser::IntExprContext::getRuleIndex() const {
  return smallCParser::RuleIntExpr;
}


antlrcpp::Any smallCParser::IntExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitIntExpr(this);
  else
    return visitor->visitChildren(this);
}


smallCParser::IntExprContext* smallCParser::intExpr() {
   return intExpr(0);
}

smallCParser::IntExprContext* smallCParser::intExpr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  smallCParser::IntExprContext *_localctx = _tracker.createInstance<IntExprContext>(_ctx, parentState);
  smallCParser::IntExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, smallCParser::RuleIntExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(312);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case smallCParser::ID: {
        setState(301);
        dynamic_cast<IntExprContext *>(_localctx)->varContext = var();

                dynamic_cast<IntExprContext *>(_localctx)->exp =  new smallc::IntExprNode(dynamic_cast<IntExprContext *>(_localctx)->varContext->ref);
            
        break;
      }

      case smallCParser::T__18:
      case smallCParser::BOOL:
      case smallCParser::INT: {
        setState(304);
        dynamic_cast<IntExprContext *>(_localctx)->constantContext = constant();

                dynamic_cast<IntExprContext *>(_localctx)->exp =  new smallc::IntExprNode(dynamic_cast<IntExprContext *>(_localctx)->constantContext->val);
            
        break;
      }

      case smallCParser::T__5: {
        setState(307);
        match(smallCParser::T__5);
        setState(308);
        dynamic_cast<IntExprContext *>(_localctx)->self = intExpr(0);
        setState(309);
        match(smallCParser::T__6);

                dynamic_cast<IntExprContext *>(_localctx)->exp =  dynamic_cast<IntExprContext *>(_localctx)->self->exp;
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(326);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(324);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<IntExprContext>(parentContext, parentState);
          _localctx->l = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleIntExpr);
          setState(314);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(315);
          dynamic_cast<IntExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == smallCParser::T__27

          || _la == smallCParser::T__28)) {
            dynamic_cast<IntExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(316);
          dynamic_cast<IntExprContext *>(_localctx)->r = intExpr(4);

                            dynamic_cast<IntExprContext *>(_localctx)->bin =  new smallc::BinaryExprNode(dynamic_cast<IntExprContext *>(_localctx)->l->exp, dynamic_cast<IntExprContext *>(_localctx)->r->exp);
                            _localctx->bin->setOpcode((dynamic_cast<IntExprContext *>(_localctx)->op != nullptr ? dynamic_cast<IntExprContext *>(_localctx)->op->getText() : ""));
                            _localctx->bin->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                            dynamic_cast<IntExprContext *>(_localctx)->exp =  new smallc::IntExprNode(_localctx->bin);
                        
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<IntExprContext>(parentContext, parentState);
          _localctx->l = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleIntExpr);
          setState(319);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(320);
          dynamic_cast<IntExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == smallCParser::T__18

          || _la == smallCParser::T__29)) {
            dynamic_cast<IntExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(321);
          dynamic_cast<IntExprContext *>(_localctx)->r = intExpr(3);

                            dynamic_cast<IntExprContext *>(_localctx)->bin =  new smallc::BinaryExprNode(dynamic_cast<IntExprContext *>(_localctx)->l->exp, dynamic_cast<IntExprContext *>(_localctx)->r->exp);
                            _localctx->bin->setOpcode((dynamic_cast<IntExprContext *>(_localctx)->op != nullptr ? dynamic_cast<IntExprContext *>(_localctx)->op->getText() : ""));
                            _localctx->bin->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                            dynamic_cast<IntExprContext *>(_localctx)->exp =  new smallc::IntExprNode(_localctx->bin);
                        
          break;
        }

        } 
      }
      setState(328);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- VarContext ------------------------------------------------------------------

smallCParser::VarContext::VarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::VarNameContext* smallCParser::VarContext::varName() {
  return getRuleContext<smallCParser::VarNameContext>(0);
}

smallCParser::ArrNameContext* smallCParser::VarContext::arrName() {
  return getRuleContext<smallCParser::ArrNameContext>(0);
}

smallCParser::IntExprContext* smallCParser::VarContext::intExpr() {
  return getRuleContext<smallCParser::IntExprContext>(0);
}


size_t smallCParser::VarContext::getRuleIndex() const {
  return smallCParser::RuleVar;
}


antlrcpp::Any smallCParser::VarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitVar(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::VarContext* smallCParser::var() {
  VarContext *_localctx = _tracker.createInstance<VarContext>(_ctx, getState());
  enterRule(_localctx, 42, smallCParser::RuleVar);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(338);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(329);
      dynamic_cast<VarContext *>(_localctx)->varNameContext = varName();

              dynamic_cast<VarContext *>(_localctx)->ref =  new smallc::ReferenceExprNode(dynamic_cast<VarContext *>(_localctx)->varNameContext->name);
              _localctx->ref->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(332);
      dynamic_cast<VarContext *>(_localctx)->arrNameContext = arrName();
      setState(333);
      match(smallCParser::T__3);
      setState(334);
      dynamic_cast<VarContext *>(_localctx)->intExprContext = intExpr(0);
      setState(335);
      match(smallCParser::T__4);

              dynamic_cast<VarContext *>(_localctx)->ref =  new smallc::ReferenceExprNode(dynamic_cast<VarContext *>(_localctx)->arrNameContext->name, dynamic_cast<VarContext *>(_localctx)->intExprContext->exp);
              _localctx->ref->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
          
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamsContext ------------------------------------------------------------------

smallCParser::ParamsContext::ParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ParamListContext* smallCParser::ParamsContext::paramList() {
  return getRuleContext<smallCParser::ParamListContext>(0);
}


size_t smallCParser::ParamsContext::getRuleIndex() const {
  return smallCParser::RuleParams;
}


antlrcpp::Any smallCParser::ParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitParams(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ParamsContext* smallCParser::params() {
  ParamsContext *_localctx = _tracker.createInstance<ParamsContext>(_ctx, getState());
  enterRule(_localctx, 44, smallCParser::RuleParams);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(344);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case smallCParser::T__7:
      case smallCParser::T__8: {
        enterOuterAlt(_localctx, 1);
        setState(340);
        dynamic_cast<ParamsContext *>(_localctx)->paramListContext = paramList();

                dynamic_cast<ParamsContext *>(_localctx)->parameters =  dynamic_cast<ParamsContext *>(_localctx)->paramListContext->parameters;
            
        break;
      }

      case smallCParser::T__6: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamEntryContext ------------------------------------------------------------------

smallCParser::ParamEntryContext::ParamEntryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::VarTypeContext* smallCParser::ParamEntryContext::varType() {
  return getRuleContext<smallCParser::VarTypeContext>(0);
}

smallCParser::VarNameContext* smallCParser::ParamEntryContext::varName() {
  return getRuleContext<smallCParser::VarNameContext>(0);
}

smallCParser::ArrNameContext* smallCParser::ParamEntryContext::arrName() {
  return getRuleContext<smallCParser::ArrNameContext>(0);
}


size_t smallCParser::ParamEntryContext::getRuleIndex() const {
  return smallCParser::RuleParamEntry;
}


antlrcpp::Any smallCParser::ParamEntryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitParamEntry(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ParamEntryContext* smallCParser::paramEntry() {
  ParamEntryContext *_localctx = _tracker.createInstance<ParamEntryContext>(_ctx, getState());
  enterRule(_localctx, 46, smallCParser::RuleParamEntry);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(355);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(346);
      dynamic_cast<ParamEntryContext *>(_localctx)->varTypeContext = varType();
      setState(347);
      dynamic_cast<ParamEntryContext *>(_localctx)->varNameContext = varName();

              dynamic_cast<ParamEntryContext *>(_localctx)->param =  new smallc::ParameterNode(dynamic_cast<ParamEntryContext *>(_localctx)->varTypeContext->type, dynamic_cast<ParamEntryContext *>(_localctx)->varNameContext->name);
              _localctx->param->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(350);
      dynamic_cast<ParamEntryContext *>(_localctx)->varTypeContext = varType();
      setState(351);
      dynamic_cast<ParamEntryContext *>(_localctx)->arrNameContext = arrName();
      setState(352);
      match(smallCParser::T__30);

              dynamic_cast<ParamEntryContext *>(_localctx)->arrType =  new smallc::ArrayTypeNode(dynamic_cast<ParamEntryContext *>(_localctx)->varTypeContext->type);
              dynamic_cast<ParamEntryContext *>(_localctx)->param =  new smallc::ParameterNode(_localctx->arrType, dynamic_cast<ParamEntryContext *>(_localctx)->arrNameContext->name);
              _localctx->param->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
          
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamListContext ------------------------------------------------------------------

smallCParser::ParamListContext::ParamListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ParamEntryContext* smallCParser::ParamListContext::paramEntry() {
  return getRuleContext<smallCParser::ParamEntryContext>(0);
}

smallCParser::ParamListContext* smallCParser::ParamListContext::paramList() {
  return getRuleContext<smallCParser::ParamListContext>(0);
}


size_t smallCParser::ParamListContext::getRuleIndex() const {
  return smallCParser::RuleParamList;
}


antlrcpp::Any smallCParser::ParamListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitParamList(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ParamListContext* smallCParser::paramList() {
  ParamListContext *_localctx = _tracker.createInstance<ParamListContext>(_ctx, getState());
  enterRule(_localctx, 48, smallCParser::RuleParamList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(366);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(357);
      dynamic_cast<ParamListContext *>(_localctx)->paramEntryContext = paramEntry();

              _localctx->parameters.push_back(dynamic_cast<ParamListContext *>(_localctx)->paramEntryContext->param);
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(360);
      dynamic_cast<ParamListContext *>(_localctx)->paramEntryContext = paramEntry();

              _localctx->parameters.push_back(dynamic_cast<ParamListContext *>(_localctx)->paramEntryContext->param);
          
      setState(362);
      match(smallCParser::T__31);
      setState(363);
      dynamic_cast<ParamListContext *>(_localctx)->paramListContext = paramList();
      for(unsigned int i = 0; i < dynamic_cast<ParamListContext *>(_localctx)->paramListContext->parameters.size(); i++) _localctx->parameters.push_back(dynamic_cast<ParamListContext *>(_localctx)->paramListContext->parameters[i]);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgsContext ------------------------------------------------------------------

smallCParser::ArgsContext::ArgsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ArgListContext* smallCParser::ArgsContext::argList() {
  return getRuleContext<smallCParser::ArgListContext>(0);
}


size_t smallCParser::ArgsContext::getRuleIndex() const {
  return smallCParser::RuleArgs;
}


antlrcpp::Any smallCParser::ArgsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitArgs(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ArgsContext* smallCParser::args() {
  ArgsContext *_localctx = _tracker.createInstance<ArgsContext>(_ctx, getState());
  enterRule(_localctx, 50, smallCParser::RuleArgs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(372);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case smallCParser::T__5:
      case smallCParser::T__17:
      case smallCParser::T__18:
      case smallCParser::BOOL:
      case smallCParser::ID:
      case smallCParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(368);
        dynamic_cast<ArgsContext *>(_localctx)->argListContext = argList();
        dynamic_cast<ArgsContext *>(_localctx)->arglist =  dynamic_cast<ArgsContext *>(_localctx)->argListContext->arglist;
        break;
      }

      case smallCParser::T__6: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgEntryContext ------------------------------------------------------------------

smallCParser::ArgEntryContext::ArgEntryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ExprContext* smallCParser::ArgEntryContext::expr() {
  return getRuleContext<smallCParser::ExprContext>(0);
}


size_t smallCParser::ArgEntryContext::getRuleIndex() const {
  return smallCParser::RuleArgEntry;
}


antlrcpp::Any smallCParser::ArgEntryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitArgEntry(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ArgEntryContext* smallCParser::argEntry() {
  ArgEntryContext *_localctx = _tracker.createInstance<ArgEntryContext>(_ctx, getState());
  enterRule(_localctx, 52, smallCParser::RuleArgEntry);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(374);
    dynamic_cast<ArgEntryContext *>(_localctx)->exprContext = expr(0);

            dynamic_cast<ArgEntryContext *>(_localctx)->arg =  new smallc::ArgumentNode(dynamic_cast<ArgEntryContext *>(_localctx)->exprContext->exp);
            _localctx->arg->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgListContext ------------------------------------------------------------------

smallCParser::ArgListContext::ArgListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ArgEntryContext* smallCParser::ArgListContext::argEntry() {
  return getRuleContext<smallCParser::ArgEntryContext>(0);
}

smallCParser::ArgListContext* smallCParser::ArgListContext::argList() {
  return getRuleContext<smallCParser::ArgListContext>(0);
}


size_t smallCParser::ArgListContext::getRuleIndex() const {
  return smallCParser::RuleArgList;
}


antlrcpp::Any smallCParser::ArgListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitArgList(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ArgListContext* smallCParser::argList() {
  ArgListContext *_localctx = _tracker.createInstance<ArgListContext>(_ctx, getState());
  enterRule(_localctx, 54, smallCParser::RuleArgList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(386);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(377);
      dynamic_cast<ArgListContext *>(_localctx)->argEntryContext = argEntry();
      _localctx->arglist.push_back(dynamic_cast<ArgListContext *>(_localctx)->argEntryContext->arg);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(380);
      dynamic_cast<ArgListContext *>(_localctx)->argEntryContext = argEntry();
      _localctx->arglist.push_back(dynamic_cast<ArgListContext *>(_localctx)->argEntryContext->arg);
      setState(382);
      match(smallCParser::T__31);
      setState(383);
      dynamic_cast<ArgListContext *>(_localctx)->argListContext = argList();
      for(unsigned int i = 0; i < dynamic_cast<ArgListContext *>(_localctx)->argListContext->arglist.size(); i++) _localctx->arglist.push_back(dynamic_cast<ArgListContext *>(_localctx)->argListContext->arglist[i]);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarNameContext ------------------------------------------------------------------

smallCParser::VarNameContext::VarNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* smallCParser::VarNameContext::ID() {
  return getToken(smallCParser::ID, 0);
}


size_t smallCParser::VarNameContext::getRuleIndex() const {
  return smallCParser::RuleVarName;
}


antlrcpp::Any smallCParser::VarNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitVarName(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::VarNameContext* smallCParser::varName() {
  VarNameContext *_localctx = _tracker.createInstance<VarNameContext>(_ctx, getState());
  enterRule(_localctx, 56, smallCParser::RuleVarName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(388);
    dynamic_cast<VarNameContext *>(_localctx)->idToken = match(smallCParser::ID);

        dynamic_cast<VarNameContext *>(_localctx)->name =  new smallc::IdentifierNode((dynamic_cast<VarNameContext *>(_localctx)->idToken != nullptr ? dynamic_cast<VarNameContext *>(_localctx)->idToken->getText() : ""));
        _localctx->name->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrNameContext ------------------------------------------------------------------

smallCParser::ArrNameContext::ArrNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* smallCParser::ArrNameContext::ID() {
  return getToken(smallCParser::ID, 0);
}


size_t smallCParser::ArrNameContext::getRuleIndex() const {
  return smallCParser::RuleArrName;
}


antlrcpp::Any smallCParser::ArrNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitArrName(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ArrNameContext* smallCParser::arrName() {
  ArrNameContext *_localctx = _tracker.createInstance<ArrNameContext>(_ctx, getState());
  enterRule(_localctx, 58, smallCParser::RuleArrName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(391);
    dynamic_cast<ArrNameContext *>(_localctx)->idToken = match(smallCParser::ID);

        dynamic_cast<ArrNameContext *>(_localctx)->name =  new smallc::IdentifierNode((dynamic_cast<ArrNameContext *>(_localctx)->idToken != nullptr ? dynamic_cast<ArrNameContext *>(_localctx)->idToken->getText() : ""));
        _localctx->name->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FcnNameContext ------------------------------------------------------------------

smallCParser::FcnNameContext::FcnNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* smallCParser::FcnNameContext::ID() {
  return getToken(smallCParser::ID, 0);
}


size_t smallCParser::FcnNameContext::getRuleIndex() const {
  return smallCParser::RuleFcnName;
}


antlrcpp::Any smallCParser::FcnNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitFcnName(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::FcnNameContext* smallCParser::fcnName() {
  FcnNameContext *_localctx = _tracker.createInstance<FcnNameContext>(_ctx, getState());
  enterRule(_localctx, 60, smallCParser::RuleFcnName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(394);
    dynamic_cast<FcnNameContext *>(_localctx)->idToken = match(smallCParser::ID);

        dynamic_cast<FcnNameContext *>(_localctx)->name =  new smallc::IdentifierNode((dynamic_cast<FcnNameContext *>(_localctx)->idToken != nullptr ? dynamic_cast<FcnNameContext *>(_localctx)->idToken->getText() : ""));
        _localctx->name->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntConstContext ------------------------------------------------------------------

smallCParser::IntConstContext::IntConstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* smallCParser::IntConstContext::INT() {
  return getToken(smallCParser::INT, 0);
}


size_t smallCParser::IntConstContext::getRuleIndex() const {
  return smallCParser::RuleIntConst;
}


antlrcpp::Any smallCParser::IntConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitIntConst(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::IntConstContext* smallCParser::intConst() {
  IntConstContext *_localctx = _tracker.createInstance<IntConstContext>(_ctx, getState());
  enterRule(_localctx, 62, smallCParser::RuleIntConst);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(402);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case smallCParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(397);
        dynamic_cast<IntConstContext *>(_localctx)->intToken = match(smallCParser::INT);

            dynamic_cast<IntConstContext *>(_localctx)->neg =  (dynamic_cast<IntConstContext *>(_localctx)->intToken != nullptr ? dynamic_cast<IntConstContext *>(_localctx)->intToken->getText() : "");
            dynamic_cast<IntConstContext *>(_localctx)->val =  new smallc::IntConstantNode((dynamic_cast<IntConstContext *>(_localctx)->intToken != nullptr ? dynamic_cast<IntConstContext *>(_localctx)->intToken->getText() : ""));
            //dynamic_cast<IntConstContext *>(_localctx)->val =  new smallc::IntConstantNode((dynamic_cast<IntConstContext *>(_localctx)->intToken != nullptr ? dynamic_cast<IntConstContext *>(_localctx)->intToken->getText() : ""));
            _localctx->val->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

        break;
      }

      case smallCParser::T__18: {
        enterOuterAlt(_localctx, 2);
        setState(399);
        match(smallCParser::T__18);
        setState(400);
        dynamic_cast<IntConstContext *>(_localctx)->intToken = match(smallCParser::INT);

            dynamic_cast<IntConstContext *>(_localctx)->neg =  "-" + (dynamic_cast<IntConstContext *>(_localctx)->intToken != nullptr ? dynamic_cast<IntConstContext *>(_localctx)->intToken->getText() : "");
            dynamic_cast<IntConstContext *>(_localctx)->val =  new smallc::IntConstantNode(_localctx->neg);
            //dynamic_cast<IntConstContext *>(_localctx)->val =  new smallc::IntConstantNode((dynamic_cast<IntConstContext *>(_localctx)->intToken != nullptr ? dynamic_cast<IntConstContext *>(_localctx)->intToken->getText() : ""));
            _localctx->val->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool smallCParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 19: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);
    case 20: return intExprSempred(dynamic_cast<IntExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool smallCParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 4);
    case 1: return precpred(_ctx, 3);
    case 2: return precpred(_ctx, 2);
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool smallCParser::intExprSempred(IntExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 3);
    case 5: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> smallCParser::_decisionToDFA;
atn::PredictionContextCache smallCParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN smallCParser::_atn;
std::vector<uint16_t> smallCParser::_serializedATN;

std::vector<std::string> smallCParser::_ruleNames = {
  "program", "preamble", "decls", "scalarDeclList", "scalarDecl", "arrDeclList", 
  "arrDecl", "fcnProto", "fcnDecl", "varType", "retType", "constant", "boolConst", 
  "scope", "stmt", "assignStmt", "ifStmt", "whileStmt", "retStmt", "expr", 
  "intExpr", "var", "params", "paramEntry", "paramList", "args", "argEntry", 
  "argList", "varName", "arrName", "fcnName", "intConst"
};

std::vector<std::string> smallCParser::_literalNames = {
  "", "'#include'", "'\"scio.h\"'", "';'", "'['", "']'", "'('", "')'", "'bool'", 
  "'int'", "'void'", "'{'", "'}'", "'='", "'if'", "'else'", "'while'", "'return'", 
  "'!'", "'-'", "'<'", "'<='", "'>'", "'>='", "'=='", "'!='", "'||'", "'&&'", 
  "'*'", "'/'", "'+'", "'[]'", "','"
};

std::vector<std::string> smallCParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "BOOL", "ID", 
  "INT", "WS", "COMMENT"
};

dfa::Vocabulary smallCParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> smallCParser::_tokenNames;

smallCParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x27, 0x197, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x47, 0xa, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x7, 0x2, 0x4c, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x4f, 0xb, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x62, 0xa, 0x4, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x5, 0x5, 0x6c, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x5, 0x7, 0x7b, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x99, 0xa, 0xb, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xa0, 0xa, 0xc, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 
    0xa8, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0xb4, 0xa, 0xf, 
    0xc, 0xf, 0xe, 0xf, 0xb7, 0xb, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 
    0xf, 0xbc, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0xbf, 0xb, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x5, 0x10, 0xd6, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0xee, 
    0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0xff, 0xa, 0x14, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x114, 
    0xa, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x7, 0x15, 0x12a, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 
    0x12d, 0xb, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x5, 0x16, 0x13b, 0xa, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x7, 0x16, 0x147, 0xa, 0x16, 0xc, 0x16, 0xe, 0x16, 0x14a, 0xb, 
    0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x155, 0xa, 0x17, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x15b, 0xa, 0x18, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x19, 0x5, 0x19, 0x166, 0xa, 0x19, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 
    0x1a, 0x5, 0x1a, 0x171, 0xa, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x5, 0x1b, 0x177, 0xa, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 
    0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x185, 0xa, 0x1d, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 
    0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x5, 0x21, 0x195, 0xa, 0x21, 0x3, 0x21, 0x2, 0x4, 0x28, 0x2a, 0x22, 
    0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 
    0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 
    0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x2, 0x7, 0x3, 0x2, 0x14, 
    0x15, 0x3, 0x2, 0x16, 0x19, 0x3, 0x2, 0x1a, 0x1b, 0x3, 0x2, 0x1e, 0x1f, 
    0x4, 0x2, 0x15, 0x15, 0x20, 0x20, 0x2, 0x19c, 0x2, 0x46, 0x3, 0x2, 0x2, 
    0x2, 0x4, 0x52, 0x3, 0x2, 0x2, 0x2, 0x6, 0x61, 0x3, 0x2, 0x2, 0x2, 0x8, 
    0x6b, 0x3, 0x2, 0x2, 0x2, 0xa, 0x6d, 0x3, 0x2, 0x2, 0x2, 0xc, 0x7a, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x10, 0x84, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x14, 0x98, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x18, 0xa7, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xac, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0xd5, 0x3, 0x2, 0x2, 0x2, 0x20, 0xd7, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0xed, 0x3, 0x2, 0x2, 0x2, 0x24, 0xef, 0x3, 0x2, 0x2, 0x2, 0x26, 0xfe, 
    0x3, 0x2, 0x2, 0x2, 0x28, 0x113, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x13a, 0x3, 
    0x2, 0x2, 0x2, 0x2c, 0x154, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x15a, 0x3, 0x2, 
    0x2, 0x2, 0x30, 0x165, 0x3, 0x2, 0x2, 0x2, 0x32, 0x170, 0x3, 0x2, 0x2, 
    0x2, 0x34, 0x176, 0x3, 0x2, 0x2, 0x2, 0x36, 0x178, 0x3, 0x2, 0x2, 0x2, 
    0x38, 0x184, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x186, 0x3, 0x2, 0x2, 0x2, 0x3c, 
    0x189, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x40, 0x194, 
    0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 0x5, 0x4, 0x3, 0x2, 0x43, 0x44, 0x8, 
    0x2, 0x1, 0x2, 0x44, 0x47, 0x3, 0x2, 0x2, 0x2, 0x45, 0x47, 0x3, 0x2, 
    0x2, 0x2, 0x46, 0x42, 0x3, 0x2, 0x2, 0x2, 0x46, 0x45, 0x3, 0x2, 0x2, 
    0x2, 0x47, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x48, 0x49, 0x5, 0x6, 0x4, 0x2, 
    0x49, 0x4a, 0x8, 0x2, 0x1, 0x2, 0x4a, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4b, 
    0x48, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4b, 
    0x3, 0x2, 0x2, 0x2, 0x4d, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x50, 0x3, 
    0x2, 0x2, 0x2, 0x4f, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x50, 0x51, 0x7, 0x2, 
    0x2, 0x3, 0x51, 0x3, 0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 0x7, 0x3, 0x2, 
    0x2, 0x53, 0x54, 0x7, 0x4, 0x2, 0x2, 0x54, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0x55, 0x56, 0x5, 0x8, 0x5, 0x2, 0x56, 0x57, 0x8, 0x4, 0x1, 0x2, 0x57, 
    0x62, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 0x5, 0xc, 0x7, 0x2, 0x59, 0x5a, 
    0x8, 0x4, 0x1, 0x2, 0x5a, 0x62, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 0x5, 
    0x10, 0x9, 0x2, 0x5c, 0x5d, 0x8, 0x4, 0x1, 0x2, 0x5d, 0x62, 0x3, 0x2, 
    0x2, 0x2, 0x5e, 0x5f, 0x5, 0x12, 0xa, 0x2, 0x5f, 0x60, 0x8, 0x4, 0x1, 
    0x2, 0x60, 0x62, 0x3, 0x2, 0x2, 0x2, 0x61, 0x55, 0x3, 0x2, 0x2, 0x2, 
    0x61, 0x58, 0x3, 0x2, 0x2, 0x2, 0x61, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x61, 
    0x5e, 0x3, 0x2, 0x2, 0x2, 0x62, 0x7, 0x3, 0x2, 0x2, 0x2, 0x63, 0x64, 
    0x5, 0xa, 0x6, 0x2, 0x64, 0x65, 0x8, 0x5, 0x1, 0x2, 0x65, 0x6c, 0x3, 
    0x2, 0x2, 0x2, 0x66, 0x67, 0x5, 0xa, 0x6, 0x2, 0x67, 0x68, 0x8, 0x5, 
    0x1, 0x2, 0x68, 0x69, 0x5, 0x8, 0x5, 0x2, 0x69, 0x6a, 0x8, 0x5, 0x1, 
    0x2, 0x6a, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x63, 0x3, 0x2, 0x2, 0x2, 
    0x6b, 0x66, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x9, 0x3, 0x2, 0x2, 0x2, 0x6d, 
    0x6e, 0x5, 0x14, 0xb, 0x2, 0x6e, 0x6f, 0x5, 0x3a, 0x1e, 0x2, 0x6f, 0x70, 
    0x7, 0x5, 0x2, 0x2, 0x70, 0x71, 0x8, 0x6, 0x1, 0x2, 0x71, 0xb, 0x3, 
    0x2, 0x2, 0x2, 0x72, 0x73, 0x5, 0xe, 0x8, 0x2, 0x73, 0x74, 0x8, 0x7, 
    0x1, 0x2, 0x74, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0x5, 0xe, 0x8, 
    0x2, 0x76, 0x77, 0x8, 0x7, 0x1, 0x2, 0x77, 0x78, 0x5, 0xc, 0x7, 0x2, 
    0x78, 0x79, 0x8, 0x7, 0x1, 0x2, 0x79, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7a, 
    0x72, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x75, 0x3, 0x2, 0x2, 0x2, 0x7b, 0xd, 
    0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x5, 0x14, 0xb, 0x2, 0x7d, 0x7e, 0x5, 
    0x3c, 0x1f, 0x2, 0x7e, 0x7f, 0x7, 0x6, 0x2, 0x2, 0x7f, 0x80, 0x5, 0x40, 
    0x21, 0x2, 0x80, 0x81, 0x7, 0x7, 0x2, 0x2, 0x81, 0x82, 0x7, 0x5, 0x2, 
    0x2, 0x82, 0x83, 0x8, 0x8, 0x1, 0x2, 0x83, 0xf, 0x3, 0x2, 0x2, 0x2, 
    0x84, 0x85, 0x5, 0x16, 0xc, 0x2, 0x85, 0x86, 0x5, 0x3e, 0x20, 0x2, 0x86, 
    0x87, 0x7, 0x8, 0x2, 0x2, 0x87, 0x88, 0x5, 0x2e, 0x18, 0x2, 0x88, 0x89, 
    0x7, 0x9, 0x2, 0x2, 0x89, 0x8a, 0x7, 0x5, 0x2, 0x2, 0x8a, 0x8b, 0x8, 
    0x9, 0x1, 0x2, 0x8b, 0x11, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8d, 0x5, 0x16, 
    0xc, 0x2, 0x8d, 0x8e, 0x5, 0x3e, 0x20, 0x2, 0x8e, 0x8f, 0x7, 0x8, 0x2, 
    0x2, 0x8f, 0x90, 0x5, 0x2e, 0x18, 0x2, 0x90, 0x91, 0x7, 0x9, 0x2, 0x2, 
    0x91, 0x92, 0x5, 0x1c, 0xf, 0x2, 0x92, 0x93, 0x8, 0xa, 0x1, 0x2, 0x93, 
    0x13, 0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 0x7, 0xa, 0x2, 0x2, 0x95, 0x99, 
    0x8, 0xb, 0x1, 0x2, 0x96, 0x97, 0x7, 0xb, 0x2, 0x2, 0x97, 0x99, 0x8, 
    0xb, 0x1, 0x2, 0x98, 0x94, 0x3, 0x2, 0x2, 0x2, 0x98, 0x96, 0x3, 0x2, 
    0x2, 0x2, 0x99, 0x15, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9b, 0x7, 0xc, 0x2, 
    0x2, 0x9b, 0xa0, 0x8, 0xc, 0x1, 0x2, 0x9c, 0x9d, 0x5, 0x14, 0xb, 0x2, 
    0x9d, 0x9e, 0x8, 0xc, 0x1, 0x2, 0x9e, 0xa0, 0x3, 0x2, 0x2, 0x2, 0x9f, 
    0x9a, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x9c, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x17, 
    0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x5, 0x1a, 0xe, 0x2, 0xa2, 0xa3, 0x8, 
    0xd, 0x1, 0x2, 0xa3, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa5, 0x5, 0x40, 
    0x21, 0x2, 0xa5, 0xa6, 0x8, 0xd, 0x1, 0x2, 0xa6, 0xa8, 0x3, 0x2, 0x2, 
    0x2, 0xa7, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa4, 0x3, 0x2, 0x2, 0x2, 
    0xa8, 0x19, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xaa, 0x7, 0x23, 0x2, 0x2, 0xaa, 
    0xab, 0x8, 0xe, 0x1, 0x2, 0xab, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xac, 0xb5, 
    0x7, 0xd, 0x2, 0x2, 0xad, 0xae, 0x5, 0xa, 0x6, 0x2, 0xae, 0xaf, 0x8, 
    0xf, 0x1, 0x2, 0xaf, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 0x5, 0xe, 
    0x8, 0x2, 0xb1, 0xb2, 0x8, 0xf, 0x1, 0x2, 0xb2, 0xb4, 0x3, 0x2, 0x2, 
    0x2, 0xb3, 0xad, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb0, 0x3, 0x2, 0x2, 0x2, 
    0xb4, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb5, 
    0xb6, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb5, 
    0x3, 0x2, 0x2, 0x2, 0xb8, 0xb9, 0x5, 0x1e, 0x10, 0x2, 0xb9, 0xba, 0x8, 
    0xf, 0x1, 0x2, 0xba, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xb8, 0x3, 0x2, 
    0x2, 0x2, 0xbc, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbb, 0x3, 0x2, 0x2, 
    0x2, 0xbd, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xc0, 0x3, 0x2, 0x2, 0x2, 
    0xbf, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc1, 0x7, 0xe, 0x2, 0x2, 0xc1, 
    0x1d, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 0x5, 0x28, 0x15, 0x2, 0xc3, 0xc4, 
    0x7, 0x5, 0x2, 0x2, 0xc4, 0xc5, 0x8, 0x10, 0x1, 0x2, 0xc5, 0xd6, 0x3, 
    0x2, 0x2, 0x2, 0xc6, 0xc7, 0x5, 0x20, 0x11, 0x2, 0xc7, 0xc8, 0x8, 0x10, 
    0x1, 0x2, 0xc8, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0x5, 0x22, 0x12, 
    0x2, 0xca, 0xcb, 0x8, 0x10, 0x1, 0x2, 0xcb, 0xd6, 0x3, 0x2, 0x2, 0x2, 
    0xcc, 0xcd, 0x5, 0x24, 0x13, 0x2, 0xcd, 0xce, 0x8, 0x10, 0x1, 0x2, 0xce, 
    0xd6, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd0, 0x5, 0x26, 0x14, 0x2, 0xd0, 0xd1, 
    0x8, 0x10, 0x1, 0x2, 0xd1, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd3, 0x5, 
    0x1c, 0xf, 0x2, 0xd3, 0xd4, 0x8, 0x10, 0x1, 0x2, 0xd4, 0xd6, 0x3, 0x2, 
    0x2, 0x2, 0xd5, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xc6, 0x3, 0x2, 0x2, 
    0x2, 0xd5, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xcc, 0x3, 0x2, 0x2, 0x2, 
    0xd5, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd6, 
    0x1f, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd8, 0x5, 0x2c, 0x17, 0x2, 0xd8, 0xd9, 
    0x7, 0xf, 0x2, 0x2, 0xd9, 0xda, 0x5, 0x28, 0x15, 0x2, 0xda, 0xdb, 0x7, 
    0x5, 0x2, 0x2, 0xdb, 0xdc, 0x8, 0x11, 0x1, 0x2, 0xdc, 0x21, 0x3, 0x2, 
    0x2, 0x2, 0xdd, 0xde, 0x7, 0x10, 0x2, 0x2, 0xde, 0xdf, 0x7, 0x8, 0x2, 
    0x2, 0xdf, 0xe0, 0x5, 0x28, 0x15, 0x2, 0xe0, 0xe1, 0x7, 0x9, 0x2, 0x2, 
    0xe1, 0xe2, 0x5, 0x1e, 0x10, 0x2, 0xe2, 0xe3, 0x8, 0x12, 0x1, 0x2, 0xe3, 
    0xee, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe5, 0x7, 0x10, 0x2, 0x2, 0xe5, 0xe6, 
    0x7, 0x8, 0x2, 0x2, 0xe6, 0xe7, 0x5, 0x28, 0x15, 0x2, 0xe7, 0xe8, 0x7, 
    0x9, 0x2, 0x2, 0xe8, 0xe9, 0x5, 0x1e, 0x10, 0x2, 0xe9, 0xea, 0x7, 0x11, 
    0x2, 0x2, 0xea, 0xeb, 0x5, 0x1e, 0x10, 0x2, 0xeb, 0xec, 0x8, 0x12, 0x1, 
    0x2, 0xec, 0xee, 0x3, 0x2, 0x2, 0x2, 0xed, 0xdd, 0x3, 0x2, 0x2, 0x2, 
    0xed, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xee, 0x23, 0x3, 0x2, 0x2, 0x2, 0xef, 
    0xf0, 0x7, 0x12, 0x2, 0x2, 0xf0, 0xf1, 0x7, 0x8, 0x2, 0x2, 0xf1, 0xf2, 
    0x5, 0x28, 0x15, 0x2, 0xf2, 0xf3, 0x7, 0x9, 0x2, 0x2, 0xf3, 0xf4, 0x5, 
    0x1e, 0x10, 0x2, 0xf4, 0xf5, 0x8, 0x13, 0x1, 0x2, 0xf5, 0x25, 0x3, 0x2, 
    0x2, 0x2, 0xf6, 0xf7, 0x7, 0x13, 0x2, 0x2, 0xf7, 0xf8, 0x5, 0x28, 0x15, 
    0x2, 0xf8, 0xf9, 0x7, 0x5, 0x2, 0x2, 0xf9, 0xfa, 0x8, 0x14, 0x1, 0x2, 
    0xfa, 0xff, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfc, 0x7, 0x13, 0x2, 0x2, 0xfc, 
    0xfd, 0x7, 0x5, 0x2, 0x2, 0xfd, 0xff, 0x8, 0x14, 0x1, 0x2, 0xfe, 0xf6, 
    0x3, 0x2, 0x2, 0x2, 0xfe, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xff, 0x27, 0x3, 
    0x2, 0x2, 0x2, 0x100, 0x101, 0x8, 0x15, 0x1, 0x2, 0x101, 0x102, 0x5, 
    0x2a, 0x16, 0x2, 0x102, 0x103, 0x8, 0x15, 0x1, 0x2, 0x103, 0x114, 0x3, 
    0x2, 0x2, 0x2, 0x104, 0x105, 0x7, 0x8, 0x2, 0x2, 0x105, 0x106, 0x5, 
    0x28, 0x15, 0x2, 0x106, 0x107, 0x7, 0x9, 0x2, 0x2, 0x107, 0x108, 0x8, 
    0x15, 0x1, 0x2, 0x108, 0x114, 0x3, 0x2, 0x2, 0x2, 0x109, 0x10a, 0x5, 
    0x3e, 0x20, 0x2, 0x10a, 0x10b, 0x7, 0x8, 0x2, 0x2, 0x10b, 0x10c, 0x5, 
    0x34, 0x1b, 0x2, 0x10c, 0x10d, 0x7, 0x9, 0x2, 0x2, 0x10d, 0x10e, 0x8, 
    0x15, 0x1, 0x2, 0x10e, 0x114, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x110, 0x9, 
    0x2, 0x2, 0x2, 0x110, 0x111, 0x5, 0x28, 0x15, 0x7, 0x111, 0x112, 0x8, 
    0x15, 0x1, 0x2, 0x112, 0x114, 0x3, 0x2, 0x2, 0x2, 0x113, 0x100, 0x3, 
    0x2, 0x2, 0x2, 0x113, 0x104, 0x3, 0x2, 0x2, 0x2, 0x113, 0x109, 0x3, 
    0x2, 0x2, 0x2, 0x113, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x114, 0x12b, 0x3, 
    0x2, 0x2, 0x2, 0x115, 0x116, 0xc, 0x6, 0x2, 0x2, 0x116, 0x117, 0x9, 
    0x3, 0x2, 0x2, 0x117, 0x118, 0x5, 0x28, 0x15, 0x7, 0x118, 0x119, 0x8, 
    0x15, 0x1, 0x2, 0x119, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11b, 0xc, 
    0x5, 0x2, 0x2, 0x11b, 0x11c, 0x9, 0x4, 0x2, 0x2, 0x11c, 0x11d, 0x5, 
    0x28, 0x15, 0x6, 0x11d, 0x11e, 0x8, 0x15, 0x1, 0x2, 0x11e, 0x12a, 0x3, 
    0x2, 0x2, 0x2, 0x11f, 0x120, 0xc, 0x4, 0x2, 0x2, 0x120, 0x121, 0x7, 
    0x1c, 0x2, 0x2, 0x121, 0x122, 0x5, 0x28, 0x15, 0x5, 0x122, 0x123, 0x8, 
    0x15, 0x1, 0x2, 0x123, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x124, 0x125, 0xc, 
    0x3, 0x2, 0x2, 0x125, 0x126, 0x7, 0x1d, 0x2, 0x2, 0x126, 0x127, 0x5, 
    0x28, 0x15, 0x4, 0x127, 0x128, 0x8, 0x15, 0x1, 0x2, 0x128, 0x12a, 0x3, 
    0x2, 0x2, 0x2, 0x129, 0x115, 0x3, 0x2, 0x2, 0x2, 0x129, 0x11a, 0x3, 
    0x2, 0x2, 0x2, 0x129, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x129, 0x124, 0x3, 
    0x2, 0x2, 0x2, 0x12a, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x129, 0x3, 
    0x2, 0x2, 0x2, 0x12b, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x29, 0x3, 0x2, 
    0x2, 0x2, 0x12d, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x12f, 0x8, 0x16, 
    0x1, 0x2, 0x12f, 0x130, 0x5, 0x2c, 0x17, 0x2, 0x130, 0x131, 0x8, 0x16, 
    0x1, 0x2, 0x131, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x132, 0x133, 0x5, 0x18, 
    0xd, 0x2, 0x133, 0x134, 0x8, 0x16, 0x1, 0x2, 0x134, 0x13b, 0x3, 0x2, 
    0x2, 0x2, 0x135, 0x136, 0x7, 0x8, 0x2, 0x2, 0x136, 0x137, 0x5, 0x2a, 
    0x16, 0x2, 0x137, 0x138, 0x7, 0x9, 0x2, 0x2, 0x138, 0x139, 0x8, 0x16, 
    0x1, 0x2, 0x139, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x12e, 0x3, 0x2, 
    0x2, 0x2, 0x13a, 0x132, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x135, 0x3, 0x2, 
    0x2, 0x2, 0x13b, 0x148, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x13d, 0xc, 0x5, 
    0x2, 0x2, 0x13d, 0x13e, 0x9, 0x5, 0x2, 0x2, 0x13e, 0x13f, 0x5, 0x2a, 
    0x16, 0x6, 0x13f, 0x140, 0x8, 0x16, 0x1, 0x2, 0x140, 0x147, 0x3, 0x2, 
    0x2, 0x2, 0x141, 0x142, 0xc, 0x4, 0x2, 0x2, 0x142, 0x143, 0x9, 0x6, 
    0x2, 0x2, 0x143, 0x144, 0x5, 0x2a, 0x16, 0x5, 0x144, 0x145, 0x8, 0x16, 
    0x1, 0x2, 0x145, 0x147, 0x3, 0x2, 0x2, 0x2, 0x146, 0x13c, 0x3, 0x2, 
    0x2, 0x2, 0x146, 0x141, 0x3, 0x2, 0x2, 0x2, 0x147, 0x14a, 0x3, 0x2, 
    0x2, 0x2, 0x148, 0x146, 0x3, 0x2, 0x2, 0x2, 0x148, 0x149, 0x3, 0x2, 
    0x2, 0x2, 0x149, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x148, 0x3, 0x2, 0x2, 
    0x2, 0x14b, 0x14c, 0x5, 0x3a, 0x1e, 0x2, 0x14c, 0x14d, 0x8, 0x17, 0x1, 
    0x2, 0x14d, 0x155, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x14f, 0x5, 0x3c, 0x1f, 
    0x2, 0x14f, 0x150, 0x7, 0x6, 0x2, 0x2, 0x150, 0x151, 0x5, 0x2a, 0x16, 
    0x2, 0x151, 0x152, 0x7, 0x7, 0x2, 0x2, 0x152, 0x153, 0x8, 0x17, 0x1, 
    0x2, 0x153, 0x155, 0x3, 0x2, 0x2, 0x2, 0x154, 0x14b, 0x3, 0x2, 0x2, 
    0x2, 0x154, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x155, 0x2d, 0x3, 0x2, 0x2, 0x2, 
    0x156, 0x157, 0x5, 0x32, 0x1a, 0x2, 0x157, 0x158, 0x8, 0x18, 0x1, 0x2, 
    0x158, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x159, 0x15b, 0x3, 0x2, 0x2, 0x2, 
    0x15a, 0x156, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x159, 0x3, 0x2, 0x2, 0x2, 
    0x15b, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x15d, 0x5, 0x14, 0xb, 0x2, 
    0x15d, 0x15e, 0x5, 0x3a, 0x1e, 0x2, 0x15e, 0x15f, 0x8, 0x19, 0x1, 0x2, 
    0x15f, 0x166, 0x3, 0x2, 0x2, 0x2, 0x160, 0x161, 0x5, 0x14, 0xb, 0x2, 
    0x161, 0x162, 0x5, 0x3c, 0x1f, 0x2, 0x162, 0x163, 0x7, 0x21, 0x2, 0x2, 
    0x163, 0x164, 0x8, 0x19, 0x1, 0x2, 0x164, 0x166, 0x3, 0x2, 0x2, 0x2, 
    0x165, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x165, 0x160, 0x3, 0x2, 0x2, 0x2, 
    0x166, 0x31, 0x3, 0x2, 0x2, 0x2, 0x167, 0x168, 0x5, 0x30, 0x19, 0x2, 
    0x168, 0x169, 0x8, 0x1a, 0x1, 0x2, 0x169, 0x171, 0x3, 0x2, 0x2, 0x2, 
    0x16a, 0x16b, 0x5, 0x30, 0x19, 0x2, 0x16b, 0x16c, 0x8, 0x1a, 0x1, 0x2, 
    0x16c, 0x16d, 0x7, 0x22, 0x2, 0x2, 0x16d, 0x16e, 0x5, 0x32, 0x1a, 0x2, 
    0x16e, 0x16f, 0x8, 0x1a, 0x1, 0x2, 0x16f, 0x171, 0x3, 0x2, 0x2, 0x2, 
    0x170, 0x167, 0x3, 0x2, 0x2, 0x2, 0x170, 0x16a, 0x3, 0x2, 0x2, 0x2, 
    0x171, 0x33, 0x3, 0x2, 0x2, 0x2, 0x172, 0x173, 0x5, 0x38, 0x1d, 0x2, 
    0x173, 0x174, 0x8, 0x1b, 0x1, 0x2, 0x174, 0x177, 0x3, 0x2, 0x2, 0x2, 
    0x175, 0x177, 0x3, 0x2, 0x2, 0x2, 0x176, 0x172, 0x3, 0x2, 0x2, 0x2, 
    0x176, 0x175, 0x3, 0x2, 0x2, 0x2, 0x177, 0x35, 0x3, 0x2, 0x2, 0x2, 0x178, 
    0x179, 0x5, 0x28, 0x15, 0x2, 0x179, 0x17a, 0x8, 0x1c, 0x1, 0x2, 0x17a, 
    0x37, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x17c, 0x5, 0x36, 0x1c, 0x2, 0x17c, 
    0x17d, 0x8, 0x1d, 0x1, 0x2, 0x17d, 0x185, 0x3, 0x2, 0x2, 0x2, 0x17e, 
    0x17f, 0x5, 0x36, 0x1c, 0x2, 0x17f, 0x180, 0x8, 0x1d, 0x1, 0x2, 0x180, 
    0x181, 0x7, 0x22, 0x2, 0x2, 0x181, 0x182, 0x5, 0x38, 0x1d, 0x2, 0x182, 
    0x183, 0x8, 0x1d, 0x1, 0x2, 0x183, 0x185, 0x3, 0x2, 0x2, 0x2, 0x184, 
    0x17b, 0x3, 0x2, 0x2, 0x2, 0x184, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x185, 
    0x39, 0x3, 0x2, 0x2, 0x2, 0x186, 0x187, 0x7, 0x24, 0x2, 0x2, 0x187, 
    0x188, 0x8, 0x1e, 0x1, 0x2, 0x188, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x189, 
    0x18a, 0x7, 0x24, 0x2, 0x2, 0x18a, 0x18b, 0x8, 0x1f, 0x1, 0x2, 0x18b, 
    0x3d, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x18d, 0x7, 0x24, 0x2, 0x2, 0x18d, 
    0x18e, 0x8, 0x20, 0x1, 0x2, 0x18e, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x18f, 
    0x190, 0x7, 0x25, 0x2, 0x2, 0x190, 0x195, 0x8, 0x21, 0x1, 0x2, 0x191, 
    0x192, 0x7, 0x15, 0x2, 0x2, 0x192, 0x193, 0x7, 0x25, 0x2, 0x2, 0x193, 
    0x195, 0x8, 0x21, 0x1, 0x2, 0x194, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x194, 
    0x191, 0x3, 0x2, 0x2, 0x2, 0x195, 0x41, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x46, 
    0x4d, 0x61, 0x6b, 0x7a, 0x98, 0x9f, 0xa7, 0xb3, 0xb5, 0xbd, 0xd5, 0xed, 
    0xfe, 0x113, 0x129, 0x12b, 0x13a, 0x146, 0x148, 0x154, 0x15a, 0x165, 
    0x170, 0x176, 0x184, 0x194, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

smallCParser::Initializer smallCParser::_init;
