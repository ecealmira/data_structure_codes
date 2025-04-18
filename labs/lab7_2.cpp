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
	int n2 = n/2; // harfin ortas�na kadar
	
	for(i=0; i < n2; i++) {
		// stack'e koyulurken ters �evrilecek
		s.push(str[i]);
	}
	
	// tek say� ise sonu� 1, yani true
	if(n%2) {
		i++; // ortadaki harfi atlar�z
	}
	
	// i kald��� yerden devam etsin diye ilk ba� bo�
	cout << "\"" << str  << "\"" << " is";
	for(; i<n; i++) {
		// string in ba�� ile stack in ba�� kar��la�t�r�l�r
		if(str[i]!=s.top()){
			cout << " not";
			break; // ayn� de�ilse ��k
		} else {
			// ayn� ise bir sonraki harfe ge�ilir
			s.pop();
		}
	}

	cout << " a palindrome" << endl;
	 
    return 0;
};

