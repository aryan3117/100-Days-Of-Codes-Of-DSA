// Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print the merged linked list elements, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 35 45

// Output:
// 10 15 20 25 30 35 40 45 50

// Explanation:
// Compare nodes of both lists, append smaller to result, continue until all nodes are merged.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createList(int size)
{
    if (size <= 0)
        return NULL;
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < size; i++)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (!head)
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
    return head;
}

int main()
{
    int n, m;

    if (scanf("%d", &n) != 1)
        return 0;
    struct Node *list1 = createList(n);

    if (scanf("%d", &m) != 1)
        return 0;
    struct Node *list2 = createList(m);

    struct Node dummy;
    dummy.next = NULL;
    struct Node *tail = &dummy;

    /* Merge by re-linking existing nodes based on comparison */
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data <= list2->data)
        {
            tail->next = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    /* Attach remaining elements from the non-empty list */
    if (list1 != NULL)
        tail->next = list1;
    else
        tail->next = list2;

    struct Node *current = dummy.next;
    while (current != NULL)
    {
        printf("%d%s", current->data, current->next ? " " : "");
        current = current->next;
    }
    printf("\n");

    return 0;
}