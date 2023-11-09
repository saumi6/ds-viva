#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20
typedef struct
{
    char a[SIZE];
    int tos;
} Stack;
void push(Stack *s, char ele)
{
    s->tos++;           // increment tos pointer
    s->a[s->tos] = ele; // store '(' at the top of the stack
}
char pop(Stack *s)
{
    return (s->a[s->tos--]); // decrement tos pointer
}
int main()
{
    Stack s1;
    char str[20];
    s1.tos = -1;
    printf("Enter Expression: ");
    gets(str);                            // input expression
    for (int i = 0; i < strlen(str); i++) // traverse enƟre expression
    {
        if (str[i] == '(')      // check for '(' bracket
            push(&s1, str[i]);  // push '(' into stack
        else if (str[i] == ')') // check for ')' bracket
        {
            if (s1.tos != -1) // check if stack is not empty

                pop(&s1); // if stack not empty pop 1 '(' bracket from stack and discard it

            else
            { // if stack is empty

                printf("Corresponding '(' missing"); //')' does not have a corresponding '('bracket
                exit(0);                             // exit from program exectuƟon with return status as 0
            }
        }
    }
    /*AŌer traversing enƟre string*/
    if (s1.tos != -1)                        // check if stack is not empty
        printf("Corresponding ')' missing"); //'(' does not have a corresponding ')' bracket
    else                                     // if stack is empty
        printf("Paranthesis Matched");       // equal no of '(' and ')' brackets

    return 0;
}