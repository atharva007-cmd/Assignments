#include "travelling-salesperson.h"

int* visited;

int main (int argc, const char* argv[]) {

	// get number of nodes
	int  numberOfNodes;
	std::cout << "Enter number of nodes: ";
	std::cin >> numberOfNodes;
	assert( "Number of nodes should be greater than 2" && numberOfNodes>2 );

	// init visited array and set values to 0
	visited = (int*) malloc (numberOfNodes * sizeof(int));
	memset( visited, 0, sizeof(visited) );

	// init adjacency matrix for graph
	int **adjacencyMatrix = (int**) malloc (numberOfNodes * sizeof(int*));
	for (int i=0; i<numberOfNodes; adjacencyMatrix[i] = (int*) malloc (numberOfNodes * sizeof(int)), i++);

	// get cost values  and display the adjacency matrix
	inputArray( adjacencyMatrix, numberOfNodes );
	displayArray( adjacencyMatrix, numberOfNodes, "Adjacency Matrix" );

	// reduce the adjacency matrix for finding the root's cost
	int cost = rowReduce(adjacencyMatrix, numberOfNodes) + columnReduce(adjacencyMatrix, numberOfNodes);

	// get the starting node for the traversal
	int root = -1;
	std::cout << "\nEnter starting node: ";
	std::cin >> root;
	assert( "Starting node should be between 0 and number-of-nodes" && root>=0 && root<numberOfNodes );

	// print the total minimum cost for the traversal
	std::cout << "Route: ";
	int finalCost = findRoute(adjacencyMatrix, cost, root, numberOfNodes);
	std::cout << "\b\b\b\b==> " << root << "\nCost for traversal: " << finalCost << "\n";

	// free the heap memory
	for (int i=0; i<numberOfNodes; free(adjacencyMatrix[i]), i++);
	free(adjacencyMatrix);
	free(visited);

	return 0;
}