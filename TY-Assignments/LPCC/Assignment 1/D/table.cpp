#include "table.h"

// To open the file
void openFile (std::ifstream& filestream, std::string filename) {

	filestream.open(filename);
	if (filestream.is_open()) {
		
	} else {
		std::cout << "[ERROR]: Failed to open file\n";
		exit(-1);
	}
}

// Handle tokens for Symbol-Table
void handleTokens (std::ifstream& filestream, std::vector<SymbolTableEntry>& symbolTable) {

	std::string line, token;
	int addressSpace = -1;

	while (getline(filestream, line)) {
		std::stringstream wordstream(line);
		while (wordstream >> token) {
			
			if (checkAdvAsmDir(token)) {
				if (token == AdvancedAssemblerDirectives[0]) {
					wordstream >> token;
					if (isNumber(token)) {
						addressSpace = stoi(token)-1;
					} else {
						std::cerr << "[ERROR]: Start address not mentioned";
						exit(-1);
					}
				}

			} else if (checkAsmDir(token)) {
				addressSpace++;
			} else if (checkMnemonic(token)) {
				addressSpace++;
			} 
			else if (checkLiteral(token)) {}
			else if (checkRegister(token)) {} 
			else if (isNumber(token)) {} 
			
			else {
				std::string symbol = token;
				wordstream >> token;
				if (checkAsmDir(token)) {
					addressSpace++;
					symbolTable.emplace_back( symbol, addressSpace);
				}
			}
		}
	}
}

// Handle tokens for Literal-Table
void handleTokens (std::ifstream& filestream, std::vector<LiteralTableEntry>& literalTable) {

	std::string line, token;
	int addressSpace = -1;

	std::vector<std::string> literalPool;
	int countLTORG = 0;

	while (getline(filestream, line)) {
		std::stringstream wordstream(line);
		while (wordstream >> token) {
			
			if (checkAdvAsmDir(token)) {
				if (token == AdvancedAssemblerDirectives[0]) {
					wordstream >> token;
					if (isNumber(token)) {
						addressSpace = stoi(token)-1;
					} else {
						std::cerr << "[ERROR]: Start address not mentioned";
						exit(-1);
					}
				}
				else if (token == AdvancedAssemblerDirectives[1]) {
					for (std::string literal: literalPool) {
						literalTable.emplace_back( literal, ++addressSpace);
					}
					literalPool.clear();
				}

			} else if (checkAsmDir(token)) {
				addressSpace++;
			} else if (checkMnemonic(token)) {
				addressSpace++;
			} 
			else if (checkLiteral(token)) {
				literalPool.push_back( token );
			}
			else if (checkRegister(token)) {} 
			else if (isNumber(token)) {} 
		}
	}
}

// Handle tokens for Literal-Pool-Table
void handleTokens (std::ifstream& filestream, std::vector<LiteralPoolTableEntry>& literalPoolTable) {

	std::string line, token;
	int addressSpace = -1;

	std::vector<std::string> literalPool;
	int countLTORG = 0;

	while (getline(filestream, line)) {
		std::stringstream wordstream(line);
		while (wordstream >> token) {
			
			if (checkAdvAsmDir(token)) {
				if (token == AdvancedAssemblerDirectives[0]) {
					wordstream >> token;
					if (isNumber(token)) {
						addressSpace = stoi(token)-1;
					} else {
						std::cerr << "[ERROR]: Start address not mentioned";
						exit(-1);
					}
				}
				else if (token == AdvancedAssemblerDirectives[1]) {

					literalPoolTable.emplace_back(++countLTORG, ++addressSpace);
					for (std::string literal: literalPool) {
						literalPool.emplace_back( literal);
						addressSpace++;
					}
					literalPool.clear();
				}
				else if (token == AdvancedAssemblerDirectives[4]) {
					literalPoolTable.emplace_back(++countLTORG, addressSpace);
					for (std::string literal: literalPool) {
						literalPool.emplace_back( literal);
						addressSpace++;
					}
					literalPool.clear();
				}

			} else if (checkAsmDir(token)) {
				addressSpace++;
			} else if (checkMnemonic(token)) {
				addressSpace++;
			} 
			else if (checkLiteral(token)) {
				literalPool.push_back( token );
			}
			else if (checkRegister(token)) {} 
			else if (isNumber(token)) {} 
		}
	}
}

std::ostream& operator<< (std::ostream& stream, const SymbolTableEntry& entry) {
	std::cout << entry.symbol << "\t  " << entry.address << std::endl;
}

std::ostream& operator<< (std::ostream& stream, const LiteralTableEntry& entry) {
	std::cout << entry.literal << "\t  " << entry.address << std::endl;
}

std::ostream& operator<< (std::ostream& stream, const LiteralPoolTableEntry& entry) {
	std::cout << "#" << entry.hash << "\t  " << entry.address << std::endl;
}

// Print Symbol-Table
void printSymbolTable(const std::vector<SymbolTableEntry>& symbolTable) {
	std::cout << "\n\nSymbol Table\n\nSymbol\tAddress\n";
	for (SymbolTableEntry entry: symbolTable) {
		std::cout << entry;
	}
}

// Print Literal-Table
void printLiteralTable(const std::vector<LiteralTableEntry>& literalTable) {
	std::cout << "\n\nLiteral Table\n\nLiteral\tAddress\n";
	for (LiteralTableEntry entry: literalTable) {
		std::cout << entry;
	}
}

// Print Literal-Pool-Table
void printLiteralPoolTable(const std::vector<LiteralPoolTableEntry>& literalTable) {
	std::cout << "\n\nLiteral Pool Table\n\nHash\tAddress\n";
	for (LiteralPoolTableEntry entry: literalTable) {
		std::cout << entry;
	}
}

// Check if token is literal
bool checkLiteral (std::string token) {
	std::regex rule("=\'[0-9]+\'");
	return std::regex_match(token, rule);
}

// Check if token is assembler directive
bool checkAsmDir (std::string token) {
	if (find(AssemblerDirectives.begin(), AssemblerDirectives.end(), token) != AssemblerDirectives.end())
		return true;
	return false;
}

// Check if token is advance assembler directive
bool checkAdvAsmDir (std::string token) {
	if (find(AdvancedAssemblerDirectives.begin(), AdvancedAssemblerDirectives.end(), token) != AdvancedAssemblerDirectives.end())
		return true;
	return false;
}

// Check if token is mnmonic opcode
bool checkMnemonic (std::string token) {
	if (find(Mnemonics.begin(), Mnemonics.end(), token) != Mnemonics.end())
		return true;
	return false;
}

// Check if token is register name
bool checkRegister (std::string token) {
	if (find(Registers.begin(), Registers.end(), token) != Registers.end())
		return true;
	return false;
}

// Check if token is address space or number
bool isNumber (std::string token) {
	std::regex rule("[0-9]+");
	return std::regex_match(token, rule);
}