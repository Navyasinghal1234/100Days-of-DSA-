//Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to delete first occurrence of key
struct Node* deleteFirstOccurrence(struct Node* head, int key) {
    struct Node *temp = head, *prev = NULL;
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return head;
    }
    prev->next = temp->next;
    free(temp);

    return head;
}
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main() {
    int n, value, key;
    struct Node *head = NULL, *temp = NULL, *last = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        temp = createNode(value);

        if (head == NULL) {
            head = temp;
            last = temp;
        } else {
            last->next = temp;
            last = temp;
        }
    }
    scanf("%d", &key);
    head = deleteFirstOccurrence(head, key);
    printList(head);
    return 0;
}
