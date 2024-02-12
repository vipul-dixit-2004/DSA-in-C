#include <stdio.h>
#include <stdlib.h>

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
// menu
int menu()
{
    int ch;
    printf("\n-----------------------------\n1.CreateList\n2.Append\n3.AddAfter\n4.DeleteNode\n5.DeleteElement\n6.Display LinkedList\n7.Exit\n");
    printf("Enter your Choice: ");
    scanf("%d", &ch);
    return ch;
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
        return;
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
    append(20);
    append(30);
    append(40);
    append(50);
    addhead(1000);
    append(60);
    display();
    deleteNode(1);
    display();
    // displayFromBack();
}