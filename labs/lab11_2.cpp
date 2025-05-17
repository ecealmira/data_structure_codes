#include <iostream>
using namespace std;

// Heap methods
// Max-Heap

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


int main()
{
    int n=11;
    int A[]={10, 3, 7, 4, 6, 1, 2, 9, 8, 5, 15};
    
    build(A, n);
    
    cout <<"Heap:     ";
    for(int i=0; i<n; i++)
        cout <<A[i] <<" ";
    cout <<endl;

    heapSort(A, n);
    
    cout <<"HeapSort: ";
    for(int i=0; i<n; i++)
        cout <<A[i] <<" ";
    
    cout <<endl <<endl;
    return 0;
};
