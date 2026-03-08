#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;
void enqueue(int value)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = value;

    if (front == NULL)
    {
        front = rear = newnode;
        rear->next = front;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
}
void dequeue()
{
    if (front == NULL)
        return;
    front = front->next;
    rear = rear->next;
}
void display()
{
    if (front == NULL)
        return;
    Node *temp = front;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
}
int main()
{
    int n, m, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
        dequeue();
    display();
    return 0;
}
