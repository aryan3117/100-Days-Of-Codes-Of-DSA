// Problem Statement:
// Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers
// - Third line contains two node values

// Output Format:
// - Print the LCA value

// Example:
// Input:
// 7
// 6 2 8 0 4 7 9
// 2 8

// Output:
// 6
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
        return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

struct Node *LCA(struct Node *root, int n1, int n2)
{
    while (root != NULL)
    {
        if (n1 < root->data && n2 < root->data)
            root = root->left;
        else if (n1 > root->data && n2 > root->data)
            root = root->right;
        else
            return root;
    }
    return NULL;
}

int main()
{
    int n, n1, n2, val;
    if (scanf("%d", &n) != 1)
        return 0;

    struct Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &val) == 1)
        {
            root = insert(root, val);
        }
    }

    if (scanf("%d %d", &n1, &n2) == 2)
    {
        struct Node *res = LCA(root, n1, n2);
        if (res)
            printf("%d\n", res->data);
    }

    return 0;
}