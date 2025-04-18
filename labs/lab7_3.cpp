#include <iostream>
#include <queue>
using namespace std;

// Queue

void print(queue <int> q) {
	// void fonksiyonuna stack'in kopyasý gönderildiði asýl queue bozulmaz
	cout << "Queue: ";
	
	// queue boþ olana kadar
	while(!q.empty()) {
		// ilk girene yani front'a bak
		cout << q.front() << " ";
		
		// front'u at sýradan devam et
		q.pop();
	}
	
	cout << endl;
}

int main()
{
	queue <int> q1;
	
	// push --> eleman koyar --> enqueue
	// (back) 30 20 10 (front)
	// O(1)
	q1.push(10); 
	q1.push(20); 
	q1.push(30);
	
	// FIFO (First In First Out)
	print(q1);
	
	// empty() --> boþ mu kontrol
	if (q1.empty()) {
		cout << "The queue is empty" << endl;
	} else {
		cout << "The queue is NOT empty" << endl;
	}
	
	// size() --> uzunluk
	cout << "The number of elements: " << q1.size() << endl;
	
	// front() --> en öndekini verir (ilk gireni)
	cout << "First(Front) element: " << q1.front() << endl;
	
	// back() --> son gireni, en arkadakini, verir
	cout << "Last(Back) element: " << q1.back() << endl; 
	
	// pop() --> en öndeki elemaný çýkarýr --> dequeue
	// O(1)
	q1.pop();
	cout << "Popped the first element" << endl;
	cout << "first element: " << q1.front() << endl;
	
    return 0;
};

