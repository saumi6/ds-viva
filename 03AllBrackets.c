// Objective: Check if an expression containing different types of brackets (parentheses, curly braces, and square brackets) is balanced.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 100
typedef struct
{
    char items[STACK_SIZE];
    int top;
} BracketsStack;
void push(BracketsStack *stack, char element)
{
    if (stack->top == STACK_SIZE - 1)
    {
        printf("Stack overflow");
        exit(404);
    }

    stack->items[++stack->top] = element;
}
char pop(BracketsStack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack underflow");
        exit(404);
    }
    return stack->items[stack->top--];
}
int main()
{
    BracketsStack stack;
    stack.top = -1;
    char symbol;
    char expression[STACK_SIZE];
    printf("Enter an expression:\n");
    fgets(expression, STACK_SIZE, stdin);
    printf("Current expression:\t%s\n", expression);
    int i = 0;
    while (expression[i] != '\0')
    {
        if (expression[i] == '(' || expression[i] == '{' ||

            expression[i] == '[')

        {
            push(&stack, expression[i]);
        }
        else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']')

        {
            symbol = pop(&stack);
            if (expression[i] == ')' && symbol != '(' ||

                expression[i] == ']' && symbol != '[' || expression[i] == '}' && symbol != '{')
            {
                printf("Not a balanced expression");

                return 1; // Return 1 to indicate unbalanced expression
            }
        }
        i++;
    }
    printf("It is a valid expression");
    return 0; // Return 0 to indicate success
}