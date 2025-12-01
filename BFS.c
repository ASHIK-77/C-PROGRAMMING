#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

// Enqueue an element
void enqueue(int v) {
    if (rear == MAX - 1) {
        printf("Queue overflow!\n");
        return;
    }
    queue[++rear] = v;
}

// Dequeue an element
int dequeue() {
    if (front > rear) {
        printf("Queue underflow!\n");
        return -1;
    }
    return queue[front++];
}

// Check if queue is empty
int isEmpty() {
    return front > rear;
}

// BFS function
void BFS(int n, int adj[MAX][MAX], int start) {
    int visited[MAX] = {0};

    enqueue(start);
    visited[start] = 1;

    printf("BFS traversal starting from vertex %d:\n", start);

    while (!isEmpty()) {
        int v = dequeue();
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n;
    int adj[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    BFS(n, adj, start);

    return 0;
}
