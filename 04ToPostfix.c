#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //isalnum
#define SIZE 20
typedef struct
{
    char a[SIZE]; // stack of operators
    int tos;
} Stack;
void push(Stack *s, char ele)
{
    if (s->tos == SIZE - 1)
    {
        printf("Stack overflow");
        return;
    }
    else
    {
        s->tos++;
        s->a[s->tos] = ele;
    }
}
char pop(Stack *s)
{
    char x = s->a[s->tos];
    s->tos--;
    return x;
}
int isEmpty(Stack s)
{
    if (s.tos == -1)
        return 1;
    else
        return 0;
}
int precedence(char c)
{
    if (c == '(') // lowest precedence to (
        return 0;
    else if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')

        return 2;
    else if (c == '^' || c == '$') // highest precedence to ^
        return 3;
}
int main()
{
    Stack s1;
    char str[SIZE], post[SIZE]; // str for input string
    // post is for output string
    int i, j = 0;
    char x;
    s1.tos = -1;
    printf("Enter Infix Expression: ");
    gets(str);
    for (i = 0; str[i] != '\0'; i++) // or for(i = 0 ; i < strlen(str);i++)
    {
        if (isalnum(str[i])) // if operand
        {
            post[j] = str[i]; // put it in postfix string
            j++;
        }
        else // if operator
        {
            if (str[i] == '(')
            {
                push(&s1, str[i]);
            }
            else if (str[i] == ')')
            {
                // pop operators from stack and put it in postfix string until '(' encountered
                while ((x = pop(&s1)) != '(') // if popped element is'(' discard
                {
                    post[j] = x;
                    j++;
                }
            }
            else if (isEmpty(s1) || precedence(str[i]) > precedence(s1.a[s1.tos])) // if str[i] is a operator
            {
                // stack is empty push

                // if str[i] is opeator having higher precedence than stack top operator, push it

                push(&s1, str[i]);
            }
            else
            {
                // if str[i] is operator having less or equalprecedence than stack top operator,
                // it means stack top operators having higher or equal precedence
                // go on popping such operators

                // while popping you have to ensure stack is notempty
                while (!isEmpty(s1) && (precedence(str[i]) <= precedence(s1.a[s1.tos])))
                {
                    post[j] = pop(&s1); // pop operator from stack having higher or equal precedence
                                        // make it a part of output string

                    j++;
                }
                push(&s1, str[i]); // push the current scanned operator on stack
            }
        }
    }
    while (!isEmpty(s1)) // at the end pop all operators and put them in postfix string
    {
        post[j] = pop(&s1);
        j++;
    }
    post[j] = '\0'; // put null character at the end

    printf("Postfix expression is: %s", post); // print output
    return (0);
}