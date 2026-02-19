//Given an array of integers, find two elements whose sum is closest to zero.

#include <stdio.h>
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
 int min_sum = arr[0] + arr[1];
 int num1 = arr[0];
 int num2 = arr[1];
for(int i = 0; i < n - 1; i++) {
      
for(int j = i + 1; j < n; j++) {
  int sum = arr[i] + arr[j];

      
 int abs_sum = sum < 0 ? -sum : sum;
int abs_min = min_sum < 0 ? -min_sum : min_sum;
  if(abs_sum < abs_min) {
      min_sum = sum;
      num1 = arr[i];
       num2 = arr[j];
            }
        }
    }
    printf("Pair whose sum is closest to zero: %d %d\n", num1, num2);

    return 0;
}
