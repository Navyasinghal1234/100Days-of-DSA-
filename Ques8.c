// Given integers a and b, compute a^b using recursion without using pow() function.
#include <stdio.h>

int find(int a, int b) {
    if (b == 0)
        return 1;          // base case
    return a * find(a, b - 1);
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", find(a, b));
    return 0;
}
