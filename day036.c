// Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of elements to enqueue)
// - Second line: n space-separated integers
// - Third line: integer m (number of dequeue operations)

// Output:
// - Print queue elements from front to rear after operations, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 30 40 50 10 20

// Explanation:
// Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;

    // Using a fixed size for the circular array logic
    int capacity = 100;
    int *queue = (int *)malloc(capacity * sizeof(int));
    int front = -1, rear = -1;

    // 1. Read number of elements to enqueue
    if (scanf("%d", &n) != 1)
        return 0;

    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);

        if (front == -1)
        {
            front = rear = 0;
            queue[rear] = val;
        }
        else
        {
            // Circular increment of rear
            rear = (rear + 1) % capacity;
            queue[rear] = val;
        }
    }

    // 2. Read number of dequeue operations
    if (scanf("%d", &m) != 1)
        m = 0;

    for (int i = 0; i < m; i++)
    {
        if (front == -1)
            break; // Underflow

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            // Circular increment of front
            front = (front + 1) % capacity;
        }
    }

    // 3. Display remaining elements
    if (front == -1)
        return 0;

    int i = front;
    while (1)
    {
        printf("%d", queue[i]);
        if (i == rear)
            break;
        printf(" ");
        i = (i + 1) % capacity;
    }
    printf("\n");

    free(queue);
    return 0;
}