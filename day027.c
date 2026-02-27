// Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print value of intersection node or 'No Intersection'

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 30 40 50

// Output:
// 30

// Explanation:
// Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.
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

    struct Node *ptr1 = list1, *ptr2 = list2;
    int diff = (n > m) ? (n - m) : (m - n);

    /* Align starting points based on length difference */
    if (n > m)
    {
        for (int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    }
    else
    {
        for (int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }

    /* Traverse simultaneously to find the first common value */
    int found = 0;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->data == ptr2->data)
        {
            printf("%d\n", ptr1->data);
            found = 1;
            break;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    if (!found)
        printf("No Intersection\n");

    return 0;
}