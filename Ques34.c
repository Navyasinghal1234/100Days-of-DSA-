#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}
int pop() {
    struct Node* temp;
    int value;

    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    temp = top;
    value = temp->data;
    top = top->next;
    free(temp);

    return value;
}
int main() {
    char exp[100];
    int i, a, b, result;
    printf("Enter postfix expression (without spaces): ");
    scanf("%s", exp);

    for (i = 0; exp[i] != '\0'; i++) {
        if (exp[i] >= '0' && exp[i] <= '9') {
            push(exp[i] - '0');
        }
        else {
            b = pop();
            a = pop();

            switch (exp[i]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            push(result);
        }
    }
    printf("Result = %d\n", pop());

    return 0;
}
