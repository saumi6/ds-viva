#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int n;
    struct node *next;
} Node;
typedef struct
{
    Node *ToS;
} Stack;
void push(int x, Stack *s)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->n = x;
    ptr->next = s->ToS;
    s->ToS = ptr;
}
int pop(Stack *s)
{
    int data = -1;
    Node *ptr = s->ToS;
    if (s->ToS == NULL)
    {
        printf("Stack Underflow\n");
        return data;
    }
    data = s->ToS->n;
    s->ToS = s->ToS->next;
    free(ptr);
    return data;
}
int peek(Stack s)
{
    int data = -1;
    if (s.ToS == NULL)
    {
        printf("Stack is empty\n");
        return data;
    }
    data = s.ToS->n;
    return data;
}
void display(Stack s)
{
    Node *ptr = s.ToS;
    printf("Stack contains:\n");
    while (ptr != NULL)
    {
        printf("%d\n", ptr->n);
        ptr = ptr->next;
    }
}
int main()
{
    Stack s1;
    s1.ToS = NULL;
    int choice, data;
    do
    {
printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\nEnter your choice:");

scanf("%d",&choice);
switch(choice)
{
        case 1:
            printf("Enter the data:");
            scanf("%d", &data);

            push(data, &s1);
            break;
        case 2:
            data = pop(&s1);
            if (data != -1)
                printf("%d popped\n", data);
            break;
        case 3:
            data = peek(s1);
            if (data != -1)
                printf("Top of stack contains:%d\n", data);
            break;
        case 4:
            display(s1);
            break;
        case 5:
            break;
        default:
            printf("Invalid choice\n");
}
    } while (choice != 5);
}