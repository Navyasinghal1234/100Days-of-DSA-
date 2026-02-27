#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}
struct Node* getIntersectionNode(struct Node* head1, struct Node* head2) {
    
    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    while (ptr1 != ptr2) {
        
        if (ptr1 == NULL)
            ptr1 = head2;
        else
            ptr1 = ptr1->next;

        if (ptr2 == NULL)
            ptr2 = head1;
        else
            ptr2 = ptr2->next;
    }
    return ptr1;   
}
int main() {
  
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    int n, m, i, value;
    printf("Enter number of nodes in first list: ");
    scanf("%d", &n);

    printf("Enter elements of first list:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &value);
        append(&head1, value);
    }
    printf("Enter number of nodes in second list: ");
    scanf("%d", &m);

    printf("Enter elements of second list:\n");
    for(i = 0; i < m; i++) {
        scanf("%d", &value);
        append(&head2, value);
    }
    struct Node* temp1 = head1;
    for(i = 1; i < 3 && temp1 != NULL; i++)
        temp1 = temp1->next;

    if(temp1 != NULL) {
        struct Node* temp2 = head2;
        while(temp2->next != NULL)
            temp2 = temp2->next;
        temp2->next = temp1;   
    }
    struct Node* intersection = getIntersectionNode(head1, head2);

    if(intersection)
        printf("Intersection Point: %d\n", intersection->data);
    else
        printf("No Intersection\n");
    return 0;
}
