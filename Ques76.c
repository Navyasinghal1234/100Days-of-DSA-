//Using DFS or BFS, count number of connected components.
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int adj[MAX][MAX]; 
int visited[MAX];    
int n, m;
void dfs(int node) {
    visited[node] = 1;
    for (int i = 1; i <= n; i++) {
        if (adj[node][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}
int countComponents() {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            dfs(i);
            count++;
        }
    }
    return count;
}
int main() {
    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        for (int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;  // Undirected graph
    }

    int result = countComponents();
    printf("Number of connected components: %d\n", result);

    return 0;
}
