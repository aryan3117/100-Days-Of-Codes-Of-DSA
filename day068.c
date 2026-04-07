// Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
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

int main()
{
    int V, E;
    if (scanf("%d %d", &V, &E) != 2)
        return 0;

    struct Node **adj = (struct Node **)malloc(V * sizeof(struct Node *));
    int *indegree = (int *)calloc(V, sizeof(int));
    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    for (int i = 0; i < E; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        struct Node *newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
        indegree[v]++;
    }

    int *queue = (int *)malloc(V * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            queue[rear++] = i;
        }
    }

    int count = 0;
    int *topo = (int *)malloc(V * sizeof(int));

    while (front < rear)
    {
        int u = queue[front++];
        topo[count++] = u;

        struct Node *temp = adj[u];
        while (temp)
        {
            int v = temp->v;
            indegree[v]--;
            if (indegree[v] == 0)
            {
                queue[rear++] = v;
            }
            temp = temp->next;
        }
    }

    if (count != V)
    {
        printf("Cycle detected! No topological ordering possible.\n");
    }
    else
    {
        for (int i = 0; i < V; i++)
        {
            printf("%d ", topo[i]);
        }
        printf("\n");
    }

    return 0;
}