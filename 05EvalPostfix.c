#include <stdio.h>
#include <math.h>   //for pow
#include <stdlib.h> //for exit
#include <ctype.h>  //for isdigit
#define SIZE 100

struct stack
{
    int operand[SIZE];
    int top;
};
int isEmpty(struct stack *ps)
{
    if (ps->top == -1)
        return (1);
    else
        return (0);
}
void push(struct stack *ps, int a)
{
    if ((ps->top) == SIZE - 1)
        printf("Stack overflow");
    else
        ps->operand[++(ps->top)] = a;
}
int pop(struct stack *ps)
{
    if (isEmpty(ps))
    {
        printf("Stack underflow");
        exit(1);
    }
    return (ps->operand[(ps->top)--]);
}
int calculate(int a, int b, char symb)
{
    switch (symb)
    {
    case '+':
        return (a + b);
    case '-':
        return (a - b);
    case '*':
        return (a * b);

    case '/':
        return (a / b);
    case '^':
        return (pow(a, b));
    }
}

int main()
{
    struct stack p1;
    p1.top = -1;
    int i = 0;

    char expr[SIZE];
    int t1, t2;
    printf("Enter the postfix expression = ");
    scanf("%s", expr);
    while (expr[i])
    {
        if (isdigit(expr[i]))
        {
            push(&p1, expr[i] - '0');
        }
        else
        {
            t1 = pop(&p1);
            t2 = pop(&p1);
            push(&p1, calculate(t2, t1, expr[i]));
        }
        i++;
    }
    printf("\n\nAnswer = %d", pop(&p1));
    return 0;
}