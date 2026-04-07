// Detect cycle in directed graph using DFS and recursion stack.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;
Node* adj[MAX];
bool visited[MAX];
bool recStack[MAX];
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
}
bool dfs(int node) {
    visited[node] = true;
    recStack[node] = true;
    Node* temp = adj[node];
    while (temp != NULL) {
        int neighbor = temp->vertex;
        if (!visited[neighbor]) {
            if (dfs(neighbor))
                return true;
        }
        else if (recStack[neighbor]) {
            return true;
        }
        temp = temp->next;
    }
    recStack[node] = false;
    return false;
}
bool hasCycle(int V) {
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
    }
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return true;
        }
    }
    return false;
}
int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
    }
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v); 
    }
    if (hasCycle(V))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
