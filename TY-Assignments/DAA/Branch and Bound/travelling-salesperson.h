#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <memory>
#include <string.h>
#include <assert.h>

#define INF 2147483647

// graph node
struct node {

	// reduced cost matrix
	int** reducedMatrix;

	// traversal cost, vertex value
	int cost, vertex;

	node(int cost, int vertex)
		: cost(cost), vertex(vertex), reducedMatrix(nullptr) {}

	~node() {
		for (int i=0; i<5; free(this->reducedMatrix[i]), i++);
		free(this->reducedMatrix);
	}
};

// find route with least cost
int findRoute( int** , int , int , int );

// reduce matrix row and return cost-of-reduction
int rowReduce( int**, int );

// reduce matrix column and return cost-of-reduction
int columnReduce( int**, int );

// get cost for traversal between each node
// return adjacency matrix
void inputArray( int**, int );

// display adjacency matrix
void displayArray( int**, int, const char* );

// copy elements from one matrix to another
void memcopy( int** , int** , int );