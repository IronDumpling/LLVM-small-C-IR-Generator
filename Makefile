# Makefile 
# ECE467 Lab 4
#
#  Created by Tarek Abdelrahman on 2023-10-13.
#  Copyright © 2023 Tarek Abdelrahman. All rights reserved.
#
#  Permission is hereby granted to use this code in ECE467 at
#  the University of Toronto. It is prohibited to distribute
#  this code, either publicly or to third parties.

SHELL := /bin/bash

ANTLR_VER     = 4.7.2
ECE467_ROOT   = /cad2/ece467f
ANTLR_INC_DIR = $(ECE467_ROOT)/ANTLR-$(ANTLR_VER)/include/antlr4-runtime/
ANTLR_LIB_DIR = $(ECE467_ROOT)/ANTLR-$(ANTLR_VER)/lib
ANTLR_LIB     = -lantlr4-runtime

LLVM_ROOT     = /cad2/ece467f/llvm-project
LLVM_BLD_INC_DIR  = $(LLVM_ROOT)/build/include
LLVM_INC_DIR  = $(LLVM_ROOT)/llvm/include
LLVM_LIB_DIR  = $(LLVM_ROOT)/build/lib
LLVM_BIN_DIR  = $(LLVM_ROOT)/build/bin

LLVM_MODULES = support bitwriter core
LLVM_LIBS     = `$(LLVM_BIN_DIR)/llvm-config --libs --system-libs $(LLVM_MODULES)`

CC            = g++ 
CC_OPT        = -std=c++17 -w

ANTLR         = java -jar $(ECE467_ROOT)/ANTLR-$(ANTLR_VER)/antlr-$(ANTLR_VER)-complete.jar
ANTLR_OPTS    = -no-listener -visitor -Dlanguage=Cpp

TARGET        = smallC
EXE           = A4Gen

GEN_SRCS      = $(TARGET)Lexer.cpp $(TARGET)Parser.cpp $(TARGET)BaseVisitor.cpp \
                $(TARGET)Visitor.cpp 

GEN_OBJS      = $(patsubst %.cpp,%.o,$(GEN_SRCS))

GEN_INCS      = $(patsubst %.cpp,%.h,$(GEN_SRCS))

GEN_OTHR      = $(TARGET).interp $(TARGET).tokens $(TARGET)Lexer.interp $(TARGET)Lexer.tokens

SRCS          = $(EXE).cpp ASTVisitorBase.cpp IRGen.cpp
OBJS          = $(patsubst %.cpp,%.o,$(SRCS))
INCS          = $(patsubst %.cpp,%.h,$(SRCS))

OBJS_INC      = ASTNodes.o SymTable.o SemanticAnalyzer.o

$(EXE):	$(OBJS) $(GEN_OBJS)
	$(CC) $(CC_OPT) -I$(ANTLR_INC_DIR) -I$(LLVM_INC_DIR) -I$(LLVM_BLD_INC_DIR) \
                        -L$(ANTLR_LIB_DIR) -L$(LLVM_LIB_DIR) $(OBJS) $(OBJS_INC) \
	                $(GEN_OBJS) -o $(EXE) $(ANTLR_LIB) $(LLVM_LIBS)

$(OBJS):	%.o:	%.cpp $(GEN_INCS)
	$(CC) $(CC_OPT) -c -I$(ANTLR_INC_DIR) -I$(LLVM_INC_DIR) -I$(LLVM_BLD_INC_DIR) -o $@ $<
	
$(GEN_OBJS):	%.o:	%.cpp %.h
	$(CC) $(CC_OPT) -c -I$(ANTLR_INC_DIR) -I$(LLVM_INC_DIR) -I$(LLVM_BLD_INC_DIR) -o $@ $<

$(GEN_INCS):	$(TARGET).g4
	$(ANTLR) $(ANTLR_OPTS)  $(TARGET).g4

$(GEN_SRCS):	$(TARGET).g4
	$(ANTLR) $(ANTLR_OPTS)  $(TARGET).g4

depend:
	@makedepend -- $(CC_OPT) -I$(ANTLR_INC_DIR) -I$(LLVM_INC_DIR) -I$(LLVM_BLD_INC_DIR) -L$(ANTLR_LIB_DIR) -- \
		                               $(SRCS) $(GEN_SRCS) >& /dev/null

.PHONY: clean
clean:
	@rm -f $(GEN_SRCS) $(GEN_INCS) $(GEN_OBJS) $(GEN_OTHR) $(OBJS) $(EXE) Makefile.bak

