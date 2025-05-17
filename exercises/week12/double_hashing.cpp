#include <iostream>
using namespace std;

// Hash Table
// Double Hashing

#include <iostream>
using namespace std;

enum Status { Empty, Legitimate, Deleted };

class HashEntry {
	public:
    int element;
    Status info;

    HashEntry() {
        element = 0;
        info = Empty;
    }
};

class HashTable {
    HashEntry* table;
    int size;
    int p1 = 11;
    int p2 = 7;

	public:
	    HashTable(int s);
	    ~HashTable();
	    int hashFun1(int x);
	    int hashFun2(int x);
	    int search(int k);
	    void insert(int k);
	    void display();
	    void rehash();
};

HashTable::HashTable(int s) {
    size = s;
    table = new HashEntry[size];
}

HashTable::~HashTable() {
    delete[] table;
}

int HashTable::hashFun1(int x) {
    return x % p1;
}

int HashTable::hashFun2(int x) {
    return p2 - (x % p2);
}

int HashTable::search(int k) {
    int hashVal = hashFun1(k);
    int stepSize = hashFun2(k);
    int i = 0;

    while (table[hashVal].info != Empty && table[hashVal].element != k) {
        i++;
        hashVal = (hashVal + stepSize) % size;
        if (i > size){
			return -1;
		}
    }
    return hashVal;
}

void HashTable::insert(int k) {
    int pos = search(k);
    if (pos == -1) {
        cout << "Table is full or rehash needed.\n";
        return;
    }

    if (table[pos].info != Legitimate) {
        table[pos].element = k;
        table[pos].info = Legitimate;
    }
}

void HashTable::display() {
    for (int i = 0; i < size; i++) {
        if (table[i].info == Legitimate)
            cout << "Position: " << i << " Element: " << table[i].element << endl;
        else
            cout << "Position: " << i << " Element: Null" << endl;
    }
}

void HashTable::rehash() {
    int oldSize = size;
    HashEntry* oldTable = table;

    size = 2 * oldSize;
    table = new HashEntry[size];

    for (int i = 0; i < oldSize; i++) {
        if (oldTable[i].info == Legitimate)
            insert(oldTable[i].element);
    }
    delete[] oldTable;
}

int main() {
    HashTable ht(13);
    
    int numbers[] = {42, 12, 7, 92, 73, 25, 17, 69, 10, 11, 14, 15};
    for (int i = 0; i < 12; i++)
        ht.insert(numbers[i]);
        
    ht.display();

    return 0;
}

