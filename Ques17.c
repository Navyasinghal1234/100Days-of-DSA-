//Write a program to find the maximum and minimum values present in a given array of integers.
#include <stdio.h>
int main() {
    int n, i;
    int arr[100];
    int max, min;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    max = arr[0];
    min = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    printf("Maximum = %d\n", max);
    printf("Minimum = %d\n", min);

    return 0;
}
