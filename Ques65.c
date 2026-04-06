//Using DFS and parent tracking, detect if undirected graph has a cycle.
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;
Node* adj[MAX];
int visited[MAX];
int n;
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
void addEdge(int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}
int dfs(int v, int parent) {
    visited[v] = 1;
    Node* temp = adj[v];
    while (temp != NULL) {
        int adjNode = temp->vertex;
        if (!visited[adjNode]) {
            if (dfs(adjNode, v))
                return 1;
        }
        else if (adjNode != parent) {
            return 1; // Cycle found
        }
        temp = temp->next;
    }
    return 0;
}
int hasCycle() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))
                return 1;
        }
    }
    return 0;
}
int main() {
    int edges, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }
    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    if (hasCycle())
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
