#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1, *queue;

void Enqueue(int n) {
    int value;

    if (rear == n - 1) {
        printf("Overflow!!!\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &value);

    if (front == -1)  // first insertion
        front = 0;

    rear++;
    queue[rear] = value;
}

void Dequeue() {
    if (front == -1 || front > rear) {
        printf("Underflow!!!\n");
        front = rear = -1;
    } else {
        printf("Dequeued element = %d\n", queue[front]);
        front++;
    }
}

void Display() {
    if (front == -1 || front > rear) {
        printf("Queue Empty!!\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int n, choice;

    printf("Enter the size of queue: ");
    scanf("%d", &n);

    queue = (int *)malloc(n * sizeof(int));
    if (queue == NULL) {
        printf("Memory allocation failed!\n");
        return 0;
    }

    do {
        printf("-----------------------\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: Enqueue(n); break;
            case 2: Dequeue(); break;
            case 3: Display(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid input...\n");
        }

    } while (choice != 4);

    free(queue);
    return 0;
}
