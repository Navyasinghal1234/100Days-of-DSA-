//Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

#include <stdio.h>

int main() {
    int n, i, j, flag = 1;

    scanf("%d", &n);  // Read size of matrix
    int mat[n][n];
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if((i == j && mat[i][j] != 1) || (i != j && mat[i][j] != 0)) {
                flag = 0;
                break;
            }
        }
    }
    if(flag)
        printf("Identity Matrix\n");
    else
        printf("Not an Identity Matrix\n");
    return 0;
}
