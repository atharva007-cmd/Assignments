#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>

using namespace std;

// Storing constants, basic and advance assembler directives, mnmonic opcodes
const vector<string> Registers = { "AREG", "BREG", "CREG", "DREG" };
const vector<string> AssemblerDirectives = { "DC", "DS" };
const vector<string> AdvancedAssemblerDirectives = { "START", "END", "ORIGIN", "EQU", "LTORG" };
const vector<string> Mnemonics = { "STOP", "ADD", "SUB", "MULT", "MOVER", "MOVEM", "COMP", "BC", "DIV", "READ", "PRINT" };

struct SymbolTableEntry {
	string symbol;
	int address;

	SymbolTableEntry (string symbol, int address)
		: symbol(symbol), address(address)
	{}
};

// To open the file
void openFile (ifstream&, string);

// Handle tokens
void handleTokens (ifstream&, vector<SymbolTableEntry>&);

// Check if token is literal
bool checkLiteral (string);

// Check if token is register name
bool checkRegister (string);

// Check if token is assembler directive
bool checkAsmDir (string);

// Check if token is advance assembler directive
bool checkAdvAsmDir (string);

// Check if token is mnmonic opcode
bool checkMnemonic (string);

// Check if token is address space or number
bool isNumber (string);

// Print Symbol-Table
void printSymbolTable(const vector<SymbolTableEntry>&);