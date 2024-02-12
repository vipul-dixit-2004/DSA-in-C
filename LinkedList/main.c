#include <stdio.h>
#include <stdlib.h>
// Creating Node
struct Node
{
    int value;
    struct Node *next;
};
// Function to print Node
void print(struct Node *n)
{
    do
    {
        printf("%d -> ", n->value);
    } while (n->next != NULL && (n = n->next));

    printf("null\n");
}
// Function to Insert Data to last;

void push(struct Node *n, int data)
{
    // Creating Node for element
    struct Node *element = NULL;
    element = (struct Node *)malloc(sizeof(struct Node));
    element->value = data;
    while (n->next != NULL)
    {
        n = n->next;
    }
    n->next = element;
    element->next = NULL;
}
void findMiddle(struct Node *head)
{
    struct Node *fast = head;
    struct Node *slow = head;
    int counter = 0;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        counter++;
    }
    printf("Middle Element is %d at %d", slow->value, counter);
}
int main()
{
    // initializing pointers
    struct Node *head;

    head = (struct Node *)malloc(sizeof(struct Node));
    // providing values
    head->value = 10;
    head->next = NULL;

    // PRINTING LINKED LIST
    print(head);
    push(head, 20);
    push(head, 30);
    push(head, 40);
    push(head, 50);
    push(head, 60);
    push(head, 70);
    print(head);
    findMiddle(head);

    return 0;
}