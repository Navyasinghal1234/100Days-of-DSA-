// Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order. */

#include <stdio.h>
int main() {
    int n, i, j;
    int a[100];
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    j = 0;
    for(i = 1; i < n; i++) {
        if(a[i] != a[j]) {
            j++;
            a[j] = a[i];
        }
    }
    for(i = 0; i <= j; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
