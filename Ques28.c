//Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
int main() {
    int n, i;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    scanf("%d", &n);
    if(n <= 0) {
        return 0;
    }
    for(i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        }
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    temp->next = head;
    struct Node* current = head;

    do {
        printf("%d ", current->data);
        current = current->next;
    } while(current != head);

    return 0;
}
