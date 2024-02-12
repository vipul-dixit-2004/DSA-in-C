/* created By Vipul Dixit
 github link:
 https://github.com/vipul-dixit-2004/DSA-in-C/blob/main/LinkedList/LinkedList.c
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int value;
    struct Node *next;
} node;

struct Node *start;

struct Node *createNode()
{
    return (struct Node *)malloc(sizeof(struct Node));
}
int menu()
{
    int ch;
    printf("\n-----------------------------\n1.CreateList(Works only in turboC because getchar)\n2.Append\n3.Add at beginning\n4.AddAfter\n5.DeleteNode\n6.DeleteElement\n7.Display LinkedList\n8.Exit\n");
    printf("Enter your Choice: ");
    scanf("%d", &ch);
    return ch;
}
void append(int value)
{
    struct Node *temp = start;
    struct Node *p = createNode();
    p->next = NULL;
    p->value = value;
    if (start != NULL)
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
    }
    else
    {
        start = p;
    }
}
void createList()
{
    if (start == NULL)
    {
        char ch;
        while (1)
        {
            printf("Insert node to Linked List: y for Yes or n for No:\n");
            scanf("%c", &ch);
            getchar();
            if (ch != 'y')
                return;
            int value;
            printf("Enter value for Node: \n");
            scanf("%d", &value);
            getchar();
            append(value);
        }
    }

    return;
}
void addAfter(int pos, int value)
{
    if (start == NULL)
    {
        append(value);
        return;
    }
    node *temp = start;
    node *newNode = createNode();
    newNode->value = value;
    for (int i = 1; i < pos && temp->next != NULL; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void insertAtBegin(int value)
{
    if (start == NULL)
    {
        append(value);
        return;
    }
    node *newNode = createNode();
    newNode->value = value;
    newNode->next = start;
    start = newNode;
}
void deleteNode(int pos)
{
    node *temp = start;
    if (pos == 1)
    {
        start = temp->next;
        return;
    }
    int i = 1;
    while ((i < pos - 1) && temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    temp->next = temp->next->next;
}
void deleteElement(int value)
{
    node *temp = start;
    while ((temp->next)->value != value)
    {
        if (temp->next == NULL)
            printf("No such element in the list");
        temp = temp->next;
    }
    temp->next = temp->next->next;
}
void print()
{
    struct Node *temp = start;
    while (temp != NULL)
    {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    while (1)
    {
        int value, pos;
        int ch = menu();
        switch (ch)
        {
        case 1:
            createList();
            break;

        case 2:
            printf("Enter Node value to append: ");
            scanf("%d", &value);
            append(value);
            break;
        case 3:
            printf("Enter Node value to add at beginning: ");
            scanf("%d", &value);
            insertAtBegin(value);
            break;
        case 4:
            printf("Enter Node location to append after (position value): ");
            scanf("%d %d", &pos, &value);
            addAfter(pos, value);
            break;
        case 5:
            printf("Enter the Position you want to delete: \n");
            scanf("%d", &pos);
            deleteNode(pos);
            break;
        case 6:
            printf("Enter the value you want to delete: \n");
            scanf("%d", &value);
            deleteElement(value);
            break;
        case 7:
            printf("\n-----------------------------\n");
            print();
            break;
        case 8:
            return 0;
        }
        getchar();
    }

    return 0;
}