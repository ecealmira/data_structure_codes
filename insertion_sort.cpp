#include <iostream>
using namespace std;

void insertionSort(int num_array[], int array_size)
{
    for (int i = 1; i < array_size; ++i) 
	{
        int j = i;

        while (j > 0 && num_array[j] < num_array[j-1]) 
		{
			int temp = num_array[j];
			num_array[j] = num_array[j-1];
			num_array[j-1] = temp;
            j = j - 1;
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {12,27,34,11,45,29,8,17,4,31};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}

