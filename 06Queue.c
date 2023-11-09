#include <stdio.h>
#define MAX 5
typedef struct
{
    int array[MAX];
    int front, rear;
} Queue;
void initialize(Queue *q)
{
    q->front = q->rear = -1;
}
void enqueue(Queue *q, int x)
{
    if (q->rear == -1)
        q->front = q->rear = 0;
    else
        q->rear++;
    if (q->rear == MAX)
    {
        printf("Queue is full....cannot add\n");
        q->rear--;
    }
    else
        q->array[q->rear] = x;
}
int dequeue(Queue *q)
{
    int x = -1;
    if (q->front == -1)
        printf("Queue is empty\n");
    else
    {
        x = q->array[q->front];
        q->front++;
        if (q->front > q->rear)
            q->front = q->rear = -1;
    }
    return x;
}
int empty(Queue q)
{
    if (q.rear == -1)
        return 1;
    else
        return 0;
}
int full(Queue q)
{
    if (q.rear == MAX - 1)
        return 1;
    return 0;
}
void display(Queue q)
{
    int i = q.front;

    if (q.front == -1)
        printf("Queue is empty\n");
    else
    {
        printf("Queue contains:\n");
        for (; i <= q.rear; i++)
        {
            printf("%d\n", q.array[i]);
        }
    }
}
int size(Queue q)
{
    if (!empty(q))
        return q.rear - q.front + 1;
    return -1;
}
int main()
{
    int choice, x;
    Queue q;
    initialize(&q);
    do
    {
        printf("\n1.Enqueue an element\n2.Dequeue an element\n3.Display\n4.Check if queue is empty\n5.Check if queue is full\n6.Get the size of the queue\n7.Exit\n\nEnter your choice:");

        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            printf("Enter element to enqueue:");
            scanf("%d", &x);
            enqueue(&q, x);
            break;
        case 2:
            x = dequeue(&q);
            if (x != -1)
                printf("Element deleted from queue is %d\n", x);
            break;
        case 3:
            display(q);
            break;
        case 4:
            if (empty(q))
                printf("Queue is empty\n");
            else
                printf("Queue is not empty\n");
            break;
        case 5:
            if (full(q))
                printf("Queue is full\n");
            else
                printf("Queue is not full\n");
            break;
        case 6:
            printf("Size of queue is %d\n", size(q));
            break;

        case 7:
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 7);
}
