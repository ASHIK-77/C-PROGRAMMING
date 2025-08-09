#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1, n;
int *stack;

void FE(int val) {
    if ((front == 0 && rear == n - 1) || (front == rear + 1)) {
        printf("Overflow at front\n");
        return;
    }
    if (front == -1) { 
        front = rear = 0;
    } else if (front == 0) {
        front = n - 1;
    } else {
        front--;
    }
    stack[front] = val;
}

void RE(int val) {
    if ((rear == n - 1 && front == 0) || (rear + 1) % n == front) {
        printf("Overflow at rear\n");
        return;
    }
    if (rear == -1) { 
        front = rear = 0;
    } else if (rear == n - 1) {
        rear = 0;
    } else {
        rear++;
    }
    stack[rear] = val;
}

void FD() {
    if (front == -1) {
        printf("Underflow at front\n");
        return;
    }
    printf("Dequeued from front: %d\n", stack[front]);
    if (front == rear) { 
        front = rear = -1;
    } else if (front == n - 1) {
        front = 0;
    } else {
        front++;
    }
}

void RD() {
    if (rear == -1) {
        printf("Underflow at rear\n");
        return;
    }
    printf("Dequeued from rear: %d\n", stack[rear]);
    if (front == rear) { 
        front = rear = -1;
    } else if (rear == 0) {
        rear = n - 1;
    } else {
        rear--;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("DEQUEUE IS: ");
    int i = front;
    while (1) {
        printf("%d ", stack[i]);
        if (i == rear)
            break;
        i = (i + 1) % n;
    }
    printf("\n");
}

int main() {
    int choice, value;
    printf("Enter the size of queue: ");
    scanf("%d", &n);
    stack = (int*) malloc(n * sizeof(int));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }

    do {
        printf("\n1. Front Enqueue\n2. Rear Enqueue\n3. Front Dequeue\n4. Rear Dequeue\n5. Display\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value (Front Enqueue): ");
                scanf("%d", &value);
                FE(value);
                break;
            case 2:
                printf("Enter the value (Rear Enqueue): ");
                scanf("%d", &value);
                RE(value);
                break;
            case 3:
                FD();
                break;
            case 4:
                RD();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid input\n");
        }
    } while (choice != 6);

    free(stack);
    return 0;
}
