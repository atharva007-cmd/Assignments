#include "table.h"

int main (int argc, char* argv[]) {

	std::ifstream symbolFilestream, literalFilestream, poolFilestream;
	openFile(symbolFilestream, argv[1]);
	openFile(literalFilestream, argv[1]);
	openFile(poolFilestream, argv[1]);

	std::vector<SymbolTableEntry> symbolTable;
	symbolTable.reserve(5);

	std::vector<LiteralTableEntry> literalTable;
	literalTable.reserve(5);
	
	std::vector<LiteralPoolTableEntry> literalPoolTable;
	literalPoolTable.reserve(5);

	handleTokens(symbolFilestream, symbolTable);
	printSymbolTable (symbolTable);

	handleTokens(literalFilestream, literalTable);
	printLiteralTable (literalTable);

	handleTokens(poolFilestream, literalPoolTable);
	printLiteralPoolTable (literalPoolTable);
	
	symbolFilestream.close();
	literalFilestream.close();
	poolFilestream.close();

	return 0;
}