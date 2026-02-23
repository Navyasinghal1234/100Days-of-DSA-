//Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
Node* insert(Node* head, int data) {
    Node* temp = newNode(data);

    if (head == NULL)
        return temp;

    Node* p = head;
    while (p->next != NULL)
        p = p->next;

    p->next = temp;
    return head;
}
Node* merge(Node* a, Node* b) {
    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;

    while (a != NULL && b != NULL) {
        if (a->data <= b->data) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }

    if (a != NULL)
        tail->next = a;
    else
        tail->next = b;

    return dummy.next;
}
void print(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m, x;
    Node *list1 = NULL, *list2 = NULL;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        list1 = insert(list1, x);
    }

    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &x);
        list2 = insert(list2, x);
    }

    Node* result = merge(list1, list2);
    print(result);

    return 0;
}
