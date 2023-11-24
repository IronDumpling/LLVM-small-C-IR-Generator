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

// variable is array or not
bool
IRGen::varIsArray(){

}

void
IRGen::createFuncProto(string name, FunctionEntry func){
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
    F = llvm::Function::Create(func_type, llvm::Function::ExternalLinkage, name, *(this->TheModule));

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

// TerminatorInst: Terminator of the basic block
// TerminatorInst has successor basic blocks
    // Subclass 1: ReturnInst
    // It doesn't have successor Basic Blocks, because the fuction is done
    // Subclass 2: BranchInst
    // None conditional BranchInsts have one successor BasicBlock. 
    // Always jump to the other block
    // Conditional BranchInsts have two successor BasicBlock. 
    // The BranchInst have one argument: a codition. 
    // True to go to the first successor. False to go to the second.
// Generate the BB flow diagram by: opt -dot-cfg bitcode.bc

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

    auto funcs = *(prg->getFuncTable()->getTable());
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
    llvm::BasicBlock * entry = llvm::BasicBlock::Create(*(this->TheContext), "entry", F, 0);
    this->Builder->SetInsertPoint(entry);

    cout << "declare fuction " << name << "\n";

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

        this->findTable(param->getIdent())->setLLVMValue(name, alloca);

        cout << "declare parameter " << name << "\n";
    }

    cout << "finish declare parameters of " << name << "\n"; 

    if (func->getBody())
        func->getBody()->visit(this);

    cout << "finish visiting scope of " << name << "\n";

    assert(this->Builder->GetInsertBlock() != nullptr);
    llvm::Instruction * lastInst = this->Builder->GetInsertBlock()->getTerminator();
    if(func->getRetType()->getTypeEnum() == TypeNode::Void && 
    (!lastInst || !llvm::isa<llvm::ReturnInst>(lastInst))){
        this->Builder->CreateRetVoid();
        cout << "add the missing return void\n";
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
    llvm::ArrayType * array_type = llvm::ArrayType::get(type, size);
    
    assert(array_type != nullptr);

    // 1. global variable
    if(array->isGlobal()){
        llvm::GlobalVariable * var = new llvm::GlobalVariable(
            *(this->TheModule), array_type, false, 
            llvm::GlobalValue::ExternalLinkage, nullptr, name
        );
        this->findTable(array->getIdent())->setLLVMValue(name, var);
    }
    // 2. local variable
    else{
        llvm::Value * var = this->Builder->CreateAlloca(
            array_type, nullptr, name
        );
        this->findTable(array->getIdent())->setLLVMValue(name, var);
        cout << "local array: " << name << "\n";
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
            llvm::GlobalValue::ExternalLinkage, nullptr, name
        );
        this->findTable(scalar->getIdent())->setLLVMValue(name, var);
    }
    // 2. local variable
    else{
        llvm::Value * var = this->Builder->CreateAlloca(
            type, nullptr, name
        );
        this->findTable(scalar->getIdent())->setLLVMValue(name, var);
        cout << "local scalar: " << name << "\n";
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

    // create the expression based on the operation
    // the right-hand side operands
    // ps: no need to perform short-circuiting for boolean expr

    ASTVisitorBase::visitUnaryExprNode(unary);
}

void 
IRGen::visitBinaryExprNode(BinaryExprNode* bin) {
    bin->getLeft()->visit(this);
    bin->getRight()->visit(this);

    // create the expression based on the operation
    // the left-hand / right-hand side operands
    // ps: no need to perform short-circuiting for boolean expr

    ASTVisitorBase::visitBinaryExprNode(bin);
}

void
IRGen::visitIntExprNode(IntExprNode* intExpr) {
    intExpr->getValue()->visit(this);

    ASTVisitorBase::visitIntExprNode(intExpr);
}

void 
IRGen::visitBoolExprNode (BoolExprNode* boolExpr) {
    boolExpr->getValue()->visit(this);

    ASTVisitorBase::visitBoolExprNode(boolExpr);
}

void
IRGen::visitCallExprNode (CallExprNode* call) {
    call->getIdent()->visit(this);
    for (auto i: call->getArguments())
        i->visit(this);

    // create the call instruction using CreateCall
    // make sure the arguments are in a vector
        // 1. reference arguments
            // 1.1 array
            // 1.2 scalar
        // 2. expression arguments
            // 2.1 array
            // 2.2 scalar
    ASTVisitorBase::visitCallExprNode(call);
}

void 
IRGen::visitConstantExprNode(ConstantExprNode* constant) {
    // create the constant using the appropriate llvm::Constant get method
    // insert into the expr
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
IRGen::visitReferenceExprNode(ReferenceExprNode* ref) {
    ref->getIdent()->visit(this);
    if (ref->getIndex())
        ref->getIndex()->visit(this);

    auto table = this->findTable(ref->getIdent());
    
    assert(table != nullptr);
    VariableEntry val_entry = table->get(ref->getIdent()->getName());
    TypeNode * type = val_entry.getType();
    llvm::Value * val = val_entry.getValue();

    // 1. scalar
    if(!type->isArray()){
        llvm::Type * value_type = this->convertType(type);
        cout << "scalar value type\n";
        // llvm::LoadInst * loadInst = this->Builder->CreateLoad(
            // value_type, val, ref->getIdent()->getName()
        // );
        cout << "scalar load instruction\n";
    } else {
        // 2. array without index

        // 3. array with index
        
        // 4. pointer
        // Use the GEP instruction
    }

    ASTVisitorBase::visitReferenceExprNode(ref);
}

void 
IRGen::visitIdentifierNode(IdentifierNode* id) {
    ASTVisitorBase::visitIdentifierNode(id);
}

void 
IRGen::visitArgumentNode(ArgumentNode* arg) {
    ASTVisitorBase::visitArgumentNode(arg);
}

void
IRGen::visitParameterNode(ParameterNode* param) {
    ASTVisitorBase::visitParameterNode(param);
    param->getType()->visit(this);
    param->getIdent()->visit(this);
}

void 
IRGen::visitStmtNode(StmtNode* stmt) {
    ASTVisitorBase::visitStmtNode(stmt);
}

void 
IRGen::visitAssignStmtNode(AssignStmtNode* assign) {
    assign->getTarget()->visit(this);
    assign->getValue()->visit(this);

    // create a store (write to memory) for the target of the assignment using CreateStore
    // 1. scalar
    
    // 2. array
    // Use the GEP instruction

    ASTVisitorBase::visitAssignStmtNode(assign);
}

void 
IRGen::visitExprStmtNode(ExprStmtNode* expr) {
    expr->getExpr()->visit(this);

    ASTVisitorBase::visitExprStmtNode(expr);
}

void 
IRGen::visitIfStmtNode(IfStmtNode* ifStmt) {
    // create the basic blocks for the condition 
    // the then clause
    if(ifStmt->getThen()){

    }
    // the else clause
    if(ifStmt->getElse()){

    }
    // add the exit block
    ASTVisitorBase::visitIfStmtNode(ifStmt);

    ifStmt->getCondition()->visit(this);
    ifStmt->getThen()->visit(this);
    if (ifStmt->getHasElse())
        ifStmt->getElse()->visit(this);
}

void 
IRGen::visitReturnStmtNode(ReturnStmtNode* ret) {
    if(ret->returnVoid()){
        this->Builder->CreateRetVoid();
        cout << "return void\n";
    }else{
        ExprNode * expr = ret->getReturn();
        expr->visit(this);
        llvm::Type * type = this->convertType(expr->getType());
        llvm::ReturnInst* retInst = nullptr;
        if (type->isIntegerTy(32)) {
            retInst = this->Builder->CreateRet(expr->getLLVMValue());
            cout << "return int\n";
        } else if (type->isIntegerTy(1)) {
            llvm::Type* int32Type = llvm::Type::getInt32Ty(*(this->TheContext));
            llvm::Value* int32Value = this->Builder->CreateZExtOrTrunc(expr->getLLVMValue(), int32Type);
            retInst = this->Builder->CreateRet(int32Value);
            cout << "return bool\n";
        }
    }
    ASTVisitorBase::visitReturnStmtNode(ret);
}

void 
IRGen::visitScopeNode(ScopeNode* scope) {
    for (auto i: scope->getDeclarations())
        i->visit(this);

    ASTVisitorBase::visitScopeNode(scope);
}

void 
IRGen::visitWhileStmtNode(WhileStmtNode* whileStmt) {
    whileStmt->getCondition()->visit(this);
    whileStmt->getBody()->visit(this);

    // create the basic blocks for the condition of the loop
    if(whileStmt->getCondition()){

    }
    // basic block for the body
    if(whileStmt->getBody()){

    }
    // add basic block for its exit

    ASTVisitorBase::visitWhileStmtNode(whileStmt);
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
