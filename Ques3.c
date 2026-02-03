// Implement linear search to find key k in an array. Count and display the number of comparisons performed.

#include <stdio.h>

int main() {
    int n, k;
    int count = 0;
    int found = 0;
scanf("%d", &n);         
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); 
    }
    scanf("%d", &k);          
    for (int i = 0; i < n; i++) {
        count++;            
        if (arr[i] == k) {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("Not Found\n");
    }
    printf("Comparisons = %d\n", count);

    return 0;
}
