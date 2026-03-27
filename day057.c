// Problem Statement:
// Convert a binary tree into its mirror image by swapping left and right children at every node.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 indicates NULL)

// Output Format:
// - Print inorder traversal of mirrored tree

// Example:
// Input:
// 7
// 1 2 3 4 5 6 7

// Output:
// 7 3 6 1 5 2 4

// Explanation:
// Each node’s left and right children are swapped recursively.
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

void mirror(struct Node *root)
{
    if (root == NULL)
        return;

    // Swap left and right pointers
    struct Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
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

    mirror(root);
    inorder(root);
    printf("\n");

    free(arr);
    return 0;
}