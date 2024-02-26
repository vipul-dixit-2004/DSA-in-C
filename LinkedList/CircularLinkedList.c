#include <stdio.h>
#include <stdlib.h>

typedef struct CircularLinkedList
{
    int val;
    struct CircularLinkedList *next;
} node;

node *tail;

node *createNode()
{
    return (node *)malloc(sizeof(node));
}

void append(int val)
{
    node *p = createNode();
    p->val = val;
    p->next = NULL;
    if (tail == NULL)
    {
        // setting node
        tail = p;
        p->next = p;
        return;
    }
    p->next = tail->next;
    tail->next = p;
    tail = p;
}

void addAfter(int val, int pos)
{
    if (tail == NULL)
    {
        return;
    }
    node *p = createNode();
    p->val = val;
    p->next = NULL;
    node *temp = tail->next;
    int i = 1;
    do
    {
        if (i < pos)
        {
            i++;
            temp = temp->next;
            continue;
        }
        p->next = temp->next;
        temp->next = p;
        break;
    } while (temp != tail->next);
}
void display()
{
    if (tail == NULL)
        return;
    int value = tail->val;
    node *temp = tail->next;
    while (temp != tail)
    {
        printf("%d->", temp->val);
        temp = temp->next;
    }
    printf("%d\n", temp->val);
}

void deleteNode(int pos)
{
    node *temp = tail->next;
    if (pos == 1)
        tail->next = temp->next;
    int i = 1;
    do
    {
        if (i < pos - 1)
        {
            i++;
            temp = temp->next;
            continue;
        }
        temp->next = temp->next->next;
        break;
    } while (temp != tail->next);
}

void deleteElement(int val)
{
    node *temp = tail->next;
    int i = 1;
    do
    {
        temp = temp->next;
    } while (temp->next->val != val && temp != tail->next);
    if (temp->next = tail)
    {
        tail = temp;
    }

    temp->next = temp->next->next;
}
void addAtBegin(int val)
{
    if (tail == NULL)
    {
        append(val);
        return;
    }
    node *newNode = createNode();
    newNode->val = val;
    newNode->next = tail->next;
    tail->next = newNode;
}

int menu()
{
    int ch;
    printf("\n-----------------------------\n1.Append\n2.Add at beginning\n3.AddAfter\n4.DeleteNode\n5.DeleteElement\n6.Display LinkedList\n7.Exit\n");
    printf("Enter your Choice: ");
    scanf("%d", &ch);
    return ch;
}

void main()
{
    while (1)
    {
        int value, pos;
        int ch = menu();
        switch (ch)
        {

        case 1:
            printf("Enter Node value to append: ");
            scanf("%d", &value);
            append(value);
            break;
        case 2:
            printf("Enter Node value to add at beginning: ");
            scanf("%d", &value);
            addAtBegin(value);
            break;
        case 3:
            printf("Enter Node location to append after (value position): ");
            scanf("%d %d", &pos, &value);
            addAfter(pos, value);
            break;
        case 4:
            printf("Enter the Position you want to delete: \n");
            scanf("%d", &pos);
            deleteNode(pos);
            break;
        case 5:
            printf("Enter the value you want to delete: \n");
            scanf("%d", &value);
            deleteElement(value);
            break;
        case 6:
            printf("\n-----------------------------\n");
            display();
            break;
        case 7:
            return;
        }
        getchar();
    }
}