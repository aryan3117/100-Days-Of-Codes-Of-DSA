// Problem: Detect cycle in directed graph using DFS and recursion stack.

// Output:
// - YES if cycle exists
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int v;
    struct Node *next;
};

struct Node *createNode(int v)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->v = v;
    newNode->next = NULL;
    return newNode;
}

int dfsCheck(int u, struct Node **adj, int *vis, int *pathVis)
{
    vis[u] = 1;
    pathVis[u] = 1;

    struct Node *temp = adj[u];
    while (temp)
    {
        int v = temp->v;
        if (!vis[v])
        {
            if (dfsCheck(v, adj, vis, pathVis))
                return 1;
        }
        else if (pathVis[v])
        {
            return 1;
        }
        temp = temp->next;
    }

    pathVis[u] = 0;
    return 0;
}

int main()
{
    int V, E;
    if (scanf("%d %d", &V, &E) != 2)
        return 0;

    struct Node **adj = (struct Node **)malloc(V * sizeof(struct Node *));
    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    for (int i = 0; i < E; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        struct Node *newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    int *vis = (int *)calloc(V, sizeof(int));
    int *pathVis = (int *)calloc(V, sizeof(int));
    int cycleFound = 0;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfsCheck(i, adj, vis, pathVis))
            {
                cycleFound = 1;
                break;
            }
        }
    }

    if (cycleFound)
        printf("True\n");
    else
        printf("False\n");

    return 0;
}