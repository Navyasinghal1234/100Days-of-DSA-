// Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.
#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;
    struct TreeNode* root = createNode(arr[0]);
    struct TreeNode* queue[n];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;
    while (i < n) {
        struct TreeNode* current = queue[front++];
        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }
    return root;
}
struct TreeNode* findLCA(struct TreeNode* root, int p, int q) {
    if (root == NULL)
        return NULL;
    if (root->val == p || root->val == q)
        return root;
    struct TreeNode* left = findLCA(root->left, p, q);
    struct TreeNode* right = findLCA(root->right, p, q);
    if (left != NULL && right != NULL)
        return root;
    return (left != NULL) ? left : right;
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int p, q;
    scanf("%d %d", &p, &q);
    struct TreeNode* root = buildTree(arr, n);
    struct TreeNode* lca = findLCA(root, p, q);
    if (lca != NULL)
        printf("%d\n", lca->val);
    return 0;
}
