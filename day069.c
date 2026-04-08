// Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node
{
    int v, w;
    struct Node *next;
} Node;

typedef struct
{
    int dist, node;
} HeapNode;

void swap(HeapNode *a, HeapNode *b)
{
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(HeapNode *heap, int size, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && heap[l].dist < heap[smallest].dist)
        smallest = l;
    if (r < size && heap[r].dist < heap[smallest].dist)
        smallest = r;
    if (smallest != i)
    {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, size, smallest);
    }
}

void push(HeapNode *heap, int *size, int d, int u)
{
    heap[*size] = (HeapNode){d, u};
    int i = (*size)++;
    while (i != 0 && heap[(i - 1) / 2].dist > heap[i].dist)
    {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

HeapNode pop(HeapNode *heap, int *size)
{
    HeapNode root = heap[0];
    heap[0] = heap[--(*size)];
    heapify(heap, *size, 0);
    return root;
}

int main()
{
    int V, E, S;
    if (scanf("%d %d %d", &V, &E, &S) != 3)
        return 0;

    Node **adj = (Node **)calloc(V, sizeof(Node *));
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        Node *n1 = (Node *)malloc(sizeof(Node));
        n1->v = v;
        n1->w = w;
        n1->next = adj[u];
        adj[u] = n1;
        Node *n2 = (Node *)malloc(sizeof(Node));
        n2->v = u;
        n2->w = w;
        n2->next = adj[v];
        adj[v] = n2;
    }

    int *dist = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[S] = 0;

    HeapNode *heap = (HeapNode *)malloc(E * 10 * sizeof(HeapNode));
    int size = 0;
    push(heap, &size, 0, S);

    while (size > 0)
    {
        HeapNode top = pop(heap, &size);
        int d = top.dist;
        int u = top.node;

        if (d > dist[u])
            continue;

        Node *curr = adj[u];
        while (curr)
        {
            if (dist[u] + curr->w < dist[curr->v])
            {
                dist[curr->v] = dist[u] + curr->w;
                push(heap, &size, dist[curr->v], curr->v);
            }
            curr = curr->next;
        }
    }

    for (int i = 0; i < V; i++)
        printf("%d ", dist[i]);
    printf("\n");

    return 0;
}