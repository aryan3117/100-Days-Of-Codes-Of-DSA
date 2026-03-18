// Problem: Level Order Traversal

// Implement the solution for this problem.

// Input:
// - Input specifications

// Output:
// - Output specifications
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

// Build tree from level-order array using a Queue
struct TreeNode *buildTree(int arr[], int n)
{
    if (n == 0 || arr[0] == -1)
        return NULL;
    struct TreeNode *root = newNode(arr[0]);
    struct TreeNode *queue[2000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;
    while (i < n)
    {
        struct TreeNode *curr = queue[front++];
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

// Level Order Traversal: Process nodes level by level
void levelOrder(struct TreeNode *root)
{
    if (!root)
        return;
    struct TreeNode *queue[2000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear)
    {
        struct TreeNode *curr = queue[front++];
        printf("%d ", curr->val);

        if (curr->left)
            queue[rear++] = curr->left;
        if (curr->right)
            queue[rear++] = curr->right;
    }
}

int main()
{
    int n;
    if (scanf("%d", &n) != 1)
        return 0;
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct TreeNode *root = buildTree(arr, n);
    levelOrder(root);
    printf("\n");

    free(arr);
    return 0;
}