//Given weighted graph with non-negative edges, compute shortest path from source using priority queue.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 100
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};
struct Graph {
    int V;
    struct Node* adj[MAX];
};
struct PQNode {
    int vertex;
    int dist;
};
struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}
void addEdge(struct Graph* graph, int u, int v, int w) {
    struct Node* newNode = createNode(v, w);
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;
}
struct PQNode pq[MAX];
int size = 0;
void swap(struct PQNode* a, struct PQNode* b) {
    struct PQNode temp = *a;
    *a = *b;
    *b = temp;
}
void heapifyUp(int i) {
    while (i && pq[(i - 1) / 2].dist > pq[i].dist) {
        swap(&pq[i], &pq[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && pq[left].dist < pq[smallest].dist)
        smallest = left;
    if (right < size && pq[right].dist < pq[smallest].dist)
        smallest = right;
    if (smallest != i) {
        swap(&pq[i], &pq[smallest]);
        heapifyDown(smallest);
    }
}
void push(int v, int dist) {
    pq[size].vertex = v;
    pq[size].dist = dist;
    heapifyUp(size);
    size++;
}
struct PQNode pop() {
    struct PQNode root = pq[0];
    pq[0] = pq[size - 1];
    size--;
    heapifyDown(0);
    return root;
}
int isEmpty() {
    return size == 0;
}
void dijkstra(struct Graph* graph, int src) {
    int dist[MAX];
    for (int i = 0; i < graph->V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
    push(src, 0);
    while (!isEmpty()) {
        struct PQNode current = pop();
        int u = current.vertex;
        struct Node* temp = graph->adj[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                push(v, dist[v]);
            }
            temp = temp->next;
        }
    }
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < graph->V; i++)
        printf("%d\t%d\n", i, dist[i]);
}
int main() {
    int V = 5;
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    for (int i = 0; i < V; i++)
        graph->adj[i] = NULL;

    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 4, 5);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 4, 1, 3);
    addEdge(graph, 4, 2, 9);
    addEdge(graph, 2, 3, 4);

    int source = 0;
    dijkstra(graph, source);

    return 0;
}
