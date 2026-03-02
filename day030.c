// Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of terms)
// - Next n lines: two integers (coefficient and exponent)

// Output:
// - Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

// Example:
// Input:
// 5
// 10 4
// 20 3
// 30 2
// 40 1
// 50 0

// Output:
// 10x^4 + 20x^3 + 30x^2 + 40x + 50

// Explanation:
// Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.
#include <stdio.h>
#include <stdlib.h>

struct Term
{
    int coeff;
    int exp;
    struct Term *next;
};

int main()
{
    int n;
    if (scanf("%d", &n) != 1 || n <= 0)
        return 0;

    struct Term *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++)
    {
        struct Term *newTerm = (struct Term *)malloc(sizeof(struct Term));
        scanf("%d %d", &newTerm->coeff, &newTerm->exp);
        newTerm->next = NULL;

        if (!head)
        {
            head = newTerm;
            tail = head;
        }
        else
        {
            tail->next = newTerm;
            tail = newTerm;
        }
    }

    struct Term *curr = head;
    while (curr != NULL)
    {
        // Handle coefficient and variable
        if (curr->exp == 0)
        {
            printf("%d", curr->coeff);
        }
        else if (curr->exp == 1)
        {
            printf("%dx", curr->coeff);
        }
        else
        {
            printf("%dx^%d", curr->coeff, curr->exp);
        }

        // Print ' + ' only if there is a next term
        if (curr->next != NULL)
        {
            printf(" + ");
        }

        curr = curr->next;
    }
    printf("\n");

    return 0;
}