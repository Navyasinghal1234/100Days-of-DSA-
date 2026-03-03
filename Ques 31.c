#include <stdio.h>
int stack[100];
int top = -1;
int main() {
    int n, choice, value;
    scanf("%d", &n);  
    for(int i = 0; i < n; i++) {
        scanf("%d", &choice);
        if(choice == 1) {
            scanf("%d", &value);
            top++;
            stack[top] = value;
        }
        else if(choice == 2) {
            if(top == -1) {
                printf("Stack Underflow\n");
            } else {
                printf("%d\n", stack[top]);
                top--;
            }
        }
        else if(choice == 3) {
            if(top == -1) {
                printf("Stack is Empty\n");
            } else {
                for(int j = top; j >= 0; j--) {
                    printf("%d ", stack[j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
