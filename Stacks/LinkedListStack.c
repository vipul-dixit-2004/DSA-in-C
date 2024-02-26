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
int peak()
{
    if (top == NULL)
    {
        return -1;
    }

    return top->value;
}
int menu()
{
    printf("\n1.) Push\n2.) Pop\n3.) Peak\n4.) Display\n5.) Exit\n Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    return choice;
}

int pop()
{
    if (top != NULL)
    {
        int item = top->value;
        top = top->next;
        return item;
    }
    printf("\n The stack is underflow....\n");
    return -1;
}
void display()
{
    node *temp;
    temp = top;
    while (temp != NULL)
    {
        printf("%d\n-----\n", temp->value);
        temp = temp->next;
    }
}
void main()
{
    int bool;
    int value;
    while (1)
    {
        int ch = menu();
        switch (ch)
        {

        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            bool = pop();
            if (bool == -1)
            {
                printf("The stack is underflow....");
                break;
            }
            printf("The Value at top is: %d", bool);
            break;
        case 3:
            bool = peak();
            if (bool == -1)
            {
                printf("The Stack is empty");
                break;
            }
            printf("The Elemednt at thd top is: %d", bool);
            break;
        case 4:
            display();
            break;
        case 5:
            return;
        default:
            printf("\n______________________________________________\n");
        }
        getchar();
    }
}
