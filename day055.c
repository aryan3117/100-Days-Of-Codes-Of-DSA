// Problem Statement:
// Print the nodes visible when the binary tree is viewed from the right side.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 indicates NULL)

// Output Format:
// - Print right view nodes

// Example:
// Input:
// 7
// 1 2 3 4 5 -1 6

// Output:
// 1 3 6

// Explanation:
// At each level, the rightmost node is visible from the right view.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

// Standard node creation
struct Node *newNode(int data)
{
    if (data == -1)
        return NULL;
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Builds the tree from level-order array input
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

void leftView(struct Node *root)
{
    if (root == NULL)
        return;

    struct Node *q[2000];
    int front = 0, rear = 0;
    q[rear++] = root;

    while (front < rear)
    {
        int size = rear - front;

        for (int i = 0; i < size; i++)
        {
            struct Node *temp = q[front++];

            // If it's the first node of the current level, it's visible from the left
            if (i == 0)
                printf("%d ", temp->data);

            if (temp->left != NULL)
                q[rear++] = temp->left;
            if (temp->right != NULL)
                q[rear++] = temp->right;
        }
    }
    printf("\n");
}

int main()
{
    int n;
    // Input format: N followed by N level-order elements
    if (scanf("%d", &n) != 1)
        return 0;

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    struct Node *root = buildTree(arr, n);
    leftView(root);

    free(arr);
    return 0;
}