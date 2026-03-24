// Problem Statement:
// Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 indicates NULL)

// Output Format:
// - Print traversal in zigzag order

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 1 3 2 4 5 6 7

// Explanation:
// Level 1 is printed left-to-right, level 2 right-to-left, and so on.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int data)
{
    if (data == -1)
        return NULL;
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node *buildTree(int arr[], int n)
{
    if (n == 0 || arr[0] == -1)
        return NULL;
    struct Node *root = newNode(arr[0]);
    struct Node *q[2000];
    int f = 0, r = 0;
    q[r++] = root;
    int i = 1;
    while (i < n)
    {
        struct Node *curr = q[f++];
        if (i < n)
        {
            curr->left = newNode(arr[i++]);
            if (curr->left)
                q[r++] = curr->left;
        }
        if (i < n)
        {
            curr->right = newNode(arr[i++]);
            if (curr->right)
                q[r++] = curr->right;
        }
    }
    return root;
}

void zigzagTraversal(struct Node *root)
{
    if (root == NULL)
        return;

    struct Node *q[2000];
    int front = 0, rear = 0;
    q[rear++] = root;

    int leftToRight = 1;

    while (front < rear)
    {
        int size = rear - front;
        int level[1000];

        for (int i = 0; i < size; i++)
        {
            struct Node *temp = q[front++];

            // Determine placement based on current direction
            int index = leftToRight ? i : (size - 1 - i);
            level[index] = temp->data;

            if (temp->left)
                q[rear++] = temp->left;
            if (temp->right)
                q[rear++] = temp->right;
        }

        for (int i = 0; i < size; i++)
        {
            printf("%d ", level[i]);
        }

        leftToRight = !leftToRight;
    }
    printf("\n");
}

int main()
{
    int n;
    if (scanf("%d", &n) != 1)
        return 0;

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    struct Node *root = buildTree(arr, n);
    zigzagTraversal(root);

    free(arr);
    return 0;
}