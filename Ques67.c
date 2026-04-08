//Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int adj[MAX][MAX];  
int visited[MAX];
int stack[MAX];
int top = -1;
void dfs(int node, int V) {
    visited[node] = 1;
    for (int i = 0; i < V; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i, V);
        }
    }
    stack[++top] = node;
}
void topologicalSort(int V) {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, V);
        }
    }
    printf("Topological Order:\n");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}
int main() {
    int V, E;
    int u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }
    printf("Enter edges (u v) where u -> v:\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }
    topologicalSort(V);
    return 0;
}
