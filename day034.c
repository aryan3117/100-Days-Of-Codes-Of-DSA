// Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

// Input:
// - Postfix expression with operands and operators

// Output:
// - Print the integer result

// Example:
// Input:
// 2 3 1 * + 9 -

// Output:
// -4

// Explanation:
// Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node **top, int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node **top)
{
    if (*top == NULL)
        return 0;
    struct Node *temp = *top;
    int val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}

int main()
{
    char token[10];
    struct Node *stack = NULL;
    char next_char;

    // This loop checks if we've reached the end of the line
    while (scanf("%s%c", token, &next_char) != EOF)
    {
        if (strlen(token) == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'))
        {
            int op2 = pop(&stack);
            int op1 = pop(&stack);

            if (token[0] == '+')
                push(&stack, op1 + op2);
            else if (token[0] == '-')
                push(&stack, op1 - op2);
            else if (token[0] == '*')
                push(&stack, op1 * op2);
            else if (token[0] == '/')
                push(&stack, op1 / op2);
        }
        else
        {
            push(&stack, atoi(token));
        }

        // If the character following the word is a newline, stop and print result
        if (next_char == '\n')
            break;
    }

    if (stack != NULL)
    {
        printf("%d\n", pop(&stack));
    }

    return 0;
}