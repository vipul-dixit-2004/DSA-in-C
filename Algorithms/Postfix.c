#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct llstack
{
    char value;
    struct llstack *next;
} node;

node *top;

node *createNode()
{
    return (node *)malloc(sizeof(node));
}

void push(char value)
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
char peak()
{
    if (top == NULL)
    {
        return '~';
    }

    return top->value;
}
char pop()
{
    if (top != NULL)
    {
        char item = top->value;
        top = top->next;
        return item;
    }
    printf("\n The stack is underflow....\n");
    return '~';
}
int empty()
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

int pref(char opr)
{
    if (opr == '*' || opr == '/')
        return 2;
    if (opr == '+' || opr == '-')
        return 1;
    else
        return -1;
}

char *infixToPostfix(char *s)
{
    int size = strlen(s);
    char *post = (char *)malloc(size);
    int j = 0, i = 0;
    for (i = 0; i < size; i++)
    {
        char curr = s[i];
        if (curr >= 65 && curr <= 90)
        {
            post[j++] = s[i];
        }
        else if (curr == '(')
        {
            push(curr);
        }
        else if (curr == ')')
        {
            while (!empty() && peak() != '(')
            {
                post[j++] = pop();
            }
            pop();
        }
        else
        {
            while (pref(curr) <= pref(peak()))
            {
                post[j++] = pop();
            }
            push(curr);
        }
    }
    while (!empty())
    {
        post[j++] = pop();
    }
    post[j] = '\0';
    return post;
}

int main()
{
    char *infix = "((A+B)-C*(D/E))+F";
    printf("%s", infixToPostfix(infix));
}