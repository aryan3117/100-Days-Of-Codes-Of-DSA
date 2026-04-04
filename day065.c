// Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

// Output:
// - YES or NO
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

int dfs(int u, int p, struct Node **adj, int *visited)
{
    visited[u] = 1;

    struct Node *temp = adj[u];
    while (temp)
    {
        int v = temp->v;
        if (!visited[v])
        {
            if (dfs(v, u, adj, visited))
                return 1;
        }
        else if (v != p)
        {
            return 1;
        }
        temp = temp->next;
    }
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
        struct Node *n1 = createNode(v);
        n1->next = adj[u];
        adj[u] = n1;

        struct Node *n2 = createNode(u);
        n2->next = adj[v];
        adj[v] = n2;
    }

    int *visited = (int *)calloc(V, sizeof(int));
    int hasCycle = 0;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, -1, adj, visited))
            {
                hasCycle = 1;
                break;
            }
        }
    }

    printf("%s\n", hasCycle ? "YES" : "NO");

    return 0;
}