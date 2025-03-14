#include <iostream>
using namespace std;

// Singly Linked List(SLL)

class Node
{
	// 2 tane attribute var: value ve pointer
	int value;
	Node* next; // pointer bir sonraki node'a iþaret edecek
	
	// SLL tarafýndan eriþilebilmesi için public yapýlabilirdi --> kötü çözüm
	friend class SLL; // arkadaþlýk tek yönlü
}; // class'larýn sonunda noktalý virgül var

// Node'lar birleþerek linked list oluþturacaklar
class SLL
{
	// Attribute: head pointer
	// listenin baþýndaki ilk node'a iþaret eder
	Node* headPtr;
	
	public:
		SLL(); // constructer
		~SLL(); // destructor --> en son fonksiyon kapandýðýnda kendisi otomatik olarak çalýþýr
		void insertFront(int x); // baþa istenilen x elemanýný ekleme
		void removeFront(); // baþtaki elemaný sil
		void print(); // tüm listeyi ekrana basar
		bool isEmpty(); // liste boþ mu yoksa dolu mu diye boolean deðerinde döndürür
		int head(); // liste baþýndaki value döndürür --> direct access	
		Node* find(int x); // listedeki x elemanýný arar ve ona yönelten Node'u döndürür	
};

SLL::SLL()
{
	// head pointer baþta null olacak þekilde hiçbir yeri iþaret etmez
	headPtr = NULL;
}

bool SLL::isEmpty()
{
	// head pointer hiçbir yeri iþaret etmiyorsa liste boþtur
	if(headPtr == NULL)
	{
		cout << "Linked list is empty" << endl;
		return true; // eðer boþ ise true döndürür
	} else
	{
		cout << "Linked list is NOT empty" << endl;
		return false; // eðer dolu ise false döndürür
	}
}

void SLL::insertFront(int x) // O(1)
{
	// create a new node and return its address
	// constructor gibi yeni obje oluþturuyor
	Node* n = new Node;
	
	// n'in gösterdiði yerdeki value x olsun
	n->value = x;
	
	// n'in gösterdiði yerdeki Node'da next pointer'ý head pointer olmalý
	n->next = headPtr;
	
	// headpointer artýk n Node'una iþaret eder
	headPtr = n;
}

int SLL::head()
{
	cout << "Head: " << headPtr->value << endl;
	return headPtr->value; // en baþtaki value deðerini döndürür
}

void SLL::print()
{
	// p isimli geçici bir pointer
	// eðer headPtr kendisi kullanýlsaydý orijinal deðeri kaybedilirdi
	Node* p = headPtr; 
	cout << "List: ";
	while(p != NULL) //Null olmadýðý sürece bir sonrakine gider
	{
		// bulunan node'un deðerini yazdýr
		cout << p->value << " ";
		p = p->next; // link hopping
	}
	cout << endl;
};

void SLL::removeFront() // O(1)
{
	Node* p = headPtr;
	if(p) // eðer liste dolu ise
	{
		// head pointer artýk bir sonraki node'u iþaret eder
		headPtr = headPtr->next;
		delete p; // p'nin gösterdiði yapýyý siler
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
		// tüm liste boþalana kadar en öndekini siler
		removeFront();	
	}	
	cout << "destructor has finished" << endl;
};

Node* SLL::find(int x)
{
	// eðer ayný deðerden birden fazla varsa ilk bulduðunu döndürür
	Node* p = headPtr;
	while(p != NULL) //Null olmadýðý sürece bir sonrakine gider
	{
		if(p->value == x)
		{
			// eðer bulduysa pointer döndür
			cout << "value has been found" << endl;
			return p;
		} else {
			// bulamazsa bir sonraki elemana git
			p = p->next; // link hopping
		}
	};
	cout << "value has NOT been found" << endl;
	return NULL; // eðer hiç bulamazsa NULL döndürür
}

int main()
{
	// list oluþtur
	SLL myList;
	
	// empty mi kontrol et
	myList.isEmpty(); 
	
	// en baþa 7 deðeri ekle  
	myList.insertFront(7);
	//myList.head();
	
	// en baþa 2 deðeri ekle
	myList.insertFront(2);
	//myList.head();
	
	// en baþa 1 deðeri ekle
	myList.insertFront(1);
	myList.head();
	//myList.isEmpty();
	
	myList.print();
	
	// deðerleri bul
	myList.find(2);
	myList.find(12);
	
	/*
	// en baþtaki 1 sil
	myList.removeFront();
	myList.print();
	
	// her liste için destructor otomatik çalýþýr
	SLL myList2;
	myList.insertFront(4);
    return 0;
    */
};

