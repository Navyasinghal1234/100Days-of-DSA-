//Find the integer square root of a given non-negative integer using Binary Search. The integer square root of a number is defined as the greatest integer whose square is less than or equal to the given number.
#include <stdio.h>
int integerSquareRoot(int n)
{
    if (n == 0 || n == 1)
        return n;
    int low = 1, high = n, ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (mid == n / mid && mid * mid == n)
        {
            return mid; 
        }
        else if (mid <= n / mid)
        {
            ans = mid;    
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", integerSquareRoot(n));
    return 0;
}
