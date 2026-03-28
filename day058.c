// Problem Statement:
// Construct a binary tree from given preorder and inorder traversal arrays.

// Input Format:
// - First line contains integer N
// - Second line contains preorder traversal
// - Third line contains inorder traversal

// Output Format:
// - Print postorder traversal of constructed tree

// Example:
// Input:
// 5
// 1 2 4 5 3
// 4 2 5 1 3

// Output:
// 4 5 2 3 1

// Explanation:
// Preorder identifies root, inorder splits left and right subtrees.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *createNode(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int findIndex(int inorder[], int start, int end, int val)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

struct Node *buildTree(int preorder[], int inorder[], int inStart, int inEnd, int *preIndex)
{
    if (inStart > inEnd)
        return NULL;

    int rootVal = preorder[*preIndex];
    (*preIndex)++;
    struct Node *root = createNode(rootVal);

    int inIndex = findIndex(inorder, inStart, inEnd, rootVal);

    root->left = buildTree(preorder, inorder, inStart, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return root;
}

void postorder(struct Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    int n;
    if (scanf("%d", &n) != 1)
        return 0;

    int *pre = (int *)malloc(n * sizeof(int));
    int *in = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &in[i]);

    int preIndex = 0;
    struct Node *root = buildTree(pre, in, 0, n - 1, &preIndex);

    postorder(root);
    printf("\n");

    free(pre);
    free(in);
    return 0;
}