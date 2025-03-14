#include <iostream>
using namespace std;

// Singly Linked List(SLL)

class Node
{
	// 2 tane attribute var: value ve pointer
	int value;
	Node* next; // pointer bir sonraki node'a i�aret edecek
	
	// SLL taraf�ndan eri�ilebilmesi i�in public yap�labilirdi --> k�t� ��z�m
	friend class SLL; // arkada�l�k tek y�nl�
}; // class'lar�n sonunda noktal� virg�l var

// Node'lar birle�erek linked list olu�turacaklar
class SLL
{
	// Attribute: head pointer
	// listenin ba��ndaki ilk node'a i�aret eder
	Node* headPtr;
	
	public:
		SLL(); // constructer
		~SLL(); // destructor --> en son fonksiyon kapand���nda kendisi otomatik olarak �al���r
		void insertFront(int x); // ba�a istenilen x eleman�n� ekleme
		void removeFront(); // ba�taki eleman� sil
		void print(); // t�m listeyi ekrana basar
		bool isEmpty(); // liste bo� mu yoksa dolu mu diye boolean de�erinde d�nd�r�r
		int head(); // liste ba��ndaki value d�nd�r�r --> direct access	
		Node* find(int x); // listedeki x eleman�n� arar ve ona y�nelten Node'u d�nd�r�r	
};

SLL::SLL()
{
	// head pointer ba�ta null olacak �ekilde hi�bir yeri i�aret etmez
	headPtr = NULL;
}

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

void SLL::insertFront(int x) // O(1)
{
	// create a new node and return its address
	// constructor gibi yeni obje olu�turuyor
	Node* n = new Node;
	
	// n'in g�sterdi�i yerdeki value x olsun
	n->value = x;
	
	// n'in g�sterdi�i yerdeki Node'da next pointer'� head pointer olmal�
	n->next = headPtr;
	
	// headpointer art�k n Node'una i�aret eder
	headPtr = n;
}

int SLL::head()
{
	cout << "Head: " << headPtr->value << endl;
	return headPtr->value; // en ba�taki value de�erini d�nd�r�r
}

void SLL::print()
{
	// p isimli ge�ici bir pointer
	// e�er headPtr kendisi kullan�lsayd� orijinal de�eri kaybedilirdi
	Node* p = headPtr; 
	cout << "List: ";
	while(p != NULL) //Null olmad��� s�rece bir sonrakine gider
	{
		// bulunan node'un de�erini yazd�r
		cout << p->value << " ";
		p = p->next; // link hopping
	}
	cout << endl;
};

void SLL::removeFront() // O(1)
{
	Node* p = headPtr;
	if(p) // e�er liste dolu ise
	{
		// head pointer art�k bir sonraki node'u i�aret eder
		headPtr = headPtr->next;
		delete p; // p'nin g�sterdi�i yap�y� siler
	} else { 
		// empty list
		cout << "list is empty cannot remove" << endl;
	}
};

SLL::~SLL()
{
	cout << "destructor has started" << endl;
	while(!isEmpty())
	{
		// t�m liste bo�alana kadar en �ndekini siler
		removeFront();	
	}	
	cout << "destructor has finished" << endl;
};

Node* SLL::find(int x)
{
	// e�er ayn� de�erden birden fazla varsa ilk buldu�unu d�nd�r�r
	Node* p = headPtr;
	while(p != NULL) //Null olmad��� s�rece bir sonrakine gider
	{
		if(p->value == x)
		{
			// e�er bulduysa pointer d�nd�r
			cout << "value has been found" << endl;
			return p;
		} else {
			// bulamazsa bir sonraki elemana git
			p = p->next; // link hopping
		}
	};
	cout << "value has NOT been found" << endl;
	return NULL; // e�er hi� bulamazsa NULL d�nd�r�r
}

int main()
{
	// list olu�tur
	SLL myList;
	
	// empty mi kontrol et
	myList.isEmpty(); 
	
	// en ba�a 7 de�eri ekle  
	myList.insertFront(7);
	//myList.head();
	
	// en ba�a 2 de�eri ekle
	myList.insertFront(2);
	//myList.head();
	
	// en ba�a 1 de�eri ekle
	myList.insertFront(1);
	myList.head();
	//myList.isEmpty();
	
	myList.print();
	
	// de�erleri bul
	myList.find(2);
	myList.find(12);
	
	/*
	// en ba�taki 1 sil
	myList.removeFront();
	myList.print();
	
	// her liste i�in destructor otomatik �al���r
	SLL myList2;
	myList.insertFront(4);
    return 0;
    */
};

