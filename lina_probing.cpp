#include <iostream>
#include <vector>

using namespace std;

class HashTable {
private:
    vector<pair<int, string>> table; // table to hold key-value pairs
    int size; // number of key-value pairs in the table
    int capacity; // maximum number of key-value pairs the table can hold
    int hash(int key); // hash function to map keys to indices in the table
    int probe(int index); // linear probing function to find next available index in case of collision
public:
    HashTable(int capacity); // constructor to initialize the hash table
    void insert(int key, string value); // insert a key-value pair into the table
    string get(int key); // get the value associated with a key in the table
    void remove(int key); // remove a key-value pair from the table
    void print(); // print the contents of the table
};

HashTable::HashTable(int capacity) {
    this->table = vector<pair<int, string>>(capacity, make_pair(-1, ""));
    this->size = 0;
    this->capacity = capacity;
}

int HashTable::hash(int key) {
    return key % this->capacity;
}

int HashTable::probe(int index) {
    return (index + 1) % this->capacity;
}

void HashTable::insert(int key, string value) {
    int index = hash(key);

    // Linear probing until an empty or deleted slot is found
    while (this->table[index].first != -1 && this->table[index].first != key) {
        index = probe(index);
    }

    // Update value if key already exists
    if (this->table[index].first == key) {
        this->table[index].second = value;
    }
    // Add key-value pair to table if key does not exist
    else {
        this->table[index] = make_pair(key, value);
        this->size++;
    }
}

string HashTable::get(int key) {
    int index = hash(key);

    // Linear probing until key is found or an empty or deleted slot is encountered
    while (this->table[index].first != -1) {
        if (this->table[index].first == key) {
            return this->table[index].second; // Return value if key is found
        }
        index = probe(index);
    }

    // Return empty string if key is not found
    return "";
}

void HashTable::remove(int key) {
    int index = hash(key);

    // Linear probing until key is found or an empty or deleted slot is encountered
    while (this->table[index].first != -1) {
        if (this->table[index].first == key) {
            this->table[index] = make_pair(-1, ""); // Mark slot as deleted
            this->size--;
            return;
        }
        index = probe(index);
    }
}

void HashTable::print() {
    for (int i = 0; i < this->capacity; i++) {
        cout << "[" << i << "]: (" << this->table[i].first << ", " << this->table[i].second << ")" << endl;
    }
}

int main() {
    HashTable ht(5);

    ht.insert(1, "apple");
    ht.insert(2, "banana");
    ht.insert(3, "cherry");
    ht.insert(4, "date");
    ht.insert(5, "elderberry");

    ht.print();

    cout << "Value for key 3: " << ht.get(3) << endl;
}
