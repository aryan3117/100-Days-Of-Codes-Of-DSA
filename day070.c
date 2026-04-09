// Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

// Input:
// - n vertices
// - m edges (u,v,w)

// Output:
// - Shortest distances OR NEGATIVE CYCLE
#include <stdio.h>

#define INF 1000000

int main()
{
    int V, E, S;
    int edges[200][3];
    int dist[100];

    // Input: Vertices, Edges, Source
    if (scanf("%d %d %d", &V, &E, &S) != 3)
        return 0;

    // Input: Edges (u, v, weight)
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

    // Initialize distances
    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[S] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            if (dist[u] != INF && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for negative cycle
    int hasCycle = 0;
    for (int j = 0; j < E; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];
        if (dist[u] != INF && dist[u] + wt < dist[v])
        {
            hasCycle = 1;
            break;
        }
    }

    // Output
    if (hasCycle)
    {
        printf("-1\n");
    }
    else
    {
        for (int i = 0; i < V; i++)
        {
            if (dist[i] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i]);
        }
        printf("\n");
    }

    return 0;
}