#include <iostream>
using namespace std;

// CLL (Circularly Linked List)
class Node 
{
    int value;
    Node* next;
    
    friend class CLL;
};

class CLL 
{
    Node* cursor;
	
	public:
	    CLL();
	    int isEmpty();
	    void print();
	    void insertAfter(int x);
	    void remove();
	    int frontReturn(int x);
	    int backReturn(int x);
	    Node* advance(Node* p);  // Advance function should take a node and return the next node
};

CLL::CLL() 
{
    cursor = NULL;  // Initially empty
};

Node* CLL::advance(Node* p) 
{
	if(p != NULL)
	{
		return p->next;
	}
    return NULL;  // Move to next node if exists
};

int CLL::isEmpty() 
{
    return cursor == NULL;
};

void CLL::print() 
{
    if (isEmpty()) {
        cout << "List is empty cannot print" << endl;
        return;
    }

    Node* p = cursor->next;  // Start from the first node
    cout << "List: ";

    do {
        cout << p->value << " ";
        p = advance(p);  // Move to the next node
    } while (p != cursor->next);  // Stop when we complete a full circle
    cout << endl;
};

void CLL::insertAfter(int x)
{
    Node* n = new Node;
    n->value = x;

    if (isEmpty()) {
        cursor = n;
        cursor->next = cursor;  // Circular link to itself
    } else {
        n->next = cursor->next;
        cursor->next = n;
        cursor = n;  // Move cursor to the newly inserted node
    }
};

void CLL::remove() 
{
    if (isEmpty()) {
        cout << "List is empty cannot remove" << endl;
        return;
    }

    Node* p = cursor->next;
    if (cursor == cursor->next) { // Only one node
        cursor = NULL;
    } else {
        cursor->next = p->next;
    }
    delete p;
};

int CLL::backReturn(int x) 
{
    if (isEmpty()) {
        cout << "List is empty cannot backReturn" << endl;
        return -1;
    }

    Node* p = cursor->next;
    Node* prev = cursor; // Start from last node

    while (p != cursor) {
        if (p->value == x) {
            cout << "The back node of " << x << " is " << prev->value << endl;
            return prev->value;
        }
        prev = p;
        p = p->next;
    }

    if (p->value == x) {
        cout << "The back node of " << x << " is " << prev->value << endl;
        return prev->value;
    }

    cout << "Value " << x << " not found in the list" << endl;
    return -1;
};

int CLL::frontReturn(int x) 
{
    if (isEmpty()) {
        cout << "List is empty" << endl;
        return -1;
    }

    Node* p = cursor->next;

    while (p != cursor) {
        if (p->value == x) {
            cout << "The front node of "<< x << " is" << p->next->value << endl;
            return p->next->value;
        }
        p = p->next;
    }

    if (p->value == x) {
        cout << "The front node of "<< x << " is " << p->next->value << endl;
        return p->next->value;
    }

    cout << "Value " << x << " not found in the list" << endl;
    return -1;
};

int main()
{
    CLL myList;
    myList.print();

    myList.insertAfter(2);
    myList.insertAfter(1);
    myList.insertAfter(3);
    myList.insertAfter(4);
    myList.print();
    
    myList.backReturn(4);
    myList.frontReturn(4);

    return 0;
};

