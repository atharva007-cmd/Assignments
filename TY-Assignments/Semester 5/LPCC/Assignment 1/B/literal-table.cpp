#include "literal-table.h"

void openFile (ifstream& filestream, string filename) {

	filestream.open(filename);
	if (filestream.is_open()) {
		
	} else {
		cout << "[ERROR]: Failed to open file\n";
		exit(-1);
	}
}

void handleTokens (ifstream& filestream, vector<LiteralTableEntry>& literalTable) {

	string line, token;
	int addressSpace = -1;

	vector<string> literalPool;
	int countLTORG = 0;

	while (getline(filestream, line)) {
		stringstream wordstream(line);
		while (wordstream >> token) {
			
			if (checkAdvAsmDir(token)) {
				if (token == AdvancedAssemblerDirectives[0]) {
					wordstream >> token;
					if (isNumber(token)) {
						addressSpace = stoi(token)-1;
					} else {
						cerr << "[ERROR]: Start address not mentioned";
						exit(-1);
					}
				}
				else if (token == AdvancedAssemblerDirectives[1]) {
					for (string literal: literalPool) {
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

ostream& operator<< (ostream& stream, const LiteralTableEntry& entry) {
	cout << entry.literal << "\t  " << entry.address << endl;
}	

void printLiteralTable(const vector<LiteralTableEntry>& literalTable) {
	cout << "\nLiteral Table\n\nLiteral\tAddress\n";
	for (LiteralTableEntry entry: literalTable) {
		cout << entry;
	}
}

bool checkLiteral (string token) {
	regex rule("=\'[0-9]+\'");
	return regex_match(token, rule);
}

bool checkAsmDir (string token) {
	if (find(AssemblerDirectives.begin(), AssemblerDirectives.end(), token) != AssemblerDirectives.end())
		return true;
	return false;
}

bool checkAdvAsmDir (string token) {
	if (find(AdvancedAssemblerDirectives.begin(), AdvancedAssemblerDirectives.end(), token) != AdvancedAssemblerDirectives.end())
		return true;
	return false;
}

bool checkMnemonic (string token) {
	if (find(Mnemonics.begin(), Mnemonics.end(), token) != Mnemonics.end())
		return true;
	return false;
}

bool checkRegister (string token) {
	if (find(Registers.begin(), Registers.end(), token) != Registers.end())
		return true;
	return false;
}

bool isNumber (string token) {
	regex rule("[0-9]+");
	return regex_match(token, rule);
}