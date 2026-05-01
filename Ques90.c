//Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

#include <stdio.h>
int isPossible(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int currSum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxTime)
            return 0;
        if (currSum + arr[i] <= maxTime) {
            currSum += arr[i];
        } else {
            painters++;
            currSum = arr[i];

            if (painters > k)
                return 0;
        }
    }
    return 1;
}
int minTime(int arr[], int n, int k) {
    int low = 0, high = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        high += arr[i];   // total sum
        if (arr[i] > low)
            low = arr[i]; // max element
    }
    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(arr, n, k, mid)) {
            ans = mid;
            high = mid - 1; // try smaller time
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Minimum time required: %d\n", minTime(arr, n, k));

    return 0;
}
