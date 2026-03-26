//Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.
#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int data;
    struct TreeNode *left, *right;
};
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Queue {
    struct TreeNode* arr[1000];
    int front, rear;
};
void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}
int isEmpty(struct Queue* q) {
    return q->front == -1;
}
void enqueue(struct Queue* q, struct TreeNode* node) {
    if (q->rear == 999) return;
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = node;
}
struct TreeNode* dequeue(struct Queue* q) {
    if (isEmpty(q)) return NULL;
    struct TreeNode* temp = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return temp;
}
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct TreeNode* root = createNode(arr[0]);
    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);
    int i = 1;
    while (i < n) {
        struct TreeNode* current = dequeue(&q);
        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            enqueue(&q, current->left);
        }
        i++;
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            enqueue(&q, current->right);
        }
        i++;
    }
    return root;
}
void zigzagTraversal(struct TreeNode* root) {
    if (!root) return;
    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);
    int leftToRight = 1;
    while (!isEmpty(&q)) {
        int size = q.rear - q.front + 1;
        int level[1000];
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = dequeue(&q);
            int index = leftToRight ? i : (size - 1 - i);
            level[index] = node->data;

            if (node->left) enqueue(&q, node->left);
            if (node->right) enqueue(&q, node->right);
        }
        for (int i = 0; i < size; i++) {
            printf("%d ", level[i]);
        }
        leftToRight = !leftToRight; // toggle direction
    }
}
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct TreeNode* root = buildTree(arr, n);
    zigzagTraversal(root);
    return 0;
}
