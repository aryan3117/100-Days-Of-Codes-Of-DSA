// Problem Statement:
// Check whether a given binary tree satisfies the Min-Heap property.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal

// Output Format:
// - Print YES if valid Min-Heap, otherwise NO

// Example:
// Input:
// 7
// 1 3 5 7 9 8 10

// Output:
// YES

// Explanation:
// Each parent node must be smaller than its children.
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
    if (n <= 0 || arr[0] == -1)
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

int isMinHeap(struct Node *root)
{
    if (root == NULL)
        return 1;

    // Check left child property
    if (root->left != NULL && root->data > root->left->data)
        return 0;

    // Check right child property
    if (root->right != NULL && root->data > root->right->data)
        return 0;

    return isMinHeap(root->left) && isMinHeap(root->right);
}

int main()
{
    int n;
    if (scanf("%d", &n) != 1)
        return 0;

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node *root = buildTree(arr, n);

    if (isMinHeap(root))
        printf("YES\n");
    else
        printf("NO\n");

    free(arr);
    return 0;
}