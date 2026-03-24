// Problem Statement:
// Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

// Input Format:
// - First line contains integer N (number of nodes)
// - Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

// Output Format:
// - Print nodes column by column from leftmost to rightmost vertical line

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 4
// 2
// 1 5 6
// 3
// 7

// Explanation:
// Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Pair
{
    struct Node *node;
    int hd;
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

// Helper to build tree from level-order input
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

void verticalOrder(struct Node *root)
{
    if (root == NULL)
        return;

    struct Pair q[2000];
    int front = 0, rear = 0;

    int hdArr[2000], valArr[2000];
    int count = 0;
    int min_hd = 0, max_hd = 0;

    q[rear++] = (struct Pair){root, 0};

    while (front < rear)
    {
        struct Pair cur = q[front++];

        hdArr[count] = cur.hd;
        valArr[count] = cur.node->data;
        count++;

        if (cur.hd < min_hd)
            min_hd = cur.hd;
        if (cur.hd > max_hd)
            max_hd = cur.hd;

        if (cur.node->left)
            q[rear++] = (struct Pair){cur.node->left, cur.hd - 1};
        if (cur.node->right)
            q[rear++] = (struct Pair){cur.node->right, cur.hd + 1};
    }

    // Print column by column
    for (int i = min_hd; i <= max_hd; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if (hdArr[j] == i)
                printf("%d ", valArr[j]);
        }
        printf("\n");
    }
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
    verticalOrder(root);

    free(arr);
    return 0;
}