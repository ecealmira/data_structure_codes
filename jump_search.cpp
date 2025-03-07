#include <iostream>
#include <cmath>
using namespace std;

class JumpSearch
{
public:
    int jump_search(int wanted_number, int num_array[], int array_size);
};

int JumpSearch::jump_search(int wanted_number, int num_array[], int array_size)
{
    int step_size = sqrt(array_size);
    int prev = 0;
    
    // Array in dışına çıkmayacak şekilde istenen sayıdan büyük olana kadar step_size ekle
    while (prev < array_size && num_array[min(prev + step_size, array_size) - 1] < wanted_number)
    {
        prev += step_size;
        if (prev >= array_size)
        {
            cout << "Number " << wanted_number << " could not be found" << endl;
            return -1;
        }
    }

	// prev'den başlayarak linear search yap
    for (int i = prev; i < min(prev + step_size, array_size); i++)
    {
        if (num_array[i] == wanted_number)
        {
            cout << "Number " << wanted_number << " has been found at index: " << i << endl;
            return i;
        }
    }

    cout << "Number " << wanted_number << " could not be found" << endl;
}

int main()
{
    int sorted_num_array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Bulunan Örnek
    int wanted_num = 8;

    // Bulunmayan örnek
    // int wanted_num = 23; 

    JumpSearch search_alg;
    search_alg.jump_search(wanted_num, sorted_num_array, 10);

    return 0;
}

