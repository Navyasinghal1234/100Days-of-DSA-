//Implement a hash table using quadratic probing with formula:

//h(k, i) = (h(k) + i*i) % m
#include <stdio.h>
#include <string.h>
#define EMPTY -1
int table[100];  
int hashFunction(int key, int m) {
    return key % m;
}
void insert(int key, int m) {
    int i = 0;
    int index;
    while (i < m) {
        index = (hashFunction(key, m) + i * i) % m;
        if (table[index] == EMPTY) {
            table[index] = key;
            return;
        }
        i++;
    }
    printf("Hash table is full, cannot insert %d\n", key);
}
void search(int key, int m) {
    int i = 0;
    int index;
    while (i < m) {
        index = (hashFunction(key, m) + i * i) % m;
        if (table[index] == key) {
            printf("FOUND\n");
            return;
        }
        if (table[index] == EMPTY) {
            printf("NOT FOUND\n");
            return;
        }

        i++;
    }
    printf("NOT FOUND\n");
}
int main() {
    int m, q;
    char operation[10];
    int key;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%s %d", operation, &key);

        if (strcmp(operation, "INSERT") == 0) {
            insert(key, m);
        } 
        else if (strcmp(operation, "SEARCH") == 0) {
            search(key, m);
        }
    }
    return 0;
}
