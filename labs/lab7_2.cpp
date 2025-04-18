#include <iostream>
#include <stack>
using namespace std;

// Stack
// Palindrome

int main() {
	
	stack <char> s;
	
	string str = "noon";
	//string str = "racecar";
	int i;
	int n = str.length();
	int n2 = n/2; // harfin ortasýna kadar
	
	for(i=0; i < n2; i++) {
		// stack'e koyulurken ters çevrilecek
		s.push(str[i]);
	}
	
	// tek sayý ise sonuç 1, yani true
	if(n%2) {
		i++; // ortadaki harfi atlarýz
	}
	
	// i kaldýðý yerden devam etsin diye ilk baþ boþ
	cout << "\"" << str  << "\"" << " is";
	for(; i<n; i++) {
		// string in baþý ile stack in baþý karþýlaþtýrýlýr
		if(str[i]!=s.top()){
			cout << " not";
			break; // ayný deðilse çýk
		} else {
			// ayný ise bir sonraki harfe geçilir
			s.pop();
		}
	}

	cout << " a palindrome" << endl;
	 
    return 0;
};

