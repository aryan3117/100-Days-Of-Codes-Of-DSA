// Problem: Deque (Double-Ended Queue)

// A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

// Common Operations:
// 1. push_front(value): Insert an element at the front of the deque.
// 2. push_back(value): Insert an element at the rear of the deque.
// 3. pop_front(): Remove an element from the front of the deque.
// 4. pop_back(): Remove an element from the rear of the deque.
// 5. front(): Return the front element of the deque.
// 6. back(): Return the rear element of the deque.
// 7. empty(): Check whether the deque is empty.
// 8. size(): Return the number of elements in the deque.

// Additional Operations:
// - clear(): Remove all elements from the deque.
// - erase(): Remove one or more elements from the deque.
// - swap(): Swap contents of two deques.
// - emplace_front(): Insert an element at the front without copying.
// - emplace_back(): Insert an element at the rear without copying.
// - resize(): Change the size of the deque.
// - assign(): Replace elements with new values.
// - reverse(): Reverse the order of elements.
// - sort(): Sort the elements in ascending order.

// Time Complexity:
// - push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
// - clear, erase, resize, assign, reverse: O(n)
// - sort: O(n log n)

// Input:
// - Sequence of deque operations with values (if applicable)

// Output:
// - Results of operations such as front, back, size, or the final state of the deque after all operations
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>  // <--- ADD THIS LINE

struct Node {
    int data;
    struct Node *next, *prev;
};

typedef struct
{
    struct Node *head, *tail;
    int count;
} Deque;

Deque *createDeque()
{
    Deque *dq = (Deque *)malloc(sizeof(Deque));
    dq->head = dq->tail = NULL;
    dq->count = 0;
    return dq;
}

void push_front(Deque *dq, int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = dq->head;

    if (dq->head == NULL)
        dq->tail = newNode;
    else
        dq->head->prev = newNode;

    dq->head = newNode;
    dq->count++;
}

void push_back(Deque *dq, int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = dq->tail;

    if (dq->tail == NULL)
        dq->head = newNode;
    else
        dq->tail->next = newNode;

    dq->tail = newNode;
    dq->count++;
}

int pop_front(Deque *dq)
{
    if (dq->head == NULL)
        return -1;
    struct Node *temp = dq->head;
    int val = temp->data;
    dq->head = dq->head->next;

    if (dq->head == NULL)
        dq->tail = NULL;
    else
        dq->head->prev = NULL;

    free(temp);
    dq->count--;
    return val;
}

int pop_back(Deque *dq)
{
    if (dq->tail == NULL)
        return -1;
    struct Node *temp = dq->tail;
    int val = temp->data;
    dq->tail = dq->tail->prev;

    if (dq->tail == NULL)
        dq->head = NULL;
    else
        dq->tail->next = NULL;

    free(temp);
    dq->count--;
    return val;
}

void display(Deque *dq)
{
    struct Node *curr = dq->head;
    while (curr)
    {
        printf("%d%s", curr->data, curr->next ? " " : "");
        curr = curr->next;
    }
    printf("\n");
}

int main()
{
    Deque *dq = createDeque();
    int n, val;
    char op[20];

    if (scanf("%d", &n) != 1)
        return 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%s", op);
        if (strcmp(op, "push_back") == 0)
        {
            scanf("%d", &val);
            push_back(dq, val);
        }
        else if (strcmp(op, "push_front") == 0)
        {
            scanf("%d", &val);
            push_front(dq, val);
        }
        else if (strcmp(op, "pop_front") == 0)
        {
            pop_front(dq);
        }
        else if (strcmp(op, "pop_back") == 0)
        {
            pop_back(dq);
        }
    }

    display(dq);
    return 0;
}