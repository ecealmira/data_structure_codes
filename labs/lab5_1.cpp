#include <iostream>
using namespace std;

// SLL
// removeEnd, insertAfter, find

class Node
{
    int value;
    Node* next;
    
    friend class SLL;
};

class SLL
{
    Node* headPtr;
  public:
    SLL();  // constructor
    ~SLL();  // destructor
    
    bool isEmpty();
    int head();
    void print();
    Node* find(int x);
    
    void insertFront(int x);
    // w sonrasýna x ekle
    void insertAfter(int x, int w); // sonrasýnda ekleneceði elemaný da alýr
    void insertEnd(int x);
    
    void removeFront();
    void removeEnd();
};

SLL::SLL()
{
    headPtr=NULL;
};

bool SLL::isEmpty()
{
    if(headPtr==NULL)
    {
        //cout <<"The list is empty." <<endl;
        return 1;
    }
    else
    {
        //cout <<"The list is not empty." <<endl;
        return 0;
    };
};

int SLL::head()
{
    if(headPtr)
    {
        cout <<"Head: " <<headPtr->value <<endl;
        return headPtr->value;
    }
    else
    {
        cout <<"Head: N/A" <<endl;
        return 0;
    };
};

void SLL::print()
{
    Node* p=headPtr;
    cout <<"List: ";
    while(p!=NULL)
    {
        cout <<p->value <<" ";
        p=p->next;
    };
    cout <<endl;
};

void SLL::insertFront(int x)
{
    Node* n=new Node;
    n->value=x;
    n->next=headPtr;
    headPtr=n;
};

void SLL::insertEnd(int x)
{
    Node* n=new Node;
    n->value=x;
    n->next=NULL;
    
    Node* p=headPtr;
    if(p)  // non-empty list
    {
        while(p->next!=NULL)
            p=p->next;
        p->next=n;
    }
    else  // empty list
        insertFront(x);
};

void SLL::removeFront()
{
    Node* p=headPtr;
    if(p)
    {
        headPtr=headPtr->next;
        delete p;
    }
    else  // empty list
        cout <<"Failed to remove as the list is empty." <<endl;
};

void SLL::removeEnd()
{
    Node* p=headPtr;
    if(p==NULL)
        cout <<"Failed to remove as the list is empty." <<endl;
    else if(p->next == NULL)
    { 
		// only one node in the list
		delete p;
		headPtr = NULL;
	}
    else
    {
    	// iki sonrasý boþ olana kadar ileri gideriz
        while(p->next->next != NULL)
        {
        	p=p->next;
        }
        // en sonuncuyu sileriz
        delete p->next;
        
        // sondan öncekini null atarýz
        p->next = NULL;
    };
};

Node* SLL::find(int x)
{
	// listede ayný elemandan birden fazla varsa ilkini döndürür
	Node* p=headPtr;
	while(p!= NULL)
    {
        if(p->value == x)
        {
        	return p;
		}
		else 
		{
			p = p->next;
		}
    };
    // p bulunursa while içinde return dönerdi
    // yani bulunamazsa buraya gelir
    cout <<"Failed to find." <<endl;
    return NULL;
};

void SLL::insertAfter(int x, int w)
{
	Node* n=new Node;
    n->value=x;
    
    // w yi iþaret eden pointer ý bulduk
    Node* prevNode = find(w);
    // eðer prevNode varsa, eleman listede olmayabilir
    if(prevNode)
	{	 
		n->next = prevNode->next;
		prevNode->next = n;
	}
	else 
	{
		cout <<"Failed to insert." <<endl;
	}
    
};

SLL::~SLL()
{
    while(!isEmpty())
        removeFront();
};


int main()
{
    SLL myList;
    myList.insertFront(2);
    myList.insertFront(1);
    myList.insertEnd(3);
    myList.print();
    //myList.removeEnd();
    //cout <<"List after removeEnd" <<endl;
    
    myList.insertAfter(6,2);
    cout <<"List after insertAfter" <<endl;
    // myList.insertAfter(6,NULL); NULL, 0 olarak kabul edilir 
    myList.print();

    
    cout <<endl <<endl;
    return 0;
};
