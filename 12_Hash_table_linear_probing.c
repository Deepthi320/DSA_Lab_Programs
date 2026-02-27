/*
 * Program: Hash Table using Linear Probing
 * Description:
 * This program inserts N employee keys into a hash table of size M
 * using linear probing for collision resolution and displays the hash table.
 */

#include <stdio.h>
#include <stdlib.h>

int key[20], n, m;   // Array of keys, number of keys, size of hash table
int *ht;             // Hash table pointer
int index;           
int count = 0;       // Count of keys inserted

/* Insert key into hash table using linear probing */
void insert(int key) {
    index = key % m;       // Hash function: key mod table size
    while(ht[index] != -1) {
        index = (index + 1) % m;   // Linear probing in case of collision
    }
    ht[index] = key;
    count++;
}

/* Display Hash Table */
void display() {
    int i;
    if(count == 0) {
        printf("\nHash Table is empty\n");
        return;
    }
    printf("\nHash Table contents are:\n");
    for(i = 0; i < m; i++)
        printf("T[%d] --> %d\n", i, ht[i]);
}

int main() {
    int i;

    printf("\nEnter the number of employee records (N): ");
    scanf("%d", &n);

    printf("\nEnter the hash table size (m): ");
    scanf("%d", &m);

    // Allocate memory for hash table and initialize with -1
    ht = (int *)malloc(m * sizeof(int));
    for(i = 0; i < m; i++)
        ht[i] = -1;

    printf("\nEnter the four-digit key values for N employee records:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &key[i]);

    for(i = 0; i < n; i++) {
        if(count == m) {
            printf("\n~~~Hash table is full. Cannot insert record %d key~~~\n", i+1);
            break;
        }
        insert(key[i]);
    }

    // Display hash table
    display();

    free(ht);
    return 0;
}

Enter the number of employee records (N): 12
Enter the hash table size (m): 15
Enter the four-digit key values for N employee records:
2541
1487
6547
2165
1563
4521
1354
6524
1356
1564
5142
8542

Hash Table contents are:
T[0] --> -1
T[1] --> -1
T[2] --> 1487
T[3] --> 1563
T[4] --> 1354
T[5] --> 2165
T[6] --> 2541
T[7] --> 6547
T[8] --> 4521
T[9] --> 1356
T[10] --> 1564
T[11] --> 8542
T[12] --> 5142
T[13] --> -1
T[14] --> 6524
