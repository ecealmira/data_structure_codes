#include <iostream>
using namespace std;

// Min-Heap

void print(int A[], int n) {
	cout << "Heap:     ";
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl << "-------------" << endl;
}

void heapify(int A[], int n, int root) {
	// set the min as root
	int min = root;
	
	// find children
	int left = 2 * root + 1;
	int right = 2 * root + 2;

	// find minimum
	if (left < n && A[left] < A[min])
		min = left;
	if (right < n && A[right] < A[min])
		min = right;

	// swap the min child and the root
	if (min != root) {
		swap(A[root], A[min]);
		heapify(A, n, min);
	}
}

void build(int A[], int n) {
	int lastParent = n / 2 - 1;
	
	// start from the last child and heapify backwards
	for (int i = lastParent; i >= 0; i--)
		heapify(A, n, i);
}

void heapSort(int A[], int n) {
	// build min-heap
	build(A, n);
	
	// swap first and last elements
	for (int i = n - 1; i > 0; i--) {
		swap(A[0], A[i]);
		heapify(A, i, 0); 
	}
}

void insertNumber(int num, int*& A, int& n) {
	// increase size of the array
	int* newArr = new int[n + 1];
	for (int i = 0; i < n; i++)
		newArr[i] = A[i];

	// add number at the end of the array
	newArr[n] = num;
	delete[] A;
	A = newArr;
	n++;

	// Rebuild min-heap
	build(A, n); 
}

void deleteNumber(int num, int*& A, int& n) {
	// find index
	int index = -1;
	for (int i = 0; i < n; i++) {
		if (A[i] == num) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		cout << "Number not found in heap." << endl;
		return;
	}

	// Swap with the last element
	swap(A[index], A[n - 1]);
	
	// decrease the size
	n--;
	int* newArr = new int[n];
	for (int i = 0; i < n; i++) {
		newArr[i] = A[i];
	}
	delete[] A;
	A = newArr;

	// rebuild the array
	build(A, n);
}

int main() {
	int n = 11;
	int* A = new int[n]{ 10, 3, 7, 4, 6, 1, 18, 9, 8, 5, 15 };

	// build
	build(A, n);
	print(A, n);

	// insert
	insertNumber(2, A, n);
	cout << "After insert" << endl;
	print(A, n);

	// delete
	deleteNumber(3, A, n);
	cout << "After deletion" << endl;
	print(A, n);

	// heapSort
	heapSort(A, n);
	cout << "After HeapSort" << endl;
	print(A, n);

	delete[] A;
	return 0;
}

