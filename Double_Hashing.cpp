#include <iostream>
#include <vector>
using namespace std;

class HashTable {
    vector<int> table;
    int size;

public:
    HashTable(int s) {
        size = s;
        table.resize(size, -1);
    }

    int h1(int key) {
        return key % size;
    }

    int h2(int key) {
        // pick a prime smaller than table size
        int prime = size - 1; 
        return prime - (key % prime);
    }

    void insert(int key, int value) {
        int index = h1(key);
        int step = h2(key);
        int i = 0;

        while (table[(index + i * step) % size] != -1 && i < size) {
            i++;
        }

        if (i < size) {
            table[(index + i * step) % size] = value;
        } else {
            cout << "Hash table full, cannot insert " << value << endl;
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << " --> ";
            if (table[i] == -1)
                cout << "Empty";
            else
                cout << table[i];
            cout << endl;
        }
    }
};

int main() {
    HashTable table(7); // size should be prime for better performance

    table.insert(1, 12);
    table.insert(2, 13);
    table.insert(3, 23);
    table.insert(4, 33);
    table.insert(5, 42);
    table.insert(6, 32);

    table.display();
}
