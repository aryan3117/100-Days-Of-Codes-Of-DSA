// Problem: Perform BFS from a given source using queue.

// Input:
// - n
// - adjacency list
// - source s

// Output:
// - BFS traversal order
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

void bfs(int startNode, int V, struct Node **adj)
{
    int *visited = (int *)calloc(V, sizeof(int));
    int *queue = (int *)malloc(V * sizeof(int));
    int front = 0, rear = 0;

    visited[startNode] = 1;
    queue[rear++] = startNode;

    while (front < rear)
    {
        int u = queue[front++];
        printf("%d ", u);

        struct Node *temp = adj[u];
        while (temp)
        {
            int v = temp->vertex;
            if (!visited[v])
            {
                visited[v] = 1;
                queue[rear++] = v;
            }
            temp = temp->next;
        }
    }
    printf("\n");

    free(visited);
    free(queue);
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

    int start;
    scanf("%d", &start);

    bfs(start, V, adj);

    return 0;
}