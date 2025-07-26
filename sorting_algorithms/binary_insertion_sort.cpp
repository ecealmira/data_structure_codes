#include <iostream>
using namespace std;

int binary_search(int num_array[], int left, int right, int num) {
	while (left <= right) {
		int mid = (left + right) / 2;
		
		if (num_array[mid] == num) {
			return mid;
		} else if (num_array[mid] < num) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	return left;
}

void binary_insertion_sort(int num_array[], int n) {
	for (int i = 1; i < n; i++) {
		int curr = num_array[i];
		int j = i - 1;

		int curr_location = binary_search(num_array, 0, j, curr);
		
		while (j >=  curr_location) {
			num_array[j + 1] = num_array[j];
			j--;
		}
		num_array[j + 1] = curr;
	}
}

void print_array(int num_array[], int n) {
	for(int i=0; i<n; i++) {
		cout << num_array[i] << " ";
	}
}

int main()
{
    int arr[] = { 5,34,1,17,4,9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Before: ";
    print_array(arr, n);
    cout << endl;
    
    binary_insertion_sort(arr, n);
    
    cout << "After: ";
    print_array(arr, n);
    cout << endl;
    
    return 0;
};

