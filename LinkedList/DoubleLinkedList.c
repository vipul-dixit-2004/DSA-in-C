/*
 created By Vipul Dixit
 github link:
 https://github.com/vipul-dixit-2004/DSA-in-C/blob/main/LinkedList/DoubleLinkedList.c
*/

#include <stdio.h>
#include <stdlib.h>
void append(int value);
struct DoubleLinkedList
{
    int value;
    struct DoubleLinkedList *prev;
    struct DoubleLinkedList *next;
};
typedef struct DoubleLinkedList node;
node *head;
node *tail;
// to create newnode
node *createNode()
{
    return (node *)malloc(sizeof(node));
}
// will append data at end of list
void append(int value)
{
    node *newNode = createNode();
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        newNode->value = value;
        newNode->prev = NULL;
        newNode->next = NULL;
    }
    else
    {
        node *temp = tail;
        temp->next = newNode;
        newNode->value = value;
        newNode->prev = temp;
        newNode->next = NULL;
        tail = newNode;
    }
    return;
}
// menu
void createList()
{
    if (head == NULL)
    {
        int data;
        printf("Enter Value for node: ");
        scanf("%d", &data);
        append(data);
        return;
    }
    printf("List Already Exist!! ");
}
int menu()
{
    int ch;
    printf("\n-----------------------------\n1.CreateList(Works only in turboC because getchar)\n2.Append\n3.Add at beginning\n4.AddAfter\n5.DeleteNode\n6.DeleteElement\n7.Display LinkedList\n8.Display list from back\n9.Exit\n");
    printf("Enter your Choice: ");
    scanf("%d", &ch);
    return ch;
}

// insert Element at beginning of the list
void addhead(int value)
{
    node *newNode = createNode();
    newNode->next = head;
    head->prev = newNode;
    head = newNode;

    newNode->prev = NULL;
    newNode->value = value;
    return;
}
// insert element at any position
void insertAfter(int pos, int value)
{
    node *temp = head;
    for (int i = 1; i < pos && temp->next != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Enter Position exceeds the length of list!!!");
        return;
    }
    node *newNode = createNode();
    newNode->value = value;
    newNode->next = temp->next;
    newNode->prev = temp;
    (temp->next)->prev = newNode;
    temp->next = newNode;
}
void insertHead(int value)
{
    node *newNode = createNode();
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = head;
    head = newNode;
}
// delete node
void deleteNode(int pos)
{
    if (pos == 1)
    {
        head->next->prev = NULL;
        head = head->next;
        return;
    }
    node *temp = head;
    // node *newNode = createNode();
    for (int i = 1; i < pos && temp != NULL; i++)
    {
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}
// delete Node by value
void deleteElement(int value)
{
    node *temp = head;
    while (temp->value != value)
    {
        if (temp->next == NULL)
        {
            printf("No such element in the list");
            return;
        }
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

// to print all the elements of LinkedList;
void display()
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
    return;
}
void displayFromBack()
{
    node *temp = tail;
    printf("NULL");
    while (temp != NULL)
    {
        printf("<- %d ", temp->value);
        temp = temp->prev;
    }
    return;
}
int main()
{
    int value, pos;
    while (1)
    {
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
            insertHead(value);
            break;
        case 4:
            printf("Enter Node location to append after (position value): ");
            scanf("%d %d", &pos, &value);
            insertAfter(pos, value);
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
            printf("\n-----------------------------\n\n");
            display();
            break;
        case 8:
            printf("\n-----------------------------\n\n");
            displayFromBack();
            break;
        case 9:
            return 0;
        }
        getchar();
    }
}