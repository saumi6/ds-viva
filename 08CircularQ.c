#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
typedef struct
{
    int a[SIZE]; // Queue of integers
    int front, rear;
} CQueue;
void cenqueue(CQueue *p, int x) // insert element in queue at rear end
{
    if ((p->rear + 1) % SIZE == p->front) // if queue is full
    {
        printf("Queue Full\n"); // report Queue full message
    }
    else
    {
        p->rear = (p->rear + 1) % SIZE; // increment rear
        p->a[p->rear] = x;              // put the element at rear index
        if (p->front == -1)             // if first elment inserted in queue
            p->front = 0;
    }
}
int cdequeue(CQueue *p)
{
    int x;
    if (p->front == -1) // if queue empty
    {
        printf("Queue Empty\n"); // report Queue empty message
        return -1;               // return something which we are not going to store in queue
    }
    else
    {
        x = p->a[p->front];          // take element at front index and store it in local variable
        if (p->front == p->rear)     // last element deleted from queue
            p->front = p->rear = -1; // go back to inƟal posƟon
        else
            p->front = (p->front + 1) % SIZE; // increment front
        return x;                             // return element
    }
}
int isEmpty(CQueue q)
{
    if (q.front == -1) // iniƟal queue
        return 1;
    else
        return 0;
}
void display(CQueue q)
{
    int i;
    if (!isEmpty(q)) // equivalent to check isEmpty(q) == 0
    {
        for (i = q.front; i != q.rear; i = (i + 1) % SIZE)

        {
            printf("%d\n", q.a[i]);
        }
        printf("%d\n", q.a[i]);
    }
}

int isFull(CQueue q)
{
    if (q.front = (q.rear + 1) % SIZE)
        return 1;
    else
        return 0;
}
int main()
{
    CQueue q1;
    int x, choice;
    char ch;

    q1.front = q1.rear = -1;
    do
    {
        printf("1.Enqueue 2.Dequeue 3.Display 4.Exit\nEnter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to be inserted :\n");
            scanf("%d", &x);
            cenqueue(&q1, x);
            break;
        case 2:
            x = cdequeue(&q1);
            printf("The removed element is %d\n", x);
            break;
        case 3:
            printf("Queue Contents\n");
            display(q1);
            break;
        case 4: 
            break;
        default: printf("Invalid input");
        }
    } while (choice!=4);
    return 0;
}