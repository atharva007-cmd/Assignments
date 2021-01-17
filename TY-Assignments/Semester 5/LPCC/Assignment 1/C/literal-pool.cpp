#include "literal-pool.h"

void openFile (ifstream& filestream, string filename) {

	filestream.open(filename);
	if (filestream.is_open()) {
		
	} else {
		cout << "[ERROR]: Failed to open file\n";
		exit(-1);
	}
}

void handleTokens (ifstream& filestream, vector<LiteralPoolTableEntry>& literalPoolTable) {

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

					literalPoolTable.emplace_back(++countLTORG, ++addressSpace);
					for (string literal: literalPool) {
						literalPool.emplace_back( literal);
						addressSpace++;
					}
					literalPool.clear();
				}
				else if (token == AdvancedAssemblerDirectives[4]) {
					literalPoolTable.emplace_back(++countLTORG, addressSpace);
					for (string literal: literalPool) {
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

ostream& operator<< (ostream& stream, const LiteralPoolTableEntry& entry) {
	cout << "#" << entry.hash << "\t  " << entry.address << endl;
}	

void printLiteralPoolTable(const vector<LiteralPoolTableEntry>& literalTable) {
	cout << "\nLiteral Pool Table\n\nHash\tAddress\n";
	for (LiteralPoolTableEntry entry: literalTable) {
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