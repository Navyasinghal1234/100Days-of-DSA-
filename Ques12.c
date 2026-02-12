#include <stdio.h>
int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    if (m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }
    int matrix[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                printf("Not a Symmetric Matrix");
                return 0;
            }
        }
    }
    printf("Symmetric Matrix");
    return 0;
}
