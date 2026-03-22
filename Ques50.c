#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}
struct Node* searchBST(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return searchBST(root->left, key);
    }
    return searchBST(root->right, key);
}
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int main() {
    struct Node* root = NULL;
    int n, value, key;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Enter value to search: ");
    scanf("%d", &key);

    struct Node* result = searchBST(root, key);

    if (result != NULL) {
        printf("Value %d found in BST.\n", key);
    } else {
        printf("Value %d not found in BST.\n", key);
    }
    return 0;
}
