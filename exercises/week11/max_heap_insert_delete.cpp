#include <iostream>
using namespace std;

// Max-Heap
// insertion and deletion

void print(int A[], int n) {
	cout <<"Heap:     ";
    for(int i=0; i<n; i++)
        cout <<A[i] <<" ";
    cout <<endl;
    cout << "-------------" << endl;
}

void heapify(int A[], int n, int root)
{
	int max=root; // n
	int left=2*root+1; // 2n + 1
	int right=left+1; // 2n + 2
    
    // on the left of the root
    if(left<n && A[left]>A[max])
    	max=left;
    
    // on the right of the root
    if(right<n && A[right]>A[max])
    	max=right;
    	
    // swap the max child and the root	
    if(max!=root)
    {
    	swap(A[root], A[max]);
    	heapify(A, n, max);
	};
};

void build(int A[], int n)
{
	int lastParent=n/2-1; // (n/2) - 1
	
	// start from the last child and heapify backwards
	for(int i=lastParent; i>=0; i--)
		heapify(A, n, i);
};

void heapSort(int A[], int n)
{
	// build max heap
	build(A, n);
	for(int i=n-1; i>0; i--) // decrease the size by 1 
	{
		// swap first and last elements
		swap(A[0], A[i]);
		heapify(A, i, 0); // heapify the new root
	};    
};

void insertNumber(int num, int*& A, int& n) {
	// increase the size of array
	int* newArr = new int[n + 1];
	for (int i = 0; i < n; i++)
		newArr[i] = A[i];

	// insert number at the end
	newArr[n] = num;
	
	// delete the old array
	delete[] A;
	A = newArr;
	n++;

	// Rebuild the heap 
	build(A, n);
}

void deleteNumber(int num, int*& A, int& n) {
	// Find the index of the number to delete
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
	// Decrease the size
	n--; 

	// Allocate new array with one less size
	int* newArr = new int[n];
	for (int i = 0; i < n; i++) {
		newArr[i] = A[i];
	}
	delete[] A;
	A = newArr;

	// Rebuild the heap
	build(A, n);
}


int main()
{
    int n=11;
	int* A = new int[n]{10, 3, 7, 4, 6, 1, 2, 9, 8, 5, 15};
    
    // build Heap
    build(A, n);
	print(A,n);
    
    // insert
	insertNumber(11, A, n); 
	cout << "After insert" << endl;
	print(A,n);

	// delete
    deleteNumber(11, A, n);
    cout << "After deletion" << endl;
	print(A,n);
	
	// heapSort
	heapSort(A,n);
	cout << "After HeapSort" << endl;
	print(A,n);
	    
    cout <<endl <<endl;
    return 0;
    
};
