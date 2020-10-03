#include "symbol-table.h"

void openFile (ifstream& filestream, string filename) {

	filestream.open(filename);
	if (filestream.is_open()) {
		
	} else {
		cout << "[ERROR]: Failed to open file\n";
		exit(-1);
	}
}

void handleTokens (ifstream& filestream, vector<SymbolTableEntry>& symbolTable) {

	string line, token;
	int addressSpace = -1;

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

			} else if (checkAsmDir(token)) {
				addressSpace++;
			} else if (checkMnemonic(token)) {
				addressSpace++;
			} 
			else if (checkLiteral(token)) {}
			else if (checkRegister(token)) {} 
			else if (isNumber(token)) {} 
			
			else {
				string symbol = token;
				wordstream >> token;
				if (checkAsmDir(token)) {
					addressSpace++;
					symbolTable.emplace_back( symbol, addressSpace);
				}
			}
		}
	}
}

ostream& operator<< (ostream& stream, const SymbolTableEntry& entry) {
	cout << entry.symbol << "\t  " << entry.address << endl;
}	

void printSymbolTable(const vector<SymbolTableEntry>& symbolTable) {
	cout << "\nSymbol Table\n\nSymbol\tAddress\n";
	for (SymbolTableEntry entry: symbolTable) {
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