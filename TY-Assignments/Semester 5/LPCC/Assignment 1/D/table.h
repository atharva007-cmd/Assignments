# pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>

// Storing constants, basic and advance assembler directives, mnmonic opcodes
const std::vector<std::string> Registers = { "AREG", "BREG", "CREG", "DREG" };
const std::vector<std::string> AssemblerDirectives = { "DC", "DS" };
const std::vector<std::string> AdvancedAssemblerDirectives = { "START", "END", "ORIGIN", "EQU", "LTORG" };
const std::vector<std::string> Mnemonics = { "STOP", "ADD", "SUB", "MULT", "MOVER", "MOVEM", "COMP", "BC", "DIV", "READ", "PRINT" };


struct SymbolTableEntry {
	std::string symbol;
	int address;

	SymbolTableEntry (std::string symbol, int address)
		: symbol(symbol), address(address)
	{}
};

struct LiteralTableEntry {
	std::string literal;
	int address;

	LiteralTableEntry (std::string literal, int address)
		: literal(literal), address(address)
	{}
};

struct LiteralPoolTableEntry {
	int hash;
	int address;

	LiteralPoolTableEntry (int hash, int address)
		: hash(hash), address(address)
	{}
};

// Handle tokens for Symbol-Table
void handleTokens (std::ifstream&, std::vector<SymbolTableEntry>&);

// Print Symbol-Table
void printSymbolTable(const std::vector<SymbolTableEntry>&);

// Handle tokens for Literal-Table
void handleTokens (std::ifstream&, std::vector<LiteralTableEntry>&);

// Print Literal-Table
void printLiteralTable(const std::vector<LiteralTableEntry>&);

// Handle tokens for Literal-Pool-Table
void handleTokens (std::ifstream&, std::vector<LiteralPoolTableEntry>&);

// Print Literal-Pool-Table
void printLiteralPoolTable(const std::vector<LiteralPoolTableEntry>&);

// To open the file
void openFile (std::ifstream&, std::string);

// Check if token is literal
bool checkLiteral (std::string);

// Check if token is assembler directive
bool checkAsmDir (std::string);

// Check if token is advance assembler directive
bool checkAdvAsmDir (std::string);

// Check if token is mnmonic opcode
bool checkMnemonic (std::string);

// Check if token is register name
bool checkRegister (std::string);

// Check if token is address space or number
bool isNumber (std::string);