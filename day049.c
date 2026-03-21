// Problem: BST Insert

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

// Recursive insertion based on BST properties
struct TreeNode *insert(struct TreeNode *root, int val)
{
    if (root == NULL)
        return newNode(val);

    if (val < root->val)
    {
        root->left = insert(root->left, val);
    }
    else if (val > root->val)
    {
        root->right = insert(root->right, val);
    }
    return root;
}

void inorder(struct TreeNode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main()
{
    int n, val;
    if (scanf("%d", &n) != 1)
        return 0;

    struct TreeNode *root = NULL;
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &val) == 1)
        {
            root = insert(root, val);
        }
    }

    // Inorder traversal of a BST always yields sorted output
    inorder(root);
    printf("\n");

    return 0;
}