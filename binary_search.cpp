#include <iostream>
using namespace std;

class BinarySearch
{
public:
    int binary_search(int wanted_number, int number_array[], int array_size);
};

int BinarySearch::binary_search(int wanted_number, int number_array[], int array_size)
{
    int low = 0; 
	int high = array_size - 1;
	int mid;

    while (low <= high)
    {
        mid = low + (high - low) / 2; 

        if (number_array[mid] == wanted_number)
        {
            cout << "Number " << wanted_number << " has been found at index: " << mid << endl;
            return mid;
        }
        else if (number_array[mid] > wanted_number)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << "Number " << wanted_number << " could not be found" << endl;
    return -1;
}

int main()
{
    int sorted_num_array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Bulunan örnek
    int wanted_num = 5;

    // Bulunmayan örnek
    //int wanted_num = 23;

    BinarySearch search_alg;
    search_alg.binary_search(wanted_num, sorted_num_array, 10);

    return 0;
}

