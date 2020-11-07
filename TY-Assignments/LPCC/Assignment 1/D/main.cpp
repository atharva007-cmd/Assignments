#include "literal-pool.h"

int main (int argc, char* argv[]) {

	ifstream filestream;
	openFile(filestream, argv[1]);

	vector<LiteralPoolTableEntry> literalPoolTable;
	literalPoolTable.reserve(5);

	handleTokens(filestream, literalPoolTable);

	printLiteralPoolTable(literalPoolTable);
	
	filestream.close();
	return 0;
}