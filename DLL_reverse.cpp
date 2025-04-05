#include <iostream>
using namespace std;

// DLL

class Node
{
    int value;
    Node* prev;
    Node* next;
    
    friend class DLL;
};

class DLL
{
    Node* header;
    Node* trailer;
  public:
    DLL();
    ~DLL();
    
    bool isEmpty();
    int head();
    int tail();
    void print();
    
    void insertBefore(Node* n, int x);
    void insertFront(int x);
    void insertEnd(int x);
    
    void remove(Node* n);
    void removeFront();
    void removeEnd();
    
    void reverse();
};

DLL::DLL()
{
    header=new Node;
    trailer=new Node;
    header->next=trailer;
    trailer->prev=header;
};

bool DLL::isEmpty()
{
    if(header->next==trailer)
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

int DLL::head()
{
    if(!isEmpty())
    {
        cout <<"Head: " <<header->next->value <<endl;
        return header->next->value;
    }
    else
    {
        cout <<"Head: N/A" <<endl;
        return 0;
    };
};

int DLL::tail()
{
    if(!isEmpty())
    {
        cout <<"Tail: " <<trailer->prev->value <<endl;
        return trailer->prev->value;
    }
    else
    {
        cout <<"Tail: N/A" <<endl;
        return 0;
    };
};

void DLL::print()
{
    Node* p=header->next;
    cout <<"List: ";
    while(p!=trailer)
    {
        cout <<p->value <<" ";
        p=p->next;
    };
    cout <<endl;
};

void DLL::insertBefore(Node* n, int x)
{
    Node* m=new Node;
    m->value=x;
    m->next=n;
    m->prev=n->prev;
    n->prev->next=m;
    n->prev=m;
};

void DLL::insertFront(int x)
{
    insertBefore(header->next, x);
};

void DLL::insertEnd(int x)
{
    insertBefore(trailer, x);
};

void DLL::remove(Node* n)
{
    if(!isEmpty())
    {
        n->prev->next=n->next;
        n->next->prev=n->prev;
        delete n;
    }
    else
        cout <<"Failed to remove as the list is empty." <<endl;
};

void DLL::removeFront()
{
    remove(header->next);
};

void DLL::removeEnd()
{
    remove(trailer->prev);
};

DLL::~DLL()
{
    while(!isEmpty())
        removeFront();
    delete header;
    delete trailer;
};

void DLL::reverse()
{
    DLL L;  // temporary list
    while(!isEmpty())
    {
        L.insertFront(head());
        removeFront();
    };
    // L.print();
    while(!L.isEmpty())
    {
        insertEnd(L.head());
        L.removeFront();
    };
};


int main()
{
    DLL myList;
    //myList.print();
    //myList.head(); myList.tail(); cout <<endl;
    
    /*
    myList.insertFront(2);
    myList.insertFront(1);
    myList.insertEnd(3);
    myList.insertEnd(4);
    myList.print();
    myList.head(); myList.tail(); cout <<endl;
    */
    
    /*
    myList.removeEnd();
    myList.print();
    
    myList.removeFront();
    myList.print();

    myList.removeEnd();
    myList.print();
    
    myList.removeFront();
    myList.print();
     */
    
    //myList.reverse();
    //myList.print();
    
    cout <<endl <<endl;
    return 0;
};
