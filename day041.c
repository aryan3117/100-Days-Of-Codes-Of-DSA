// Problem Statement:
// Implement a Queue using a linked list supporting enqueue and dequeue operations.

// Input Format:
// - First line contains integer N
// - Next N lines contain queue operations

// Output Format:
// - Print dequeued elements
// - Print -1 if dequeue is attempted on an empty queue
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *front, *rear;
} Queue;

void enqueue(Queue *q, int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    if (q->rear == NULL)
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue *q)
{
    if (q->front == NULL)
        return -1;
    Node *temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return val;
}

int main()
{
    int n;
    // Standard practice: check if scanf succeeds
    if (scanf("%d", &n) != 1)
        return 0;

    Queue q = {NULL, NULL};
    char op[20];
    int val;

    for (int i = 0; i < n; i++)
    {
        // IMPORTANT: The space before %s clears the input buffer
        if (scanf(" %s", op) != 1)
            break;

        if (strcmp(op, "enqueue") == 0)
        {
            scanf("%d", &val);
            enqueue(&q, val);
        }
        else if (strcmp(op, "dequeue") == 0)
        {
            printf("%d\n", dequeue(&q));
        }
    }

    return 0;
}