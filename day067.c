// Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
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

void dfs(int u, struct Node **adj, int *vis, int *stack, int *top)
{
    vis[u] = 1;
    struct Node *temp = adj[u];
    while (temp)
    {
        if (!vis[temp->v])
        {
            dfs(temp->v, adj, vis, stack, top);
        }
        temp = temp->next;
    }
    stack[(*top)++] = u;
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
    int *stack = (int *)malloc(V * sizeof(int));
    int top = 0;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, stack, &top);
        }
    }

    for (int i = top - 1; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");

    return 0;
}