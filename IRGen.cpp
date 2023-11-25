//
//  IRGen.cpp
//  ECE467 Lab 4
//
//  Created by Tarek Abdelrahman on 2023-10-13.
//  Based on code written by Ao (Dino) Li for ECE467.
//  Copyright © 2023 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE467 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

#include <iostream>
using namespace std;

#include "IRGen.h"
#include "SymTable.h"
#include "ASTVisitorBase.h"
using namespace smallc;
using namespace llvm;

namespace smallc {

IRGen::IRGen(const std::string moduleName) : ASTVisitorBase(),
                                             prog(nullptr),
                                             TheModule(),
                                             Builder(),
                                             ModuleName(moduleName) {
    TheContext = std::make_unique<llvm::LLVMContext>();
}

unique_ptr<Module> 
IRGen::getModule() {
    Builder.reset();
    return std::move(TheModule);
}

llvm::Type*
IRGen::convertType(TypeNode* type){
    llvm::Type* base;
    switch(type->getTypeEnum()){
        case TypeNode::TypeEnum::Void:
            base = llvm::Type::getVoidTy(*TheContext);
            break;
        case TypeNode::TypeEnum::Int:
            base = llvm::Type::getInt32Ty(*TheContext);
            break;
        case TypeNode::TypeEnum::Bool:
            base = llvm::Type::getInt1Ty(*TheContext);
            break;
    }
    if(type->isArray()){
        ArrayTypeNode* arrType = (ArrayTypeNode*) type;
	if(arrType->getSize() == 0) return llvm::PointerType::get(base, 0);
        return llvm::ArrayType::get(base, arrType->getSize());
    }
    return base;
}

SymTable<VariableEntry>*
IRGen::findTable(IdentifierNode* id){
    ASTNode* parent = id->getParent();
    bool found = false;
    SymTable<VariableEntry>* res = nullptr;
    while (parent && !found){
        if (parent->hasVarTable()){
            if (parent->getParent()){
                ScopeNode* scope = (ScopeNode*)parent;
                res = scope->getVarTable();
            } else {
                res = id->getRoot()->getVarTable();
            }
            if (res && res->contains(id->getName()))
                found = true;
        }
        parent = parent->getParent();
    }
    return res;
}

/* Helper Functions */

llvm::Type * 
IRGen::arrayToPrimitiveType(TypeNode * array){
    PrimitiveTypeNode * primitive = new PrimitiveTypeNode(array->getTypeEnum());
    return this->convertType(primitive);
}

void
IRGen::createFuncProto(string name, FunctionEntry & func){
    // try to get function from module
    llvm::Function * F = this->TheModule->getFunction(name);
    // 1. exists
    if(F != nullptr) return;
        
    // 2. not exists
    // return type 
    llvm::Type * ret_type = this->convertType(func.getReturnType());
        
    // parameters
    vector<llvm::Type *> param_types;
    for(int i = 0; i < func.getParameterTypes().size(); i++){
        TypeNode * type = func.getParameterTypes()[i];
        llvm::Type * T = this->convertType(type);
        param_types.push_back(T);
    }
        
    // function signature
    llvm::FunctionType * func_type = llvm::FunctionType::get(ret_type, param_types, false);
    F = llvm::Function::Create(
        func_type, llvm::Function::ExternalLinkage, name, *(this->TheModule)
    );

    assert(F != nullptr);
    
    // add zeroext attribute to bool parameters
    llvm::Argument * arg;
    for(unsigned int i = 0; i < F->arg_size(); i++){
        arg = &*(F->arg_begin() + i);
        if(arg->getType()->isIntegerTy(1)){
            arg->addAttr(llvm::Attribute::ZExt);
        }
    }
}

/* ECE467 STUDENT: complete the implementation of the visitor functions */

void
IRGen::visitASTNode (ASTNode* node) {
    ASTVisitorBase::visitASTNode(node);
}

void
IRGen::visitProgramNode(ProgramNode* prg) {
    // create a context
    this->TheContext = std::make_unique<llvm::LLVMContext>();
    // create a module
    this->TheModule = std::make_unique<llvm::Module>(this->ModuleName, *(this->TheContext));
    // create the IRBuilder object 
    // used to insert global symbols into module in ArrayDecl and ScalarDecl
    this->Builder = std::make_unique<llvm::IRBuilder<>>(*(this->TheContext));

    this->prog = prg;
    assert(this->prog != nullptr);

    auto funcs = *(this->prog->getFuncTable()->getTable());
    for(auto pair : funcs){
        string name = pair.first;
        auto func = pair.second;
        this->createFuncProto(name, func);
    }

    ASTVisitorBase::visitProgramNode(prg);
}

void 
IRGen::visitDeclNode (DeclNode* decl) {
    ASTVisitorBase::visitDeclNode(decl);
}

void
IRGen::visitFunctionDeclNode (FunctionDeclNode* func) {
    func->getRetType()->visit(this);
    func->getIdent()->visit(this);

    for (auto i: func->getParams())
        i->visit(this);

    // try to get function from module
    string name = func->getIdent()->getName();
    llvm::Function * F = this->TheModule->getFunction(name);
    
    assert(F != nullptr);

    // 1. function prototype
    if(func->getProto()) return;

    // 2. function declaration
    llvm::BasicBlock * entry = llvm::BasicBlock::Create(
        *(this->TheContext), "entry", F
    );
    this->Builder->SetInsertPoint(entry);

    // cout << "declare fuction " << name << "\n";

    // declare parameters
    for(int i = 0; i < func->getNumParameters(); i++){
        auto param = func->getParams()[i];
        std::string name = param->getIdent()->getName();
        
        TypeNode * type = param->getType();
        llvm::Type * T = this->convertType(type);
        llvm::Argument * arg = F->getArg(i);
        arg->setName(name);
        
        llvm::Value * alloca = this->Builder->CreateAlloca(T, nullptr, name);
        this->Builder->CreateStore(arg, alloca); // store the argument value to a pointer

        func->getBody()->getVarTable()->setLLVMValue(name, alloca);
    }

    this->currFunctionName = name;

    if (func->getBody())
        func->getBody()->visit(this);

    // cout << "finish visiting the scope of " << name << "\n";

    assert(this->Builder->GetInsertBlock() != nullptr);

    llvm::Instruction * lastInst = this->Builder->GetInsertBlock()->getTerminator();
    if(func->getRetType()->getTypeEnum() == TypeNode::Void && 
    (!lastInst || !llvm::isa<llvm::ReturnInst>(lastInst))){
        this->Builder->CreateRetVoid();
    }
    
    ASTVisitorBase::visitFunctionDeclNode(func);
}

void
IRGen::visitArrayDeclNode (ArrayDeclNode* array) {    
    array->getType()->visit(this);
    array->getIdent()->visit(this);

    int size = array->getType()->getSize();
    string name = array->getIdent()->getName();
    llvm::Type * type = this->convertType(array->getType());
    
    assert(type != nullptr);

    // 1. global variable
    if(array->isGlobal()){
        llvm::GlobalVariable * var = new llvm::GlobalVariable(
            *(this->TheModule), type, false, 
            llvm::GlobalValue::CommonLinkage, 
            llvm::ConstantAggregateZero::get(type), name
        );
        this->findTable(array->getIdent())->setLLVMValue(name, var);
    }
    // 2. local variable
    else{
        llvm::Value * var = this->Builder->CreateAlloca(
            type, nullptr, name
        );
        this->findTable(array->getIdent())->setLLVMValue(name, var);
        // cout << array->getLine() << ": local array: " << name << "\n";
    }    

    ASTVisitorBase::visitArrayDeclNode(array);
}

void
IRGen::visitScalarDeclNode (ScalarDeclNode* scalar) {
    scalar->getType()->visit(this);
    scalar->getIdent()->visit(this);
    
    llvm::Type * type = this->convertType(scalar->getType());
    string name = scalar->getIdent()->getName();

    assert(type != nullptr);

    // 1. global variable
    if(scalar->isGlobal()){
        llvm::GlobalVariable * var = new llvm::GlobalVariable(
            *(this->TheModule), type, false, 
            llvm::GlobalValue::CommonLinkage, 
            llvm::ConstantInt::get(type, 0), name
        );
        this->findTable(scalar->getIdent())->setLLVMValue(name, var);
    }
    // 2. local variable
    else{
        llvm::Value * var = this->Builder->CreateAlloca(
            type, nullptr, name
        );
        this->findTable(scalar->getIdent())->setLLVMValue(name, var);
        // cout << scalar->getLine() << ": local scalar: " << name << "\n";
    }
    
    ASTVisitorBase::visitScalarDeclNode(scalar);
}

void 
IRGen::visitExprNode (ExprNode* exp) {
    ASTVisitorBase::visitExprNode(exp);
}

void 
IRGen::visitUnaryExprNode(UnaryExprNode* unary) {
    unary->getOperand()->visit(this);

    string op = ExprNode::codeToStr(unary->getOpcode());
    llvm::Value * left = unary->getOperand()->getLLVMValue();
    llvm::Value * operation;

    if(op == "!"){
        operation = this->Builder->CreateICmpEQ(left, this->Builder->getInt1(0));
    }else if(op == "-"){
        operation = this->Builder->CreateNeg(left);
    }

    unary->setLLVMValue(operation);

    ASTVisitorBase::visitUnaryExprNode(unary);
}

void 
IRGen::visitBinaryExprNode(BinaryExprNode* bin) {
    // cout << bin->getLine() << ": left operand\n";
    bin->getLeft()->visit(this);
    // cout << bin->getLine() << ": right operand\n";
    bin->getRight()->visit(this);

    string op = ExprNode::codeToStr(bin->getOpcode());
    llvm::Value * left = bin->getLeft()->getLLVMValue();
    llvm::Value * right = bin->getRight()->getLLVMValue();
    llvm::Value * operation;

    // 1. Arithmetic Operations
    if(op == "+"){
        operation = this->Builder->CreateAdd(left, right);
    }else if (op == "-"){
        operation = this->Builder->CreateSub(left, right);
    }else if (op == "*"){
        operation = this->Builder->CreateMul(left, right);
    }else if (op == "/"){
        operation = this->Builder->CreateSDiv(left, right);
    }
    // 2. Comparison Operations
    else if (op == "&&"){
        operation = this->Builder->CreateAnd(left, right);
    }else if (op == "||"){
        operation = this->Builder->CreateOr(left, right);
    }else if (op == "=="){
        operation = this->Builder->CreateICmpEQ(left, right);
    }else if (op == "!="){
        operation = this->Builder->CreateICmpNE(left, right);
    }else if (op == "<"){
        operation = this->Builder->CreateICmpSLT(left, right);
    }else if (op == "<="){
        operation = this->Builder->CreateICmpSLE(left, right);
    }else if (op == ">"){
        operation = this->Builder->CreateICmpSGT(left, right);
    }else if (op == ">="){
        operation = this->Builder->CreateICmpSGE(left, right);
    }

    bin->setLLVMValue(operation);

    ASTVisitorBase::visitBinaryExprNode(bin);
}

void
IRGen::visitIntExprNode(IntExprNode* intExpr) {
    intExpr->getValue()->visit(this);
    intExpr->setLLVMValue(intExpr->getValue()->getLLVMValue());
    ASTVisitorBase::visitIntExprNode(intExpr);
}

void 
IRGen::visitBoolExprNode(BoolExprNode* boolExpr) {
    boolExpr->getValue()->visit(this);
    boolExpr->setLLVMValue(boolExpr->getValue()->getLLVMValue());
    ASTVisitorBase::visitBoolExprNode(boolExpr);
}

void
IRGen::visitCallExprNode (CallExprNode* call) {
    
    call->getIdent()->visit(this);

    string name = call->getIdent()->getName();
    
    llvm::Function * func = this->TheModule->getFunction(name);
    assert(func != nullptr);
    FunctionType * type = func->getFunctionType();
    assert(type != nullptr);

    std::vector<llvm::Value*> arg_values;
    for (ArgumentNode * arg: call->getArguments()){
        arg->visit(this);
        arg_values.push_back(arg->getExpr()->getLLVMValue());
    }

    CallInst * callInst = this->Builder->CreateCall(
        type, func, arg_values
    );

    call->setLLVMValue(callInst);

    // cout << call->getLine() << ": function call " << name << "\n";

    ASTVisitorBase::visitCallExprNode(call);
}

void 
IRGen::visitArgumentNode(ArgumentNode* arg) {
    arg->getExpr()->visit(this);
    ASTVisitorBase::visitArgumentNode(arg);
}

void
IRGen::visitParameterNode(ParameterNode* param) {
    param->getType()->visit(this);
    param->getIdent()->visit(this);
    ASTVisitorBase::visitParameterNode(param);
}

void 
IRGen::visitConstantExprNode(ConstantExprNode* constant) {
   ASTVisitorBase::visitConstantExprNode(constant);
}

void 
IRGen::visitBoolConstantNode(BoolConstantNode* boolConst) {
    llvm::Constant * cst = this->Builder->getInt1(boolConst->getVal());
    boolConst->setLLVMValue(cst);
    ASTVisitorBase::visitBoolConstantNode(boolConst);
}

void 
IRGen::visitIntConstantNode(IntConstantNode* intConst) {
    llvm::Constant * cst = this->Builder->getInt32(intConst->getVal());
    intConst->setLLVMValue(cst);
    ASTVisitorBase::visitIntConstantNode(intConst);
}

void 
IRGen::createVarInst(ReferenceExprNode* ref, bool isValue){
    ref->getIdent()->visit(this);        

    auto table = this->findTable(ref->getIdent());
    
    assert(table != nullptr);

    VariableEntry val_entry = table->get(ref->getIdent()->getName());
    TypeNode * type = val_entry.getType();
    llvm::Type * value_type = this->convertType(type);
    llvm::Value * val = val_entry.getValue();

    assert(type != nullptr);
    assert(val != nullptr);

    // 1. scalar
    if(!type->isArray()){
        if(isValue){
            llvm::LoadInst * loadInst = this->Builder->CreateLoad(value_type, val);
            ref->setLLVMValue(loadInst);
        }else{
            ref->setLLVMValue(val);
        }
    }
    // 2. array no size with index
    else if(ref->getIndex() && value_type->isPointerTy()){
        ref->getIndex()->visit(this);

        // %0 = load ptr, ptr %a2
        llvm::LoadInst * loadInst = this->Builder->CreateLoad(value_type, val);
        // %1 = getelementptr i32/i1, ptr %0, i32/i1 idx
        llvm::ArrayRef<llvm::Value *> indicies = {
            ref->getIndex()->getLLVMValue()
        };
        llvm::Value * gepInst = this->Builder->CreateGEP(
            this->arrayToPrimitiveType(type), loadInst, indicies
        );
        
        if(isValue){
            loadInst = this->Builder->CreateLoad(
                this->arrayToPrimitiveType(type), gepInst
            ); 
            ref->setLLVMValue(loadInst);
        }else{
            ref->setLLVMValue(gepInst);
        }
    }
    // 3. array has size with index
    else if(ref->getIndex() && !value_type->isPointerTy()){
        ref->getIndex()->visit(this);
        
        llvm::ArrayRef<llvm::Value *> indicies = {
            llvm::ConstantInt::get(llvm::Type::getInt32Ty(*TheContext), 0),
            ref->getIndex()->getLLVMValue()
        };
        llvm::Value * gepInst = this->Builder->CreateGEP(value_type, val, indicies);
        
        if(isValue){
            llvm::LoadInst * loadInst = this->Builder->CreateLoad(
                this->arrayToPrimitiveType(type), gepInst
            ); 
            ref->setLLVMValue(loadInst);
        }else{
            ref->setLLVMValue(gepInst);
        }
    } 
    // 4. array no size without index
    else if(!ref->getIndex() && value_type->isPointerTy()){
        // %0 = load ptr, ptr %a2, align 8
        llvm::LoadInst * loadInst = this->Builder->CreateLoad(value_type, val);
        ref->setLLVMValue(loadInst);
    }
    // 5. array has size without index
    else if(!ref->getIndex() && !value_type->isPointerTy()) {
        // %0 = getelementptr [size * i32/i1], ptr %d, i32/i1 0, i32/i1 0
        llvm::ArrayRef<llvm::Value *> indicies = {
            llvm::ConstantInt::get(llvm::Type::getInt32Ty(*TheContext), 0),
            llvm::ConstantInt::get(llvm::Type::getInt32Ty(*TheContext), 0)
        };
        llvm::Value * gepInst = this->Builder->CreateGEP(value_type, val, indicies);
        ref->setLLVMValue(gepInst);
    }

    ASTVisitorBase::visitReferenceExprNode(ref);
}

void
IRGen::visitReferenceExprNode(ReferenceExprNode* ref) {
    this->createVarInst(ref, true);
}

void 
IRGen::visitIdentifierNode(IdentifierNode* id) {
    ASTVisitorBase::visitIdentifierNode(id);
}

void 
IRGen::visitStmtNode(StmtNode* stmt) {
    ASTVisitorBase::visitStmtNode(stmt);
}

void 
IRGen::visitAssignStmtNode(AssignStmtNode* assign) {
    assign->getValue()->visit(this);
    this->createVarInst(assign->getTarget(), false);

    llvm::Value * val = assign->getValue()->getLLVMValue();
    llvm::Value * target = assign->getTarget()->getLLVMValue();

    this->Builder->CreateStore(val, target);
    
    // TODO: it works?    
    // array Use the GEP instruction

    ASTVisitorBase::visitAssignStmtNode(assign);
}

void 
IRGen::visitExprStmtNode(ExprStmtNode* expr) {
    expr->getExpr()->visit(this);
    ASTVisitorBase::visitExprStmtNode(expr);
}

void 
IRGen::visitReturnStmtNode(ReturnStmtNode* ret) {
    if(ret->returnVoid()){
        this->Builder->CreateRetVoid();
    }else{
        ExprNode * expr = ret->getReturn();
        expr->visit(this);
        llvm::Type * type = this->convertType(expr->getType());
        llvm::ReturnInst* retInst = nullptr;
        retInst = this->Builder->CreateRet(expr->getLLVMValue());
    }
    ASTVisitorBase::visitReturnStmtNode(ret);
}

// Generate the BB flow diagram by: opt -dot-cfg bitcode.bc
void 
IRGen::visitIfStmtNode(IfStmtNode* ifStmt) {
    llvm::Function * func = this->TheModule->getFunction(this->currFunctionName);

    llvm::BasicBlock * then = llvm::BasicBlock::Create(
        *(this->TheContext), "if.then", func
    );
    llvm::BasicBlock * els;
    llvm::BasicBlock * exit = llvm::BasicBlock::Create(
        *(this->TheContext), "if.merge", func
    );
    
    ifStmt->getCondition()->visit(this);
    llvm::Value * cond = ifStmt->getCondition()->getLLVMValue();

    if(ifStmt->getElse()){
        els = llvm::BasicBlock::Create(
            *(this->TheContext), "if.else", func
        );
        this->Builder->CreateCondBr(cond, then, els);
    }else{
        this->Builder->CreateCondBr(cond, then, exit);
    }

    // then clause
    if(ifStmt->getThen()){
        this->Builder->SetInsertPoint(then);
        ifStmt->getThen()->visit(this);
        llvm::Instruction * lastInst = this->Builder->GetInsertBlock()->getTerminator();
        if(!lastInst || !llvm::isa<llvm::ReturnInst>(lastInst)){
            this->Builder->CreateBr(exit);
        }
    }
    // else clause
    if(ifStmt->getElse()){
        this->Builder->SetInsertPoint(els);
        ifStmt->getElse()->visit(this);
        llvm::Instruction * lastInst = this->Builder->GetInsertBlock()->getTerminator();
        if(!lastInst || !llvm::isa<llvm::ReturnInst>(lastInst)){
            this->Builder->CreateBr(exit);
        }
    }

    this->Builder->SetInsertPoint(exit);

    ASTVisitorBase::visitIfStmtNode(ifStmt);
}

void 
IRGen::visitWhileStmtNode(WhileStmtNode* whileStmt) {
    llvm::Function * func = this->TheModule->getFunction(this->currFunctionName);

    assert(whileStmt->getCondition() != nullptr);
    assert(whileStmt->getBody() != nullptr);

    llvm::BasicBlock * cond = llvm::BasicBlock::Create(
        *(this->TheContext), "while.condition", func
    );
    llvm::BasicBlock * loop = llvm::BasicBlock::Create(
        *(this->TheContext), "while.body", func
    );
    llvm::BasicBlock * exit = llvm::BasicBlock::Create(
        *(this->TheContext), "while.exit", func
    );

    this->Builder->CreateBr(cond);

    this->Builder->SetInsertPoint(cond);
    whileStmt->getCondition()->visit(this);
    llvm::Value * condition = whileStmt->getCondition()->getLLVMValue();
    this->Builder->CreateCondBr(condition, loop, exit);

    this->Builder->SetInsertPoint(loop);
    whileStmt->getBody()->visit(this);
    llvm::Instruction * lastInst = this->Builder->GetInsertBlock()->getTerminator();
    if(!lastInst || !llvm::isa<llvm::ReturnInst>(lastInst)){
        this->Builder->CreateBr(cond);
    }

    this->Builder->SetInsertPoint(exit);

    ASTVisitorBase::visitWhileStmtNode(whileStmt);
}

void 
IRGen::visitScopeNode(ScopeNode* scope) {
    for (auto i: scope->getDeclarations())
        i->visit(this);

    ASTVisitorBase::visitScopeNode(scope);
}

void 
IRGen::visitTypeNode(TypeNode* type) {
   ASTVisitorBase::visitTypeNode(type);
}

void 
IRGen::visitPrimitiveTypeNode(PrimitiveTypeNode* type) {
    ASTVisitorBase::visitPrimitiveTypeNode(type);
}

void 
IRGen::visitArrayTypeNode(ArrayTypeNode* type) {
    ASTVisitorBase::visitArrayTypeNode(type);
}

} // namespace smallc
