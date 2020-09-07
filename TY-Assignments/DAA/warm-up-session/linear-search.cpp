#include <iostream>

using namespace std;

int linearSearch (int array[], int size, int key) {

	for (int i=0; i<size; i++) {
		if (array[i] == key) {
			return i;
		}
	}
	return -1;
}

int main() {

	int key, size, result=-1;
	cout << "Size of array: ";
	cin >> size;

	int array[size];

	cout << "Enter numbers:";
	for (int i=0; i<size; i++) {
		cin >> array[i];
	}

	cout << "Number to search: ";
	cin >> key;

	result = linearSearch(array, size, key);

	if (result < 0) {
		cout << "Number not found\n";
	} else {
		cout << "Number found at " << result << endl;
	}
	return 0;
}