#include <iostream>
using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void selection_sort(int num_array[], int n) {
	for(int i = 0; i < n - 1; i++) {
		int min_index = i;

		for(int j = i + 1; j < n; j++) {
			if(num_array[j] < num_array[min_index]) {
				min_index = j;
			}
		}
		swap(num_array[i], num_array[min_index]);
	}
}

void print_array(int num_array[], int n) {
	for(int i = 0; i < n; i++) {
		cout << num_array[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = { 5, 34, 1, 17, 4, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Before: ";
	print_array(arr, n);

	selection_sort(arr, n);

	cout << "After: ";
	print_array(arr, n);

	return 0;
}

