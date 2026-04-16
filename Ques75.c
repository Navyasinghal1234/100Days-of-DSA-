//Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
typedef struct {
    int sum;
    int index;
} Hash;
int maxLenZeroSum(int arr[], int n) {
    Hash hash[MAX];
    int size = 0;
    int sum = 0;
    int max_len = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == 0) {
            max_len = i + 1;
        }
        int found = 0;
        for (int j = 0; j < size; j++) {
            if (hash[j].sum == sum) {
                int len = i - hash[j].index;
                if (len > max_len)
                    max_len = len;
                found = 1;
                break;
            }
        }
        if (!found) {
            hash[size].sum = sum;
            hash[size].index = i;
            size++;
        }
    }
    return max_len;
}
int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = maxLenZeroSum(arr, n);

    printf("Length of longest subarray with sum 0: %d\n", result);

    return 0;
}
