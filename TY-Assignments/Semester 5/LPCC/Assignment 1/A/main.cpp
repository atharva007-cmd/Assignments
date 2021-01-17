#include "symbol-table.h"

int main (int argc, char* argv[]) {

	ifstream filestream;
	openFile(filestream, argv[1]);

	vector<SymbolTableEntry> symbolTable;
	symbolTable.reserve(5);

	handleTokens(filestream, symbolTable);

	printSymbolTable(symbolTable);
	
	filestream.close();
	return 0;
}