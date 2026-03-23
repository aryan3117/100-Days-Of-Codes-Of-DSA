// Problem Statement:
// Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 represents NULL)
// - Third line contains two node values

// Output Format:
// - Print the LCA value

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7
// 4 5

// Output:
// 2
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
    struct Node *queue[2000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;
    while (i < n)
    {
        struct Node *curr = queue[front++];
        if (i < n)
        {
            curr->left = newNode(arr[i++]);
            if (curr->left)
                queue[rear++] = curr->left;
        }
        if (i < n)
        {
            curr->right = newNode(arr[i++]);
            if (curr->right)
                queue[rear++] = curr->right;
        }
    }
    return root;
}

struct Node *LCA(struct Node *root, int n1, int n2)
{
    if (root == NULL || root->data == n1 || root->data == n2)
        return root;

    struct Node *left = LCA(root->left, n1, n2);
    struct Node *right = LCA(root->right, n1, n2);

    if (left != NULL && right != NULL)
        return root;

    return (left != NULL) ? left : right;
}

int main()
{
    int n, n1, n2;
    if (scanf("%d", &n) != 1)
        return 0;

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if (scanf("%d %d", &n1, &n2) != 2)
        return 0;

    struct Node *root = buildTree(arr, n);
    struct Node *res = LCA(root, n1, n2);

    if (res)
        printf("%d\n", res->data);

    free(arr);
    return 0;
}