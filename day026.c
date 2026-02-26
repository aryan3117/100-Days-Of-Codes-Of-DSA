// Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the linked list elements in forward order, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 10 20 30 40 50

// Explanation:
// Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.
#include <stdio.h>
#include <stdlib.h>

/* Doubly Linked List Node Structure */
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

int main()
{
    int n, val;
    struct Node *head = NULL, *tail = NULL;

    /* Read number of nodes */
    if (scanf("%d", &n) != 1 || n <= 0)
        return 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);

        /* Allocate memory for new node */
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL)
        {
            head = newNode;
            tail = head;
        }
        else
        {
            /* Link the current tail and the new node bidirectionally */
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    /* Forward Traversal */
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d%s", current->data, current->next ? " " : "");
        current = current->next;
    }
    printf("\n");

    return 0;
}