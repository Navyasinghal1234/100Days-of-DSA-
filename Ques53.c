//Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
};
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node* q[100];
    int front = 0, rear = 0;
    q[rear++] = root;
    int i = 1;
    while (i < n) {
        struct Node* curr = q[front++];
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            q[rear++] = curr->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            q[rear++] = curr->right;
        }
        i++;
    }
    return root;
}
void verticalOrder(struct Node* root) {
    if (!root) return;
    struct Node* q[100];
    int hd[100];  // horizontal distance
    int front = 0, rear = 0;
    int map[200][100], count[200] = {0};
    int min = 100, max = 100;
    q[rear] = root;
    hd[rear++] = 100;
    while (front < rear) {
        struct Node* curr = q[front];
        int h = hd[front++];
        map[h][count[h]++] = curr->data;
        if (h < min) min = h;
        if (h > max) max = h;

        if (curr->left) {
            q[rear] = curr->left;
            hd[rear++] = h - 1;
        }
        if (curr->right) {
            q[rear] = curr->right;
            hd[rear++] = h + 1;
        }
    }
    for (int i = min; i <= max; i++) {
        for (int j = 0; j < count[i]; j++)
            printf("%d ", map[i][j]);
        printf("\n");
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    struct Node* root = buildTree(arr, n);
    verticalOrder(root);
    return 0;
}
