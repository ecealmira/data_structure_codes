#include <iostream>
using namespace std;

// Singly Linked List(SLL)

class Node
{
	int value;
	Node* next;
	
	friend class SLL; 
}; 

// Node'lar birle�erek linked list olu�turacaklar
class SLL
{
	Node* headPtr;
	
	public:
		SLL(); 
		// add destructor
		int tail();
		void removeEnd();
		void insertEnd(int x);
		void insertAfter(int x, int w);
		void print(); 
		Node* find(int x);
		bool isEmpty();
};

SLL::SLL()
{
	headPtr = NULL;
}

int SLL::tail()
{
	Node* p = headPtr;
	while(p->next != NULL)
	{
		p = p->next;
	}
	cout << "Tail: " << p->value << endl;
	return p->value;
};

void SLL::insertEnd(int x)
{
    Node* n = new Node; 
    n->value = x;
    n->next = NULL; 

    if (headPtr == NULL)  
    {
        headPtr = n;
        return;
    }

    Node* tail = headPtr;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    tail->next = n;
}

void SLL::removeEnd()
{
    if (headPtr == NULL)  
    {
        cout << "Cannot remove from empty list" << endl;
        return;
    }

    if (headPtr->next == NULL)  // If there is only one node
    {
        delete headPtr;
        headPtr = NULL;
        return;
    }

    Node* p = headPtr;
    while (p->next->next != NULL)  // sondan ikinci olan bulunur
    {
        p = p->next;
    }

	// sondan ikinci sonuncuya atan�r
    delete p->next;  
    p->next = NULL;  
}

Node* SLL::find(int x)
{
	Node* p = headPtr;
	while(p != NULL)
	{
		if(p->value == x)
		{
			return p;
		} else {
			p = p->next; // link hopping
		}
	};
	return NULL; 
}


void SLL::insertAfter(int x, int w)
{
    Node* curr = find(w);
    if (curr == NULL)  // Check if the node is found
    {
        cout << "Value " << w << " not found in the list." << endl;
        return;
    }

    Node* n = new Node;
    n->value = x;
    n->next = curr->next;
    curr->next = n;       
}

void SLL::print()
{
	Node* p = headPtr; 
	cout << "List: ";
	while(p != NULL) 
	{
		cout << p->value << " ";
		p = p->next; // link hopping
	}
	cout << endl;
};

bool SLL::isEmpty()
{
	// head pointer hi�bir yeri i�aret etmiyorsa liste bo�tur
	if(headPtr == NULL)
	{
		cout << "Linked list is empty" << endl;
		return true; // e�er bo� ise true d�nd�r�r
	} else
	{
		cout << "Linked list is NOT empty" << endl;
		return false; // e�er dolu ise false d�nd�r�r
	}
}

int main()
{
	SLL myList;
	
	myList.insertEnd(7);
	myList.insertEnd(2);
	myList.insertEnd(1);
	
	cout << "List before deletion" << endl;
	myList.print();
	
	cout << "Show the tail" << endl;
	myList.tail();
	
	cout << "List after deletion" << endl;
	myList.removeEnd();
	myList.print();
	
	cout << "List after insertAfter" << endl;
	myList.insertAfter(3,7);
	myList.print();

    return 0;
};

