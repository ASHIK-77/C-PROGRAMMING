#include <stdio.h>

#define SIZE 10
int hashTable[SIZE];
int DELETED = -2;

int search(int key);   // <-- FIXED

void initTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }
}

int hashfn(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashfn(key);
    int start = index;

    while (hashTable[index] != -1 && hashTable[index] != DELETED) {
        index = (index + 1) % SIZE;

        if (index == start) {
            printf("Table full!!");
            return;
        }
    }
    hashTable[index] = key;
    printf("Key %d added at %d\n", key, index);
}

void delete(int key) {
    int index = search(key);

    if (index == -1) {
        printf("Key not found!!!\n");
        return;
    }

    hashTable[index] = DELETED;
    printf("Key deleted from index %d\n", index);
}

int search(int key) {
    int index = hashfn(key);
    int start = index;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            return index;
        }
        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }
    return -1;
}

void printTable() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {

        if (hashTable[i] == -1)
            printf("%d : NULL\n", i);

        else if (hashTable[i] == DELETED)
            printf("%d : DELETED\n", i);

        else
            printf("%d : %d\n", i, hashTable[i]);
    }
}

int main() {

    int choice, key;
    initTable();

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Print Table\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete(key);
                break;

            case 3:
                printf("Key to search: ");
                scanf("%d", &key);
                int idx = search(key);
                if (idx != -1)
                    printf("%d found at index %d\n", key, idx);
                else
                    printf("%d not found\n", key);
                break;

            case 4:
                printTable();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice!!!");
        }
    }

    return 0;
}
