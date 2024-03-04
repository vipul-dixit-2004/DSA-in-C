#include <stdlib.h>
#include <stdio.h>
// Stack
struct Stack
{
    int top;
    int size;
    int *arr;
};
// creating Stack
struct Stack *create(int size)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->size = size;
    stack->arr = (int *)malloc(stack->size * sizeof(int));
    return stack;
}
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}
int isFull(struct Stack *stack)
{
    return stack->top == ((stack->size) - 1);
}
void push(struct Stack *stack, int item)
{
    if (isFull(stack))
    {
        printf("The stack is full overflow\n");
        return;
    }
    stack->arr[++stack->top] = item;
}
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("The stack is empty underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

int peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("The stack is empty underflow\n");
        return -1;
    }
    return stack->arr[stack->top];
}
int menu()
{
    printf("1.)Push\n2.)Pop\n3.)Peek\n");
    printf("--------------------------------\n");
    int choice;
    printf("what would you like to perform: ");
    scanf("%d", &choice);
    return choice;
}
int main()
{
    unsigned int size;
    int val;
    int popValue;
    int choice;
    printf("Enter size of Stack: ");
    scanf("%d", &size);
    struct Stack *stack = create(size);
    while (1)
    {
        choice = menu();
        switch (choice)
        {
        case 1:
            printf("Enter Value: ");
            scanf("%d", &val);
            push(stack, val);
            break;
        case 2:
            popValue = pop(stack);
            if (popValue != -1)
            {
                printf("The Poped Value is: %d\n", popValue);
            }
            break;
        case 3:
            popValue = peek(stack);
            if (popValue != -1)
            {
                printf("The Top Value is: %d\n", popValue);
            }
            break;
        }
        getchar();
        printf("-----------------------------------------\n");
    }
}
