#include <stdio.h>
#include <stdlib.h>

typedef struct llstack
{
    int value;
    struct llstack *next;
} node;

node *top;

node *createNode()
{
    return (node *)malloc(sizeof(node));
}

void push(int value)
{
    node *newNode = createNode();
    newNode->value = value;
    if (top == NULL)
    {
        newNode->next = NULL;
        top = newNode;
        return;
    }
    newNode->next = top;
    top = newNode;
}
int pop()
{
    int item = top->value;
    top = top->next;
    return item;
}
void display()
{
    node *temp;
    temp = top;
    while (temp != NULL)
    {
        printf("%d-> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}
void main()
{
}
