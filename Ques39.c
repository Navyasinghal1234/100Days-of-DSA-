#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int heap[MAX];
int size = 0;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
})
void heapifyUp(int index)
{
    int parent = (index - 1) / 2;
    while(index > 0 && heap[index] < heap[parent])
    {
        swap(&heap[index], &heap[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}
void insert(int x)
{
    if(size == MAX)
    {
        printf("Heap Overflow\n");
        return;
    }

    heap[size] = x;
    heapifyUp(size);
    size++;
}
void heapifyDown(int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < size && heap[left] < heap[smallest])
        smallest = left;

    if(right < size && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != index)
    {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(smallest);
    }
}
int peek()
{
    if(size == 0)
        return -1;

    return heap[0];
}
int extractMin()
{
    if(size == 0)
        return -1;
    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return root;
}
int main()
{
    int n;
    char operation[20];
    int value;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%s", operation);

        if(strcmp(operation, "insert") == 0)
        {
            scanf("%d", &value);
            insert(value);
        }
        else if(strcmp(operation, "peek") == 0)
        {
            printf("%d\n", peek());
        }
        else if(strcmp(operation, "extractMin") == 0)
        {
            printf("%d\n", extractMin());
        }
    }
    return 0;
}
