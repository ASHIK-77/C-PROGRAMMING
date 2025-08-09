#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1, n1, *queue;

void add(int n) {
    printf("Enter the number of elements to enqueue: ");
    scanf("%d", &n1);

    if ((rear + 1) % n == front) {  
        printf("Overflow - The queue is full!\n");
    } else {
        printf("Enter the elements:\n");
        for (int i = 0; i < n1; i++) {
            if (front == -1) {
                front = 0;
            }
            rear = (rear + 1) % n;
            scanf("%d", &queue[rear]);
        }
    }
}

void deletion(int n) {
    printf("Enter the number of elements to dequeue: ");
    scanf("%d", &n1);

    if (front == -1) {
        printf("Underflow!!!\n");
    } else {
        for (int i = 0; i < n1; i++) {
            printf("Deleted %d\n", queue[front]);
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % n;
            }
        }
    }
}

void display(int n) {
    if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % n;
        }
        printf("%d ", queue[rear]);
        printf("\n");
    }
}

int main() {
    int choice, n;  
    printf("Enter the size of the queue: ");
    scanf("%d", &n);
    
    queue = (int*)malloc(n * sizeof(int));

    if (queue == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add(n);  
                break;
            case 2:
                deletion(n);  
                break;
            case 3:
                display(n);  
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid input!!!\n");
        }
    } while (choice != 4);

    free(queue);
    return 0;
}
