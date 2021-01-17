#include "n-queen.h"

int main (int argc, const char* argv[]) {

	int size = std::atoi( argv[1] );
	assert(size > 3);

	int **chessBoard = new int*[size];
	for (int i=0; i<size; chessBoard[i++] = new int[size]);

	solveNQueen(size, 0, chessBoard);

	return 0;
}

