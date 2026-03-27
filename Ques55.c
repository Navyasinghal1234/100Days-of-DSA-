//Print the nodes visible when the binary tree is viewed from the right side.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* queue[1000];
int front = -1, rear = -1;

void enqueue(struct Node* node) {
    if (front == -1) front = 0;
    queue[++rear] = node;
}
struct Node* dequeue() {
    struct Node* temp = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;
    return temp;
}
int isEmpty() {
    return front == -1;
}
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = createNode(arr[0]);
    enqueue(root);
    int i = 1;
    while (i < n) {
        struct Node* curr = dequeue();
        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(curr->left);
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }
    return root;
}
void rightView(struct Node* root) {
    if (root == NULL) return;

    enqueue(root);
    while (!isEmpty()) {
        int size = rear - front + 1;
        for (int i = 0; i < size; i++) {
            struct Node* temp = dequeue();
            if (i == size - 1) {
                printf("%d ", temp->data);
            }
            if (temp->left) enqueue(temp->left);
            if (temp->right) enqueue(temp->right);
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct Node* root = buildTree(arr, n);
    rightView(root);
    return 0;
}
