// Problem Statement:
// Implement a Min Heap using an array where the smallest element is always at the root.

// Supported Operations:
// - insert x
// - extractMin
// - peek

// Input Format:
// - First line contains integer N
// - Next N lines contain heap operations

// Output Format:
// - Print results of extractMin and peek
// - Print -1 if operation cannot be performed

// Example:
// Input:
// 6
// insert 40
// insert 10
// insert 30
// peek
// extractMin
// peek

// Output:
// 10
// 10
// 30
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10001

typedef struct
{
    int data[MAX_SIZE];
    int size;
} MinHeap;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(MinHeap *h, int x)
{
    if (h->size >= MAX_SIZE)
        return;
    h->data[h->size] = x;
    int curr = h->size;
    h->size++;
    while (curr > 0)
    {
        int parent = (curr - 1) / 2;
        if (h->data[curr] < h->data[parent])
        {
            swap(&h->data[curr], &h->data[parent]);
            curr = parent;
        }
        else
            break;
    }
}

int extractMin(MinHeap *h)
{
    if (h->size <= 0)
        return -1;
    int minVal = h->data[0];
    h->data[0] = h->data[h->size - 1];
    h->size--;
    int curr = 0;
    while (1)
    {
        int smallest = curr;
        int left = 2 * curr + 1;
        int right = 2 * curr + 2;
        if (left < h->size && h->data[left] < h->data[smallest])
            smallest = left;
        if (right < h->size && h->data[right] < h->data[smallest])
            smallest = right;
        if (smallest != curr)
        {
            swap(&h->data[curr], &h->data[smallest]);
            curr = smallest;
        }
        else
            break;
    }
    return minVal;
}

int peek(MinHeap *h)
{
    if (h->size <= 0)
        return -1;
    return h->data[0];
}

int main()
{
    int n;
    if (scanf("%d", &n) != 1)
        return 0;

    MinHeap *h = (MinHeap *)malloc(sizeof(MinHeap));
    h->size = 0;

    char op[20];
    int val;

    for (int i = 0; i < n; i++)
    {
        // Adding a space before %s skips leading whitespace/newlines
        if (scanf(" %s", op) != 1)
            break;

        if (strcmp(op, "insert") == 0)
        {
            scanf("%d", &val);
            insert(h, val);
        }
        else if (strcmp(op, "extractMin") == 0)
        {
            int result = extractMin(h);
            printf("%d\n", result);
        }
        else if (strcmp(op, "peek") == 0)
        {
            int result = peek(h);
            printf("%d\n", result);
        }
    }

    free(h);
    return 0;
}