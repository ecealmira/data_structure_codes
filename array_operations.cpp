#include <iostream>
using namespace std;

class ArrayOperations 
{
public:
    ArrayOperations();  
    int access(int num_array[], int index);
    int search(int num_array[], int target_num, int array_size);
    int deletion(int num_array[], int target_num, int& array_size);
    int insertion(int num_array[], int target_num, int& array_size);
};

ArrayOperations::ArrayOperations() {}

// Access an element at a given index
int ArrayOperations::access(int num_array[], int index) 
{
    cout << "Number at index " << index << " is: " << num_array[index] << endl;
    return num_array[index];
}

// Search for a number in the array (Linear search)
int ArrayOperations::search(int num_array[], int target_num, int array_size) 
{
    for (int i = 0; i < array_size; i++) {
        if (num_array[i] == target_num) {
            cout << target_num << " is found at index " << i << endl;
            return i;
        }
    }
    cout << target_num << " cannot be found" << endl;
    return -1;  
}

// Delete an element and shift elements left
int ArrayOperations::deletion(int num_array[], int target_num, int& array_size) 
{
    int pos = search(num_array, target_num, array_size);
    if (pos == -1) return array_size; // If not found, do nothing

    for (int i = pos; i < array_size - 1; i++) {
        num_array[i] = num_array[i + 1];
    }
    
    // Reduce size
    array_size--;  
    return array_size;
}

int ArrayOperations::insertion(int num_array[], int target_num, int& array_size) 
{
    if (array_size >= 100) 
	{ // Assume 100 is the max size
        cout << "Array is full, cannot insert." << endl;
        return array_size;
    }

    // Find the correct position to insert target_num
    int pos = 0;
    while (pos < array_size && num_array[pos] < target_num) {
        pos++;
    }

    // Shift elements to the right to make space
    for (int i = array_size; i > pos; i--) {
        num_array[i] = num_array[i - 1];
    }

    // Insert the target number
    num_array[pos] = target_num;
    array_size++; // Increase array size

    return array_size;
}


// Overloading operator<< to print array
ostream& operator<<(ostream& s, const int num_array[])
{
    s << "Array: [";
    for (int i = 0; i < 9; i++) {
        s << num_array[i];
        if (i < 8) s << ", ";
    }
    s << "]";
    return s;
}

int main() 
{
	// Allocate extra space for insertions
    int num_array[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    int array_size = 9; 

	// print array using operation overloading
    cout << num_array << endl;

    ArrayOperations operation;
    
    // Find 4
    operation.access(num_array, 4);
    
    // search for the index of 5
    operation.search(num_array, 5, array_size);
    
    // delete 5 from the array
    operation.deletion(num_array, 5, array_size);
    cout << "Array after deletion:" << endl;
    cout << num_array << endl;
    
    // insert 5 back into the array
    operation.insertion(num_array, 5, array_size);
    cout << "Array after insertion:" << endl;
    cout << num_array << endl;

    return 0;
}
