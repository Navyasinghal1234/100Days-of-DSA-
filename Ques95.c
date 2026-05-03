//Given n real numbers in [0,1), sort using bucket sort algorithm. Distribute into buckets, sort each, concatenate.
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    float data;
    struct Node* next;
} Node;
void insertSorted(Node** head, float value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    Node* current = *head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}
void bucketSort(float arr[], int n) {
    Node* buckets[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];  
        insertSorted(&buckets[index], arr[i]);
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        Node* temp = buckets[i];
        while (temp != NULL) {
            arr[k++] = temp->data;
            temp = temp->next;
        }
    }
}
int main() {
    float arr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}
