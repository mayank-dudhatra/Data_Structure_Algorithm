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

    int hashFunction(int key, int i) {
        return (key + i) % size; // linear probing
    }

    void insert(int key, int value, int i = 0) {
        int index = hashFunction(key, i);

        if (i == size) { // tried all slots
            cout << "Hash Table Full! Cannot insert " << value << endl;
            return;
        }

        if (table[index] == -1) {
            table[index] = value;
        } else {
            insert(key, value, i + 1); // try next slot
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
    HashTable table(6);

    table.insert(1, 12);
    table.insert(2, 13);
    table.insert(3, 23);
    table.insert(4, 33);
    table.insert(5, 42);
    table.insert(6, 32);
    table.insert(7, 99); // table full

    cout << "\nHash Table:\n";
    table.display();

    return 0;
}
