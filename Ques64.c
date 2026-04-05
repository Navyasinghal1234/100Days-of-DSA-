//Perform BFS from a given source using queue.

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct Queue {
    int items[MAX];
    int front, rear;
} Queue;
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}
int isEmpty(Queue* q) {
    return q->front == -1;
}
void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->items[++q->rear] = value;
}
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front >= q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return item;
}
void BFS(Node* adj[], int n, int start) {
    int visited[MAX] = {0};
    Queue q;
    initQueue(&q);
    visited[start] = 1;
    enqueue(&q, start);
    printf("BFS Traversal: ");
    while (!isEmpty(&q)) {
        int current = dequeue(&q);
        printf("%d ", current);

        Node* temp = adj[current];
        while (temp != NULL) {
            int adjNode = temp->data;
            if (!visited[adjNode]) {
                visited[adjNode] = 1;
                enqueue(&q, adjNode);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}
int main() {
    int n, edges, u, v, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    Node* adj[MAX] = {NULL};
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
      
        Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }
    printf("Enter source vertex: ");
    scanf("%d", &start);
    BFS(adj, n, start);
    return 0;
}
