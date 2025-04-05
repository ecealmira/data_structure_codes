#include <iostream>
using namespace std;

// DLL (Double Linked List)

class Node
{
    int value;
    
    Node* prev; // �ncekini i�aret eden pointer
    Node* next;
    
    friend class DLL;
};

class DLL
{
	// private
    Node* header;
    Node* trailer;
    
  	public:
	    DLL();
	    ~DLL();
	    
	    bool isEmpty();
	    int head(); // en ba�taki 
	    int tail(); // en sondaki 
	    void print();
	    
	    void insertBefore(Node* n, int x);
	    void insertFront(int x);
	    void insertEnd(int x);
	    
	    void remove(Node* n);
	    void removeFront();
	    void removeEnd();
};

DLL::DLL()
{
	// sentinel nodes
    header = new Node;
    trailer = new Node;
    
    // bo� listede header ve trailer birbirlerini g�sterir
    header->next = trailer;
    trailer->prev = header;
};

bool DLL::isEmpty()
{
    if(header->next == trailer) // e�er header trailer � g�steriyorsa liste bo�tur
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
    	//header->next ilk eleman� verir
    	// ilk eleman -> value bast�r�r�z
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
    	//trailer->prev sondaki verir
    	// son eleman -> value bast�r�r�z
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
    Node* p=header->next; // ilk eleman
    cout <<"List: ";
    // p nin kendisi trailer olursa bitmeli
    while(p != trailer)
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
    
    // en ba� - araya giren m - en sondaki n
    // ikisi de en ba�� (geriyi) g�steriyor
    m->prev = n->prev;
    
    // en ba�taki de�er araya giren m'ye atan�r
    n->prev->next = m;
    
    // en sondaki de�er araya giren m'ye atan�r
    n->prev = m;
};

void DLL::insertFront(int x)
{
	// en ba�taki eleman�n �n�ne ekle �eklinde kullan�l�r
    insertBefore(header->next, x); 
};

void DLL::insertEnd(int x)
{
	// insertBefore kendisi trailer'�n prev ine giderek ekliyor
    insertBefore(trailer, x); 
};

void DLL::remove(Node* n)
{
    if(!isEmpty())
    {
    	// n in �ncesi next pointer'� n in sonras�na atan�r
        n->prev->next = n->next;
        
        // n in sonras� n in �ncesine atan�r
        n->next->prev = n->prev;
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
	cout <<"started" <<endl;
    while(!isEmpty())
    	// ba�tan sona
        removeFront();
    delete header;
    delete trailer;
    cout <<"finished" <<endl;
};


int main()
{
    DLL myList;
    //myList.print();
    //myList.head(); myList.tail(); cout <<endl;
    
    
    myList.insertFront(2);
    myList.insertFront(1);
    myList.insertEnd(3);
    myList.insertEnd(4);
    myList.print();
    myList.head(); myList.tail(); cout <<endl;
    
    
    cout <<"After removeEnd" <<endl;
    myList.removeEnd();
    myList.print();
    
    cout <<"After removeFront" <<endl;
    myList.removeFront();
    myList.print();

	/*
	cout <<"After removeEnd" <<endl;
    myList.removeEnd();
    myList.print();
    
    cout <<"After removeFront" <<endl;
    myList.removeFront();
    myList.print();
    */
        
    cout <<endl <<endl;
    return 0;
};
