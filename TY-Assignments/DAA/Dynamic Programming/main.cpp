#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <string.h>

int getObstCost ( int*, int*, int, std::vector<int>& );
    
int main() {
	int numberOfNodes;

	std::cout << "Number of nodes: ";
	std::cin >> numberOfNodes;
	assert (numberOfNodes > 0);
	
	int nodes[numberOfNodes];
	int frequencies[numberOfNodes];

	// To store OBST nodes in sequential order
	std::vector<int> obstNodes;
	obstNodes.reserve (numberOfNodes);

	// Input tree nodes
	std::cout << "\nNodes:\n";
	for (int i=0; i<numberOfNodes; i++) {
		std::cin >> nodes[i];
	}

	// Input node frequencies
	std::cout << "\nFrequencies:\n";
	for (int i=0; i<numberOfNodes; i++) {
		std::cin >> frequencies[i];
		assert (frequencies[i] > 0);
	}

	// Display the inputs given
	std::cout << "\nNode Frequency\n";
	for (int i=0; i<numberOfNodes; i++) {
		std::cout << " " << nodes[i] << "\t" << frequencies[i] << "\n";
	}

	// Get minimum searching cost for OBST's node
	int minimumCost = getObstCost (nodes, frequencies, numberOfNodes, obstNodes);

	// Display the OBST nodes
	std::cout << "\nOBST Nodes: ";
	for (int node: obstNodes) {
		std::cout << node << " ";
	}
	
	// Print the minimum cost
	std::cout << "\nMinimum Cost: " << minimumCost << "\n";

	return 0;
}

int getObstCost (int* nodes, int* frequencies, int population, std::vector<int> &obstNodes) {

	// For storing frequency calculations
	int frequencyTable[population][population];
	memset (frequencyTable, 0, sizeof(frequencyTable));
	
	// For storing node information
	int nodeTable[population][population];
	memset (nodeTable, 0, sizeof(nodeTable));
	
	// For generating weight for nodes a to b
	int prefixSumArray[population];
	prefixSumArray[0] = frequencies[0];
	for (int i=1; i<population; i++) {
		prefixSumArray[i] = prefixSumArray[i-1] + frequencies[i];
	}

	for (int diagonal=0; diagonal<population; diagonal++) {
		for (int i=0, j=diagonal; j<population; i++, j++) {

			// This is the first/longest diagonal's case
			if (diagonal == 0) {
				/**
				 * Here we handle the case with single node
				 * 
				 * Level 1:		a
				 * Thus minimum frequency for search operation = frequency of node
				 */
				frequencyTable[i][j] = frequencies[i];
				nodeTable[i][j] = nodes[i];
			}
			// This is the second/adjacent diagonal's case
			else if (diagonal == 1) {
				/**
				 * Here we handle the case with two nodes
				 * 
				 * Level 1:		a		b
				 *       	   /		 \
				 * Level 2:   b			  a
				 * 
				 * Thus minimum frequncy is either for 'node a' or 'node b'
				 * frequencies[i] = Frequency of 'node a'
				 * frequencies[j] = Frequency of 'node b'
				 */
				frequencyTable[i][j] = std::min (
					frequencies[i] + 2*frequencies[j],
					frequencies[j] + 2*frequencies[i]
				);

				nodeTable[i][j] = frequencies[i]>frequencies[j] ? nodes[i]: nodes[j];
			}
			// This is every other diagonal's case except the first two
			else {
				int minimum = 99999999;
				int optimalNode = -1;
				// Weight is required as the depth of tree is increased by 1
				int weight = prefixSumArray[j] - (i == 0? 0: prefixSumArray[i-1]);

				for (int k=i; k<=j; k++) {
					// Left and Right subtrees
					int left = k == i ? 0: frequencyTable[i][k-1];		// Leftmost node's left is zero
					int right = k == j ? 0: frequencyTable[k+1][j];		// Rightmost node's right is zero

					if (left + right + weight < minimum) {
						minimum = left + right + weight;				// Minimum Cost
						optimalNode = k;								// Node for minimum cost
					}
				}

				frequencyTable[i][j] = minimum;
				nodeTable[i][j] = nodes[optimalNode];
			}
		}
	}

	// Traversing node-table diagonally in '\' direction
	// This way we can get OBST nodes in sequential order
	// and put it into the vector
	for (int g=population-1; g>=0; g--) {
		for (int i=0, j=g; j<population; i++, j++) {
			// If node is absent in the vector then push
			if(std::find(obstNodes.begin(), obstNodes.end(), nodeTable[i][j]) == obstNodes.end()) {
				obstNodes.push_back(nodeTable[i][j]);
			}
		}
	}

	// Display frequency calculation table
	std::cout << "\nCost Table:\n";
	for (int i=0; i<population; i++) {
		for (int j=0; j<population; j++) {
			if (j >= i) {
				printf("%02d  ", frequencyTable[i][j]);
			} else {
				printf("    ");
			}
		}
		std::cout << "\n";
	}

	// Display root table
	std::cout << "\nRoot Table:\n";
	for (int i=0; i<population; i++) {
		for (int j=0; j<population; j++) {
			if (j >= i) {
				printf("%02d  ", nodeTable[i][j]);
			} else {
				printf("    ");
			}
		}
		std::cout << "\n";
	}

	// Return minimum cost
	return frequencyTable[0][population-1];
}

