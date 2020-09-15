#include <iostream>
#include <stdio.h>

using namespace std;

void printarray (int [], int);
void quicksort (int [], int, int);
int split (int [], int, int);
void swap (int*, int*);


// Main Function
int main (int argc, char* argv[]) {
	int size;

	cout << "Enter size of array: ";
	cin >> size;
	int array[size];

	cout << "\nEnter array elements" << endl;
	for (int i=0; i<size; i++) {
		cin >> array[i];
	}
	
	cout << "\nInput Array: ";
	printarray (array, size);

	quicksort (array, 0, size-1);

	cout << "\nOutput Array: ";
	printarray (array, size);

	return 0;
}



// Quicksort Function
void quicksort (int array[], int lowerBound, int upperBound) {
	
	// Array has less than 2 elements
	// No need for sorting
	if (lowerBound-upperBound >= 0) {
		return;
	}

	// Split the array
	int splitPoint = split (array, lowerBound, upperBound);

	// Left sub-array recursion sort call
	quicksort (array, lowerBound, splitPoint-1);

	// Right sub-array recursion sort call
	quicksort (array, splitPoint+1, upperBound);
}


// Core of quicksort
int split (int array[], int lowerBound, int upperBound) {

	int left = lowerBound+1;
	int right = upperBound;
	int pivot = array[lowerBound];

	while (true) {

		// Find index such that array[index] > pivot
		while (left <= right) {
			if (array[left] < pivot) {
				left++;
			} else {
				break;
			}
		}

		// Find index such that array[index] < pivot
		while (right > left) {
			if (array[right] > pivot) {
				right--;
			} else {
				break;
			}
		}

		// The left pointer has exceeded the array bounds
		// Thus get out of the loop
		if (left >= right) {
			break;
		}

		// Swap left and right element
		swap (&array[left], &array[right]);

		// Advance each pointer in respective position
		left++;
		right--;
	}

	// Swap pivot with (left-1) positon
	swap (&array[lowerBound], &array[left-1]);

	return left-1;
}


// Prints array in [0, 1, 2, ... , n] format
void printarray (int array[], int size) {
	cout << "[";
	for (int i=0; i<size; i++) {
		cout << array[i] << ", ";
	}
	cout << "\b\b]" << endl;
}


// Swaps values from two positions
void swap (int* first, int* second) {
	int temp;
	temp = *first;
	*first = *second;
	*second = temp;
}