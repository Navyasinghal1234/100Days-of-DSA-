// Given meeting intervals, find minimum number of rooms required. Sort by start time and use min-heap on end times.
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
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] <= heap[index]) break;
        swap(&heap[parent], &heap[index]);
        index = parent;
    }
}

void heapifyDown(int heap[], int size, int index) {
    while (1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == index) break;

        swap(&heap[index], &heap[smallest]);
        index = smallest;
    }
}
void push(int heap[], int *size, int value) {
    heap[*size] = value;
    (*size)++;
    heapifyUp(heap, *size - 1);
}
void pop(int heap[], int *size) {
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
}
int top(int heap[]) {
    return heap[0];
}
int minMeetingRooms(Interval intervals[], int n) {
    if (n == 0) return 0;
    qsort(intervals, n, sizeof(Interval), compare);

    int heap[1000];  
    int heapSize = 0;
    push(heap, &heapSize, intervals[0].end);

    for (int i = 1; i < n; i++) {
        if (intervals[i].start >= top(heap)) {
            pop(heap, &heapSize);
        }
        push(heap, &heapSize, intervals[i].end);
    }

    return heapSize;
}
int main() {
    Interval intervals[] = {
        {0, 30},
        {5, 10},
        {15, 20}
    };
    int n = sizeof(intervals) / sizeof(intervals[0]);
    int result = minMeetingRooms(intervals, n);
    printf("Minimum meeting rooms required: %d\n", result);

    return 0;
}
