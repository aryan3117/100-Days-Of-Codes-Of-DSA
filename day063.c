// Problem: Perform DFS starting from a given source vertex using recursion.

// Input:
// - n
// - adjacency list
// - starting vertex s

// Output:
// - DFS traversal order
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

void dfs(int u, struct Node **adj, int *visited)
{
    visited[u] = 1;
    printf("%d ", u);

    struct Node *temp = adj[u];
    while (temp)
    {
        int v = temp->vertex;
        if (!visited[v])
        {
            dfs(v, adj, visited);
        }
        temp = temp->next;
    }
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

        struct Node *n1 = createNode(v);
        n1->next = adj[u];
        adj[u] = n1;

        struct Node *n2 = createNode(u);
        n2->next = adj[v];
        adj[v] = n2;
    }

    int *visited = (int *)calloc(V, sizeof(int));

    int startVertex;
    scanf("%d", &startVertex);

    dfs(startVertex, adj, visited);
    printf("\n");

    return 0;
}