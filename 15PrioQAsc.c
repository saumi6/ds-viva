#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    int priority;
    struct node *next;
} Node;
typedef struct
{
    Node *front;
} prioq;
void enqueue(prioq *pq, int ele, int prio)
{
    Node *p;
    p = (Node *)malloc(sizeof(Node));
    p->data = ele;
    p->priority = prio;
    p->next=NULL;
    if (pq->front == NULL)
    {
        pq->front = p;
        return;
    }
    Node *prev = NULL;
    Node *trav = pq->front;
    while (trav != NULL)
    {
        if (p->priority < trav->priority)
        {
            if (trav == pq->front)
            {
                p->next = pq->front;
                pq->front = p;
                return;
            }
            prev->next = p;
            p->next = trav;
            return;
        }
        prev = trav;
        trav = trav->next;
    }
    if (trav == NULL)
    {
        prev->next = p;
        p->next = NULL;
    }
}
int dequeue(prioq *pq)
{
    if (pq->front == NULL)

    {
        printf("Queue is empty.");
        return -1;
    }
    Node *temp = pq->front;
    int x = temp->data;
    pq->front = temp->next;
    free(temp);
    return x;
}
void display(prioq* pq)
{
    if (pq->front == NULL)
    {
        printf("Queue is empty.");
        return;
    }
    Node *trav = pq->front;
    printf("The queue contains:\n");
    while (trav != NULL)
    {
        printf("Element:%d\tPriority:%d\n", trav->data, trav->priority);
        trav = trav->next;
    }
}
int main()
{
    prioq pq;
    int x, p, choice;
    pq.front = NULL;
    do
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &x);
            printf("Enter the priority: ");
            scanf("%d", &p);
            enqueue(&pq, x, p);
            break;
        case 2:
            x = dequeue(&pq);
            printf("Value dequeued is: %d\n", x);
            break;
        case 3:
            display(&pq);
            break;
        case 4:
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 4);
}