//Find the height (maximum depth) of a given binary tree.

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
};
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
struct Node* queue[1000];
int front = 0, rear = 0;
void enqueue(struct Node* node) {
    queue[rear++] = node;
}
struct Node* dequeue() {
    return queue[front++];
}
struct Node* buildTree(int arr[], int n) {
    if (arr[0] == -1) return NULL;
    struct Node* root = createNode(arr[0]);
    enqueue(root);
    int i = 1;
    while (i < n) {
        struct Node* curr = dequeue();
        if (arr[i] != -1) {
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
int getHeight(struct Node* root) {
    if (root == NULL) return 0;
    int l = getHeight(root->left);
    int r = getHeight(root->right);
    return (l > r ? l : r) + 1;
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    struct Node* root = buildTree(arr, n);
    printf("%d", getHeight(root));
    return 0;
}
