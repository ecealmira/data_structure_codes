#include <iostream>
#include <deque>
using namespace std;

// Deque(Double-Ended Queue)

void print(deque <int> d) {
	// void fonksiyonuna stack'in kopyasý gönderildiði asýl queue bozulmaz
	cout << "Deque: ";
	
	// queue boþ olana kadar
	while(!d.empty()) {
		// ilk girene yani front'a bak
		cout << d.front() << " ";
		
		// front'u at sýradan devam et
		d.pop_front();
	}
	
	cout << endl;
}

int main(){
	// create a deque
	deque <int> d1;
	
	// push_front() --> enqueue at the front, insert an element at the beginning of the deque
	d1.push_front(2);
	d1.push_front(3);
	print(d1);
	
	// push_back() --> dequeue from the back, add an element at the end
	d1.push_back(1);
	d1.push_back(4);
	print(d1);
	
	// empty
	if (d1.empty()) {
		cout << "The deque is empty" << endl;
	} else {
		cout << "The deque is NOT empty" << endl;
	}
		
	// size
	cout << "The number of elements: " << d1.size() << endl;
	
	// front
	cout << "First(Front) element: " << d1.front() << endl;
	
	// back
	cout << "Last(Back) element: " << d1.back() << endl; 
	
	// pop_front() --> remove an element from the beginning of the deque
	cout << "Popped the first element" << endl;
	d1.pop_front();
	print(d1);
	
	// pop_back() --> remove an element at the end
	cout << "Popped the last element" << endl;
	d1.pop_back();
	print(d1);
	
	// at() --> access an element at a specified index
	cout << "Second element " << d1.at(1) << endl;
	return 0;
}
