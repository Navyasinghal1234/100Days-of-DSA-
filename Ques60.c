#include <stdio.h>

#define MAX 100

int main() {
    int n, m;
    int adj[MAX][MAX] = {0};
    int u, v;
    int isDirected;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);
    printf("Enter 1 for Directed Graph, 0 for Undirected Graph: ");
    scanf("%d", &isDirected);
    printf("Enter edges (u v):\n");
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;

        if(!isDirected) {
            adj[v][u] = 1;  // for undirected graph
        }
    }
    printf("\nAdjacency Matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
