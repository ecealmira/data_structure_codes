#include <iostream>
using namespace std;

class LinearSearch
{
	public:
    	int search(int wanted_number, int search_array[], int size);
};

int LinearSearch::search(int wanted_number, int search_array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (search_array[i] == wanted_number)
        {
        	// Bulunan index numarasını döndürür (0'dan saymaya başlıyor)
            cout << "Number " << wanted_number << " has been found at index: " << i << endl;
            return i; 
        }
    }
    cout << "Number " << wanted_number << " could not be found" << endl;
}

int main()
{
    int num_array[10] = {42, 7, 18, 95, 63, 29, 84, 12, 56, 37};
    
    // Bulunan örnek
    int wanted_num = 84;
    
    // Bulunamayan örnek
    // int wanted_num = 23; 
    
    LinearSearch lin_search;
    lin_search.search(wanted_num, num_array, 10);
    
    return 0;
}

