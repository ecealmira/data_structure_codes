#include <iostream>
#include <stack>
using namespace std;

// Stack

void print(stack <int> s) {
	// void fonksiyonuna stack'in kopyas� g�nderildi�i as�l stack bozulmaz
	cout << "Stack: ";
	
	// stack bo� olana kadar
	while(!s.empty()) {
		// en �ste bak
		cout << s.top() << " ";
		
		// en �st� at, alttakine ge�
		s.pop();
	}
	
	cout << endl;
}

int main() {
	
	// iki tane stack
	// verilerin tipi girilmeli
	stack <int> s1, s2;
	
	// push --> eleman koyar
	s1.push(10);
	s1.push(20);
	s1.push(30);
	
	// empty() --> bo� mu kontrol
	if (s1.empty()) {
		cout << "The stack is empty" << endl;
	} else {
		cout << "The stack is NOT empty" << endl;
	}
	
	// size() --> uzunluk
	cout << "The number of elements: " << s1.size() << endl;
	
	// top() --> en �sttekini verir
	cout << "The top of the stack: " << s1.top() << endl;
	cout << "The top of the stack: " << s1.top() << endl; // de�i�medi�i i�in ayn�s� kal�r
	
	// void print()
	print(s1);
	print(s2);
	
	// pop() --> en �stteki eleman� ��kar�r
	s1.pop();
	cout << "Popped the last element" << endl;
	cout << "The top of the stack: " << s1.top() << endl;

	 
    return 0;
};

