//Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}
int isEmpty(Queue *q) {
    return q->rear < q->front;
}
void enqueue(Queue *q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    q->items[++q->rear] = value;
}
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    return q->items[q->front++];
}
int main() {
    int V, E;
    int adj[MAX][MAX] = {0};  // Adjacency matrix
    int indegree[MAX] = {0};
    int u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    printf("Enter edges (u v) meaning u -> v:\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }
    Queue q;
    initQueue(&q);
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            enqueue(&q, i);
        }
    }
    int topo[MAX];
    int count = 0;
    while (!isEmpty(&q)) {
        int node = dequeue(&q);
        topo[count++] = node;
        for (int i = 0; i < V; i++) {
            if (adj[node][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    enqueue(&q, i);
                }
            }
        }
    }
    if (count != V) {
        printf("Cycle detected! Topological sort not possible.\n");
    } else {
        printf("Topological Order:\n");
        for (int i = 0; i < count; i++) {
            printf("%d ", topo[i]);
        }
        printf("\n");
    }
    return 0;
}
