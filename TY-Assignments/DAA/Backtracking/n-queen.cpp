#include "n-queen.h"

bool solveNQueen ( int N, int row, int** board ) {

	// Out of bounds
	if ( row == N ) {

		std::cout << "\n\n\n";
		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				
				if ( board[i][j] ) {
					std::cout << "✅   ";
				} else {
					std::cout << "❌   ";
				}
			}
			std::cout << "\n\n";
		}

		return false;
	}

	// Recursive call to place queen in right position
	for (int j=0; j<N; j++) {

		if ( isSafePosition (N, row, j, board) ) {

			// Queen can be placed
			board[row][j] = 1;	

			// Check for the next queen
			if( solveNQueen (N, row+1, board) ) {
				return true;
			}

			// Apparently, further queens can't be placed
			// Backtrack and remove queen from ( row,j ) position 
			board[row][j] = 0;
		}
	}

	return false;
}

bool isSafePosition ( int N, int row, int column, int** board ) {

	// Check if queen present in same column
	for (int i=0; i<row; i++) {
		if ( board[i][column]==1 ) {
			return false;
		}
	}

	// Check if queen present in left diagonal
	for (int i=row, j=column; i>=0 && j>=0; i--, j--) {
		if ( board[i][j]==1 ) {
			return false;
		}
	}

	// Check if queen present in right diagonal
	for (int i=row, j=column; i>=0 && j<N; i--, j++) {
		if ( board[i][j]==1 ) {
			return false;
		}
	}

	// Queen is safe
	return true;
}