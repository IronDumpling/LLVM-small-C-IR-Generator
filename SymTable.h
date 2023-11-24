//
//  SymTable.h
//  ECE467 Lab 4
//
//  Created by Tarek Abdelrahman on 2023-10-13.
//  Based on code written by Ao (Dino) Li for ECE467.
//  Copyright © 2023 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE467 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

#ifndef SYMTABLE_H
#define SYMTABLE_H

#include "ASTNodes.h"
#include <map>
#include <string>
#include "llvm/IR/Value.h"

namespace smallc {

// Symbol table class
template<class T>
class SymTable {
private:
    std::map<std::string, T> table;
public:
    bool contains(const std::string &name);
    
    T get(const std::string &name);
    
    void insert(const std::string& name, T ent);
    
    void setLLVMValue(std::string name, llvm::Value* val);
    
    std::map<std::string, T>* getTable(); // Bad, it returns a pointer to the table
};

// A variable entry in the table
class VariableEntry {
private:
    TypeNode* type;
    bool isArray;
    llvm::Value* value;
    
public:
    VariableEntry();
    explicit VariableEntry(PrimitiveTypeNode* p);
    explicit VariableEntry(ArrayTypeNode* arr);
    TypeNode* getType();
    llvm::Value* getValue();
    friend class SymTable<VariableEntry>;
};

// A function entry in the table
class FunctionEntry {
public:
    PrimitiveTypeNode* returnType;
    std::vector<TypeNode*> parameterTypes;
    llvm::Value* value; 
    bool proto;
public:
    FunctionEntry();
    FunctionEntry(PrimitiveTypeNode* retType, std::vector<TypeNode*> paraTypes);
    PrimitiveTypeNode* getReturnType();
    std::vector<TypeNode*> getParameterTypes();
    friend class SymTable<FunctionEntry>;
};

} // namspace smallc
#endif //SYMTABLE_H

