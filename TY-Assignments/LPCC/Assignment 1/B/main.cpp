#include "literal-table.h"

int main (int argc, char* argv[]) {

	ifstream filestream;
	openFile(filestream, argv[1]);

	vector<LiteralTableEntry> literalTable;
	literalTable.reserve(5);

	handleTokens(filestream, literalTable);

	printLiteralTable(literalTable);
	
	filestream.close();
	return 0;
}