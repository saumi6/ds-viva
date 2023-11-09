#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int n;
    struct node *next;
} Node;
typedef struct
{
    Node *front, *rear;
} Queue;
void enqueue(int x, Queue *q)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->n = x;
    ptr->next = NULL;
    if (q->rear == NULL)
        q->front = q->rear = ptr;
    else
    {
        q->rear->next = ptr;
        q->rear = ptr;
    }
}
int dequeue(Queue *q)
{
    int data = -1;
    Node *ptr = q->front;
    if (q->front == NULL)
    {
        printf("Queue is empty\n");
        return data;
    }
    data = q->front->n;
    if (q->front == q->rear)
        q->front = q->rear = NULL;
    else
        q->front = q->front->next;
    free(ptr);
    return data;
}
void display(Queue q)
{
    Node *ptr = q.front;
    printf("Queue contains:\n");
    while (ptr != NULL)
    {
        printf("%d\n", ptr->n);
        ptr = ptr->next;
    }
}
void main()
{

    Queue q;
    q.front = NULL;
    q.rear = NULL;
    int choice, data;
    do
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice:");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data:");
            scanf("%d", &data);
            enqueue(data, &q);
            break;
        case 2:
            data = dequeue(&q);
            if (data != -1)
                printf("%d dequeued\n", data);
            break;
        case 3:
            display(q);
            break;
        case 4:
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 4);
}