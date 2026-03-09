// Problem Statement:
// Implement a Priority Queue using an array. An element with smaller value has higher priority.

// Supported Operations:
// - insert x
// - delete
// - peek

// Input Format:
// - First line contains integer N
// - Next N lines contain operations

// Output Format:
// - Print the deleted or peeked element
// - Print -1 if the queue is empty

// Example:
// Input:
// 5
// insert 30
// insert 10
// insert 20
// delete
// peek

// Output:
// 10
// 20
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int heap[MAX];
int size = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Maintains min-heap property by bubbling down
void minHeapify(int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(&heap[i], &heap[smallest]);
        minHeapify(smallest);
    }
}

// Inserts value and bubbles up
void insert(int x)
{
    if (size >= MAX)
        return;
    heap[size] = x;
    int i = size;
    size++;

    while (i != 0 && heap[(i - 1) / 2] > heap[i])
    {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Prints and removes the smallest element
void delete()
{
    if (size <= 0)
    {
        printf("-1\n");
        return;
    }
    // Print the root (smallest element) before removing
    printf("%d\n", heap[0]);

    heap[0] = heap[size - 1];
    size--;
    minHeapify(0);
}

// Prints the current smallest element without removing
void peek()
{
    if (size <= 0)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", heap[0]);
    }
}

int main()
{
    int n;
    if (scanf("%d", &n) != 1)
        return 0;

    char op[10];
    int val;

    for (int i = 0; i < n; i++)
    {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0)
        {
            if (scanf("%d", &val) == 1)
            {
                insert(val);
            }
        }
        else if (strcmp(op, "delete") == 0)
        {
            delete();
        }
        else if (strcmp(op, "peek") == 0)
        {
            peek();
        }
    }

    return 0;
}