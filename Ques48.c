//Count Leaf Nodes. Implement the solution for this problem
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct Node* insertLevelOrder(int arr[], int n, int i) {
    if (i >= n)
        return NULL;
    struct Node* root = createNode(arr[i]);
    root->left = insertLevelOrder(arr, n, 2*i + 1);
    root->right = insertLevelOrder(arr, n, 2*i + 2);
    return root;
}
int countLeafNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct Node* root = insertLevelOrder(arr, n, 0);
    int leafCount = countLeafNodes(root);
    printf("Number of leaf nodes: %d\n", leafCount);
    return 0;
}
