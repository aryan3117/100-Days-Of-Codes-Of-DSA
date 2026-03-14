// Problem Statement:
// Given a queue of integers, reverse the queue using a stack.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers

// Output Format:
// - Print the reversed queue

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 50 40 30 20 10
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    int top;
} Stack;

void push(Stack *s, int x)
{
    s->data[++(s->top)] = x;
}

int pop(Stack *s)
{
    return s->data[(s->top)--];
}

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

void reverseQueue(Queue *q, int n)
{
    Stack s;
    s.data = (int *)malloc(n * sizeof(int));
    s.top = -1;

    // Transfer all elements from queue to stack
    while (q->front != NULL)
    {
        push(&s, dequeue(q));
    }

    // Transfer back from stack to queue to reverse order
    while (s.top != -1)
    {
        enqueue(q, pop(&s));
    }

    free(s.data);
}

int main()
{
    int n, val;
    if (scanf("%d", &n) != 1)
        return 0;

    Queue q = {NULL, NULL};
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &val) == 1)
        {
            enqueue(&q, val);
        }
    }

    reverseQueue(&q, n);

    while (q.front != NULL)
    {
        printf("%d%s", dequeue(&q), (q.front == NULL) ? "" : " ");
    }
    printf("\n");

    return 0;
}