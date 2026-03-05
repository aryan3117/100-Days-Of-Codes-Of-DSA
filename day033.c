// Problem: Convert an infix expression to postfix notation using stack.

// Input:
// - Single line: infix expression (operands are single characters)

// Output:
// - Print the postfix expression

// Example:
// Input:
// A+B*C

// Output:
// ABC*+

// Explanation:
// Operator precedence: * > +
// Use stack to handle operator precedence and associativity
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Helper to determine operator precedence */
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

int main()
{
    char infix[100], stack[100];
    int top = -1;

    if (scanf("%s", infix) != 1)
        return 0;

    for (int i = 0; infix[i] != '\0'; i++)
    {
        char c = infix[i];

        // If operand, print it immediately
        if (isalnum(c))
        {
            printf("%c", c);
        }
        // If '(', push to stack
        else if (c == '(')
        {
            stack[++top] = c;
        }
        // If ')', pop until '(' is found
        else if (c == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                printf("%c", stack[top--]);
            }
            top--; // pop '('
        }
        // If operator
        else
        {
            while (top != -1 && precedence(stack[top]) >= precedence(c))
            {
                printf("%c", stack[top--]);
            }
            stack[++top] = c;
        }
    }

    // Pop remaining operators from stack
    while (top != -1)
    {
        printf("%c", stack[top--]);
    }
    printf("\n");

    return 0;
}