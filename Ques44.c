#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void inorder(struct node* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(struct node* root) {
    if(root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node* root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
int main() {
    int n, i;
    scanf("%d", &n);

    int arr[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct node* nodes[n];

    for(i = 0; i < n; i++) {
        if(arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = newNode(arr[i]);
    }
    int j = 1;
    for(i = 0; i < n && j < n; i++) {
        if(nodes[i] != NULL) {
            nodes[i]->left = nodes[j++];
            if(j < n)
                nodes[i]->right = nodes[j++];
        }
    }
    struct node* root = nodes[0];
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");

    postorder(root);

    return 0;
}

