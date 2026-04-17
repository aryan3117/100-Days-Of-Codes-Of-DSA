// Problem Statement
// Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

// Input Format
// n m
// u v w
// ...

// Output Format
// Total weight of MST.

// Sample Input
// 4 5
// 1 2 3
// 1 3 5
// 2 3 1
// 2 4 4
// 3 4 2

// Sample Output
// 6

// Explanation
// One possible MST edges: (2-3), (3-4), (1-2)
#include <stdio.h>

#define INF 1000000000

int main()
{
    int n, m;
    if (scanf("%d %d", &n, &m) != 2)
        return 0;

    int graph[105][105];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            graph[i][j] = (i == j) ? 0 : INF;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        if (u <= 104 && v <= 104)
        {
            if (w < graph[u][v])
            {
                graph[u][v] = w;
                graph[v][u] = w;
            }
        }
    }

    int selected[105] = {0};
    selected[1] = 1;
    int edges_count = 0, total_weight = 0;

    while (edges_count < n - 1)
    {
        int min_weight = INF;
        int x = 0, y = 0;

        for (int i = 1; i <= n; i++)
        {
            if (selected[i])
            {
                for (int j = 1; j <= n; j++)
                {
                    if (!selected[j] && graph[i][j] < min_weight)
                    {
                        min_weight = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        if (y != 0)
        {
            selected[y] = 1;
            total_weight += min_weight;
            edges_count++;
        }
        else
        {
            break;
        }
    }

    printf("%d\n", total_weight);
    return 0;
}