// Problem: BST Search

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
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Insert function to build the initial BST
struct TreeNode *insert(struct TreeNode *root, int val)
{
    if (root == NULL)
        return newNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);
    return root;
}

// Search function: returns 1 if found, 0 otherwise
int search(struct TreeNode *root, int target)
{
    if (root == NULL)
        return 0;
    if (root->val == target)
        return 1;

    if (target < root->val)
    {
        return search(root->left, target);
    }
    return search(root->right, target);
}

int main()
{
    int n, target, val;
    if (scanf("%d %d", &n, &target) != 2)
        return 0;

    struct TreeNode *root = NULL;
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &val) == 1)
        {
            root = insert(root, val);
        }
    }

    if (search(root, target))
    {
        printf("Found\n");
    }
    else
    {
        printf("Not Found\n");
    }

    return 0;
}