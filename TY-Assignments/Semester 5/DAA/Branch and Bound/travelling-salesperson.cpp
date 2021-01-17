#include "travelling-salesperson.h"

extern int* visited;

// find route with least cost
int findRoute( int** matrix, int cost, int vertex, int size) {

	// check if all nodes are visited
	int totalNodesVisited = 0;
	for (int i=0; i<size; i++) {
		if (visited[i]) { totalNodesVisited++; }
		if (totalNodesVisited == size) { return cost; }
	}

	// init "unique" node
	std::unique_ptr<node> currentNode = std::make_unique<node>(cost, vertex);
	currentNode->reducedMatrix = (int**) malloc (size * sizeof(int*));
	for (int i=0; i<size; currentNode->reducedMatrix[i] = (int*) malloc (size * sizeof(int)), i++);
	memcopy( currentNode->reducedMatrix, matrix, size);
	
	// mark the node as visited
	visited[ currentNode->vertex ] = 1;
	std::cout << currentNode->vertex << " ==> ";

	// init "shared" node for storing temporary information
	std::shared_ptr<node> bufferNode = std::make_shared<node>(INF, -1);
	bufferNode->reducedMatrix = (int**) malloc (size * sizeof(int*));
	for (int i=0; i<size; bufferNode->reducedMatrix[i] = (int*) malloc (size * sizeof(int)), i++);
	// store least cost for traversal
	int lowerBound = INF;

	// iterate over each unvisited node
	for (int i=0; i<size; i++) {
	
		if (!visited[i]) {
			// init another "shared" node for calculations
			std::shared_ptr<node> nextNode = std::make_shared<node>( INF, i );
			nextNode->reducedMatrix = (int**) malloc (size * sizeof(int*));
			for (int i=0; i<size; nextNode->reducedMatrix[i] = (int*) malloc (size * sizeof(int)), i++);
			memcopy( nextNode->reducedMatrix, currentNode->reducedMatrix, size );

			// cost for traversal before reduction
			int initialCost = nextNode->reducedMatrix[currentNode->vertex][nextNode->vertex];

			// set the cost for whole row and column from current-node to next-node as ∞
			for (int x=0; x<size; x++) {
				nextNode->reducedMatrix[x][nextNode->vertex] = INF;
				nextNode->reducedMatrix[currentNode->vertex][x] = INF;
			}
			nextNode->reducedMatrix[i][currentNode->vertex] = INF;

			// cost for traversal after reduction
			int reducedCost = rowReduce(nextNode->reducedMatrix, size) + columnReduce(nextNode->reducedMatrix, size);
			nextNode->cost = reducedCost + initialCost + cost;

			// node under evaluation has least cost for traversal
			// copy it's contents in the buffer-node and update the lower-bound
			if (nextNode->cost < lowerBound) {
				lowerBound = nextNode->cost;
				bufferNode = nextNode;
				memcopy(bufferNode->reducedMatrix, nextNode->reducedMatrix, size);
			}
		}		
	}
	lowerBound = (lowerBound==INF)? currentNode->cost: lowerBound;

	return findRoute( bufferNode->reducedMatrix, lowerBound, bufferNode->vertex, size );
}

// reduce matrix row and return cost-of-reduction
int rowReduce( int** matrix, int size) {

	int minimum = INF, costOfReduction = 0;
	for (int i=0; i<size; i++) {
		for (int j=0; j<size; j++) { minimum = (matrix[i][j] < minimum)? matrix[i][j] : minimum; }
		for (int j=0; j<size; j++) { if (matrix[i][j] != INF) { matrix[i][j] -= minimum; } }
		costOfReduction += (minimum != INF)? minimum: 0;
		minimum = INF;
	}

	return costOfReduction;
}

// reduce matrix column and return cost-of-reduction
int columnReduce( int** matrix, int size) {

	int minimum = INF, costOfReduction = 0;
	for (int i=0; i<size; i++) {
		for (int j=0; j<size; j++) { minimum = (matrix[j][i] < minimum)? matrix[j][i] : minimum; }
		for (int j=0; j<size; j++) { if (matrix[j][i] != INF) { matrix[j][i] -= minimum; } }
		costOfReduction += (minimum != INF)? minimum: 0;
		minimum = INF;
	}

	return costOfReduction;
}

// get cost for traversal between each node
// return adjacency matrix
void inputArray( int** matrix, int size ) {

	for (int i=0; i<size; i++) {
		for (int j=0; j<size; j++) {
			if( i==j ) { matrix[i][j] = INF; }
			else {
				std::cout << "Cost for edge between " << i << " to " << j << ": ";
				std::cin >> matrix[i][j];
			}
		}
	}
}

// display adjacency matrix
void displayArray( int** matrix, int size, const char* name ) {

	std::cout << "\n" << name << ":\n";
	for (int i=0; i<size; i++) {
		for (int j=0; j<size; j++) {
			if (matrix[i][j] == INF) printf(" ∞   ");
			else printf("%03d  ", matrix[i][j]);
		}
		std::cout << "\n";
	}
}

// copy elements from one matrix to another
void memcopy( int** destination, int** source, int size ) {
	
	for (int i=0; i<size; i++) {
		for (int j=0; j<size; destination[i][j] = source[i][j], j++);
	}
}