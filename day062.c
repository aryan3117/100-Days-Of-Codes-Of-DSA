// Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

// Input:
// - n (vertices)
// - m (edges)
// - edges (u, v)

// Output:
// - List of adjacency lists for each vertex
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int vertex;
    struct Node *next;
};

struct Node *createNode(int v)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

int main()
{
    int n, m;
    if (scanf("%d %d", &n, &m) != 2)
        return 0;

    // Array of pointers to represent adjacency list
    struct Node **adj = (struct Node **)malloc(n * sizeof(struct Node *));
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        // Insert at the beginning for O(1) addition
        struct Node *n1 = createNode(v);
        n1->next = adj[u];
        adj[u] = n1;

        // Symmetric entry for undirected graph
        struct Node *n2 = createNode(u);
        n2->next = adj[v];
        adj[v] = n2;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d: ", i);
        struct Node *temp = adj[i];
        while (temp)
        {
            printf("%d%s", temp->vertex, temp->next ? " -> " : "");
            temp = temp->next;
        }
        printf("\n");
    }

    // Cleanup memory
    for (int i = 0; i < n; i++)
    {
        struct Node *temp = adj[i];
        while (temp)
        {
            struct Node *prev = temp;
            temp = temp->next;
            free(prev);
        }
    }
    free(adj);

    return 0;
}