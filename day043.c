// Problem Statement:
// Construct a Binary Tree from the given level-order traversal.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers (-1 represents NULL)

// Output Format:
// - Print inorder traversal of the constructed tree

// Example:
// Input:
// 7
// 1 2 3 4 5 -1 6

// Output:
// 4 2 5 1 3 6
#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left, *right;
};

struct TreeNode *newNode(int val)
{
    if (val == -1)
        return NULL;
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Helper to build tree using a Queue
struct TreeNode *buildTree(int arr[], int n)
{
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct TreeNode *root = newNode(arr[0]);
    struct TreeNode *queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < n)
    {
        struct TreeNode *curr = queue[front++];

        // Left Child
        if (i < n)
        {
            curr->left = newNode(arr[i++]);
            if (curr->left)
                queue[rear++] = curr->left;
        }

        // Right Child
        if (i < n)
        {
            curr->right = newNode(arr[i++]);
            if (curr->right)
                queue[rear++] = curr->right;
        }
    }
    return root;
}

void inorder(struct TreeNode *root)
{
    if (!root)
        return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
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

    struct TreeNode *root = buildTree(arr, n);
    inorder(root);
    printf("\n");

    return 0;
}