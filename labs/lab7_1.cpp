#include <iostream>
#include <stack>
using namespace std;

// Stack

void print(stack <int> s) {
	// void fonksiyonuna stack'in kopyasý gönderildiði asýl stack bozulmaz
	cout << "Stack: ";
	
	// stack boþ olana kadar
	while(!s.empty()) {
		// en üste bak
		cout << s.top() << " ";
		
		// en üstü at, alttakine geç
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
	
	// empty() --> boþ mu kontrol
	if (s1.empty()) {
		cout << "The stack is empty" << endl;
	} else {
		cout << "The stack is NOT empty" << endl;
	}
	
	// size() --> uzunluk
	cout << "The number of elements: " << s1.size() << endl;
	
	// top() --> en üsttekini verir
	cout << "The top of the stack: " << s1.top() << endl;
	cout << "The top of the stack: " << s1.top() << endl; // deðiþmediði için aynýsý kalýr
	
	// void print()
	print(s1);
	print(s2);
	
	// pop() --> en üstteki elemaný çýkarýr
	s1.pop();
	cout << "Popped the last element" << endl;
	cout << "The top of the stack: " << s1.top() << endl;

	 
    return 0;
};

