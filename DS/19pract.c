// Create a struct called HashNode that contains three fields: an int called key, an int called value, and a pointer to another HashNode called next.

//     Create a struct called HashTable that contains a single field, a pointer to an array of HashNode pointers called table.

//     Define a function called createHashTable() that allocates memory for a new HashTable struct and its table array, then initializes all the elements in the array to NULL.

//     Define a function called hashFunction(int key) that takes an int as input and returns the index in the table array where the key-value pair should be stored. In this case the hash function is very simple, it takes the key mod table size.

//     Define a function called insert(struct HashTable* ht, int key, int value) that takes a pointer to a HashTable, an int key, and an int value as input. It calculates the index of the array using the hashFunction(key), creates a new HashNode struct with the given key and value, sets the next pointer of the new struct to the current head of the linked list at that index, and then makes the new struct the new head of the linked list.

//     Define a function called search(struct HashTable* ht, int key) that takes a pointer to a HashTable and an int key as input. It calculates the index of the array using the hashFunction(key), sets a pointer called entry to the head of the linked list at that index.
//     Then it traverse the linked list starting at entry until entry is NULL, it compares the key of each HashNode with the given key and returns the value if it matches otherwise returns -1 if it reached end of the linked list and key is not found.

//     In the main() function, create a new HashTable struct using the createHashTable() function, then insert some key-value pairs using the insert() function, and finally search for some keys using the search() function, displaying the result of each search.

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 128

struct HashNode {
    int key;
    int value;
    struct HashNode* next;
};

struct HashTable {
    struct HashNode** table;
};

struct HashTable* createHashTable() {
    struct HashTable* ht = (struct HashTable*)malloc(sizeof(struct HashTable));
    ht->table = (struct HashNode**)malloc(TABLE_SIZE * sizeof(struct HashNode*));
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(struct HashTable* ht, int key, int value) {
    int hash = hashFunction(key);
    struct HashNode* newNode = (struct HashNode*)malloc(sizeof(struct HashNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = ht->table[hash];
    ht->table[hash] = newNode;
}

int search(struct HashTable* ht, int key) {
    int hash = hashFunction(key);
    struct HashNode* entry = ht->table[hash];
    while (entry != NULL) {
        if (entry->key == key) {
            return entry->value;
        }
        entry = entry->next;
    }
    return -1;
}

int main() {
    struct HashTable* ht = createHashTable();
    insert(ht, 1, 100);
    insert(ht, 2, 200);
    insert(ht, 3, 300);

    printf("The value at 1 is %d\n", search(ht, 1));
    printf("The value at 2 is %d\n", search(ht, 2));
    printf("The value at 3 is %d\n", search(ht, 3));
    printf("The value at 4 is %d\n", search(ht, 4));

    return 0;
}