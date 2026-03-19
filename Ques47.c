//Height of Binary Tree. Implement the solution for this problem

#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
Node* createNode(int data) {
    if (data == -1)
        return NULL;

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    printf("Enter left child of %d (-1 for NULL): ", data);
    int leftData;
    scanf("%d", &leftData);
    newNode->left = createNode(leftData);

    printf("Enter right child of %d (-1 for NULL): ", data);
    int rightData;
    scanf("%d", &rightData);
    newNode->right = createNode(rightData);

    return newNode;
}
int height(Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}
int main() {
    int rootData;
    printf("Enter root value (-1 for NULL): ");
    scanf("%d", &rootData);
    Node* root = createNode(rootData);
    int h = height(root);
    printf("Height of Binary Tree = %d\n", h);

    return 0;
}
