//Given intervals, merge all overlapping ones. Sort first, then compare with previous.
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int start;
    int end;
} Interval;
int compare(const void *a, const void *b) {
    Interval *i1 = (Interval *)a;
    Interval *i2 = (Interval *)b;
    return i1->start - i2->start;
}

Interval* mergeIntervals(Interval arr[], int n, int *returnSize) {
    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }
    qsort(arr, n, sizeof(Interval), compare);
    Interval *result = (Interval *)malloc(n * sizeof(Interval));

    int index = 0;
    result[0] = arr[0];
    for (int i = 1; i < n; i++) {

        if (arr[i].start <= result[index].end) {
            if (arr[i].end > result[index].end)
                result[index].end = arr[i].end;
        }
        else {
            index++;
            result[index] = arr[i];
        }
    }

    *returnSize = index + 1;
    return result;
}
int main() {
    Interval arr[] = {{1,3}, {2,6}, {8,10}, {15,18}};
    int n = sizeof(arr) / sizeof(arr[0]);

    int mergedSize;
    Interval *merged = mergeIntervals(arr, n, &mergedSize);

    printf("Merged Intervals:\n");
    for (int i = 0; i < mergedSize; i++) {
        printf("[%d, %d] ", merged[i].start, merged[i].end);
    }

    free(merged);
    return 0;
}
