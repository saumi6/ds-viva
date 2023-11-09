#include <stdio.h>
#define SIZE 5

typedef struct
{
    float a[100];
    int tos;
}Stack;

void push(Stack *p, float ele)
{
    if (p->tos==SIZE-1)
    {
        printf("Stack Overflow.\n");
        return;
    }
    p->tos++;
    p->a[p->tos]=ele;
}

float pop(Stack *p)
{
    if(p->tos==-1)
    {
        printf("Stack Underflow.\n");
        return -1.0;
    }
    return (p->a[p->tos--]);
}

void display(Stack s)
{
    for(int i=s.tos;i>=0;i--)
    {
        printf("%.1f\n",s.a[i]);
    }
}

int isEmpty (Stack s)
{
    return (s.tos==-1);
}

int isFull (Stack s)
{
    return (s.tos==SIZE-1);
}

float peek (Stack s)
{
    if (s.tos==-1)
    {
        printf("Stack empty.\n");
        return -1.0;
    }
    return s.a[s.tos];
}

int size (Stack s)
{
    return s.tos+1;
}

int main()
{   
    Stack S;
    int choice;
    float x;
    S.tos=-1;
    do
	{
		printf("\n1.Push\t\t2.Pop\t\t3.Display\t4.Peek\n5.Is it full?\t6.Is it empty?\t7.Size\t\t8.Exit\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
            printf("Enter the element to push: ");
			scanf("%f",&x);
			push(&S,x);
			break;
			case 2:
            x=pop(&S);
			if(x!=-1.0) printf("Value popped from stack top:%f\n",x);
			break;
			case 3:
            if (S.tos!=-1)
            {
                printf("Stack contains the following starting from Top of Stack:\n");
			    display(S);
            }
            else printf("Stack is Empty.");
			break;
			case 4:
            x=peek(S);
			if(x!=-1.0) printf("Top of stack contains:%f\n",x);
			break;
            case 5:
            if(isFull(S)) printf("Stack is full\n");
            else printf("Stack is not full\n");
            break;
            case 6:
            if(isEmpty(S)) printf("Stack is empty\n");
            else printf("Stack is not empty\n");
            break;
			case 7:
            x=size(S);
            printf("Size of stack is %d\n",(int)x);
            break;
            case 8:
            break;
			default:printf("Invalid choice\n");
		}
	}while(choice!=8);
}