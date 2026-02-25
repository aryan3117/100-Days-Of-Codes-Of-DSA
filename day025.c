// Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of nodes)
// - Second line: n space-separated integers (linked list elements)
// - Third line: integer key (element to be counted)

// Output:
// - Print the number of times the key appears in the linked list

// Example:
// Input:
// 6
// 10 20 30 20 40 20
// 20

// Output:
// 3

// Explanation:
// Traverse the linked list from head to end. Each time a node's data matches the given key, increment a counter. After traversal, print the final count.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    int n, key, count = 0;
    struct Node *head = NULL, *tail = NULL;

    /* Read number of nodes */
    if (scanf("%d", &n) != 1 || n < 0)
        return 0;

    /* Build the linked list dynamically */
    for (int i = 0; i < n; i++)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            tail = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    /* Read the key to search for */
    scanf("%d", &key);

    /* Traverse and count occurrences */
    struct Node *current = head;
    while (current != NULL)
    {
        if (current->data == key)
        {
            count++;
        }
        current = current->next;
    }

    printf("%d\n", count);

    return 0;
}