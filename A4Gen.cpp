//
//  A3Sema.cpp
//  ECE467 Lab 4
//
//  Created by Tarek Abdelrahman on 2023-07-31.
//  Modified by Tarek Abdelrahman on 2023-09-27.
//  Copyright © 2023 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE467 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include "antlr4-runtime.h"
#include "smallCLexer.h"
#include "smallCParser.h"
#include "ASTVisitorBase.h"
#include "SemanticAnalyzer.h"
#include "IRGen.h"

#include "llvm/Support/Host.h"
#include "llvm/Bitcode/BitcodeWriter.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Target/TargetOptions.h"

using namespace antlrcpp;
using namespace antlr4;
using namespace std;
using namespace smallc;
using namespace llvm;

int main(int argc, const char *argv[]) {
    // Check for the number of arguments
    if (argc != 2) {
	    cerr << "Usage: " << argv[0] << " filename" << std::endl;
	    return -1;
    }

    // Input stream handler
    ifstream inputStream;

    // The input file must have a .sc extension
    string argName (argv[1]);
    string fileName = argName;
    string extName;
    for (int i = argName.size()-1; i >=0; --i) {
        if (argName[i] == '.') {
            extName = argName.substr(i+1,argName.size()-1);
            fileName = argName.substr(0,i);
            break;
        }
    }
    
    if (fileName == "") {
        cerr << "fatal: invalid file name \"" << fileName << "\" in " << argv[1] << std::endl;
        return -1;
    }
    
    if (extName != "sc") {
        cerr << "fatal: invalid file extension \"" << extName << "\" in " << argv[1] << std::endl;
        return -1;
    }
    
    // Open the input file
    inputStream.open(argv[1]);
    if (!inputStream) {
        cerr << "fatal: " << argv[1] << " not found or cannot be opened" << std::endl;
        return -1;
    }

    // Create the input stream to the lexer
    ANTLRInputStream input(inputStream);
   
    // Create a lexer which scans the input stream
    // to create a token stream.
    smallCLexer* lexer = new smallCLexer(&input);
    CommonTokenStream tokens(lexer);

    // Get the tokens
    tokens.fill();

    // Uncomment these lines to see the tokens printed out
    // cout << "Tokens:" << endl;
    // for (Token *token : tokens.getTokens()) 
        // std::cout << token->toString() << std::endl;

    // Create a parser 
    smallCParser* parser = new smallCParser(&tokens);

    // Invoke the parser and get the root of the AST, i.e., the ProgramNode
    ProgramNode* prg = parser->program()->prg;

    // Create a semantic analyzer object
    SemanticAnalyzer* sema = new SemanticAnalyzer();
   
    // Check there there are no parse errors
    if (parser->getNumberOfSyntaxErrors() != 0) return -1;
    
    // Start semantic analysis by visiting the program node
    sema->visitProgramNode(prg);
    
    // Check if there are error messages and print them
    if (!sema->success()) {
        sema->printErrorMsgs();
        return -1;
    }
    
    // Lab 4. 
    // Generate the code in file with extension .bc
    IRGen IR(fileName+".bc");
    
    IR.visitProgramNode(prg);
    
    std::unique_ptr<llvm::Module> m = IR.getModule();
    auto TargetTriple = llvm::sys::getDefaultTargetTriple();
    m->setTargetTriple(TargetTriple);
    
    std::error_code EC;
    if (!llvm::verifyModule(*m, &llvm::errs())) {
        // emit bytecode
        llvm::raw_fd_ostream OS(fileName+".bc", EC);
        llvm::WriteBitcodeToFile(*m, OS);
        OS.flush();
    } else {
        cerr << "fatal: the generated IR is malformed!" << endl;
        return -1;
    }
    
    return 0;
}

