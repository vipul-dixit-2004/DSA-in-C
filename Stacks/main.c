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
        return;
    }
    stack->arr[++stack->top] = item;
}
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        return -1;
    }
    return stack->arr[stack->top--];
}
int main()
{
    unsigned int size = 3;
    printf("%d\n", sizeof(struct Stack));
    struct Stack *stack = create(size);
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);
    push(stack, 60);
    int top = pop(stack);
    printf("%d", top);
    return 0;
}