#include <iostream>
#include <queue> 
using namespace std;

// Priority Queue
// under queue but it is a tree

void print(priority_queue <int> pq)
{
    cout <<"Priority queue: ";
    while(!pq.empty())
    {
    	// print and delete the top priority while it is not empty
        cout <<pq.top() <<" "; 
        pq.pop();
    };
    cout <<endl;
};

int main()
{
    priority_queue <int> pq1, pq2;
    
    // empty
    if(pq1.empty())
        cout <<"The priority queue is empty." <<endl;
    else
        cout <<"The priority queue is not empty." <<endl;
    
    // push
    int A[]={1,8,5,6,3,4,0,9,7,2};
    for(int i=0; i<10; i++)
        pq1.push(A[i]);
    
    // print
    print(pq1);
    
    // size
    cout <<"Number of elements in the priority queue: " <<pq1.size() <<endl;
    
    // top
    cout <<"Element with highest priority: " <<pq1.top() <<endl;
    
    // take from pq1 and add to pq2
    pq2.push(pq1.top());
    
    // pop
    pq1.pop(); cout <<"Pop!" <<endl;
    cout <<"Element with highest priority: " <<pq1.top() <<endl;
      
    cout <<endl <<endl;
    return 0;
};
