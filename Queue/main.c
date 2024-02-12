#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int first;
    int last;
    int capacity;
    int *arr;
};
struct Queue *create(int capacity)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->first = -1;
    queue->last = -1;
    queue->capacity = capacity;
    queue->arr = (int *)malloc(queue->capacity * sizeof(int));
}

int isFull(struct Queue *queue)
{
    if (queue->last == queue->capacity - 1)
    {
        return 1;
    }
    return 0;
}
int isEmpty(struct Queue *queue)
{
    if (queue->first > queue->last || queue->first == -1)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct Queue *queue, int value)
{
    if (queue->first == -1)
    {
        queue->arr[++queue->first] = value;
        queue->last = queue->first;
        return;
    }
    if (!isFull(queue))
    {
        queue->arr[++queue->last] = value;
    }
    return;
}
int peekfirst(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        return -1;
    }
    return queue->arr[queue->first];
}
int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        return -1;
    }
    return queue->arr[queue->first++];
}
int size(struct Queue *queue)
{
    if (queue->first <= queue->last && queue->first != -1)
    {
        return queue->last - queue->first + 1;
    }
    else
    {
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    struct Queue *queue = create(100);
    // enqueue(queue, 10);
    // enqueue(queue, 20);
    // enqueue(queue, 30);
    // enqueue(queue, 40);
    // dequeue(queue);
    // dequeue(queue);
    // dequeue(queue);
    // dequeue(queue);
    printf("%d", size(queue));
    return 0;
}
