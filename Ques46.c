//Level Order Traversal. Implement the solution for this problem.

#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left, *right;
};
struct node* newNode(int value) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}
struct node* queue[100];
int front = -1, rear = -1;
void enqueue(struct node* temp) {
    if (rear == 99) {
        printf("Queue full\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = temp;
}
struct node* dequeue() {
    if (front == -1) return NULL;

    struct node* temp = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;

    return temp;
}
void levelOrder(struct node* root) {
    if (root == NULL) return;
    enqueue(root);
    while (front != -1) {
        struct node* temp = dequeue();
        printf("%d ", temp->data);
        if (temp->left != NULL)
            enqueue(temp->left);
        if (temp->right != NULL)
            enqueue(temp->right);
    }
}
int main() {
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Level Order Traversal: ");
    levelOrder(root);

    return 0;
}
