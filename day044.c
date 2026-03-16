// Problem Statement:
// Perform inorder, preorder, and postorder traversals of a given binary tree.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 represents NULL)

// Output Format:
// - Print inorder, preorder, and postorder traversals

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 4 2 5 1 6 3 7
// 1 2 4 5 3 6 7
// 4 5 2 6 7 3 1
#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left, *right;
};

// Create a new tree node
struct TreeNode *newNode(int val)
{
    if (val == -1)
        return NULL;
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from Level-Order array using a Queue
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

// Inorder: Left -> Root -> Right
void inorder(struct TreeNode *root)
{
    if (!root)
        return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// Preorder: Root -> Left -> Right
void preorder(struct TreeNode *root)
{
    if (!root)
        return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

// Postorder: Left -> Right -> Root
void postorder(struct TreeNode *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
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

    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");

    free(arr);
    return 0;
}