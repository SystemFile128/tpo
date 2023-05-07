#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100
#define MIN_DIST INT_MAX

typedef struct edge
{
    int dest, weight;
    struct edge *next;
} Edge;

typedef struct vertex
{
    int visited;
    Edge *head;
} Vertex;

typedef struct graph
{
    Vertex vertices[MAX_VERTICES];
    int num_vertices;
} Graph;

void addEdge(Graph *graph, int src, int dest, int weight)
{
    Edge *edge = (Edge *)malloc(sizeof(Edge));
    edge->dest = dest;
    edge->weight = weight;
    edge->next = graph->vertices[src].head;
    graph->vertices[src].head = edge;
}

int getUnvisitedVertex(int dist[], int n, int visited[])
{
    int min_dist = MIN_DIST, min_index = -1;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && dist[i] < min_dist)
        {
            min_dist = dist[i];
            min_index = i;
        }
    }

    return min_index;
}

void prims(Graph *graph, int start)
{
    int dist[MAX_VERTICES];
    int parent[MAX_VERTICES];
    int visited[MAX_VERTICES];

    for (int i = 0; i < graph->num_vertices; i++)
    {
        dist[i] = MIN_DIST;
        parent[i] = -1;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (int i = 0; i < graph->num_vertices - 1; i++)
    {
        int u = getUnvisitedVertex(dist, graph->num_vertices, visited);

        visited[u] = 1;

        Edge *edge = graph->vertices[u].head;
        while (edge != NULL)
        {
            int v = edge->dest;
            int weight = edge->weight;

            if (!visited[v] && weight < dist[v])
            {
                dist[v] = weight;
                parent[v] = u;
            }

            edge = edge->next;
        }
    }

    for (int i = 1; i < graph->num_vertices; i++)
        printf("%d - %d: %d\n", parent[i], i, dist[i]);
}

int main()
{
    Graph graph;

    printf("Enter the number of vertices: ");
    scanf("%d", &graph.num_vertices);

    printf("Enter the number of edges: ");
    int num_edges;
    scanf("%d", &num_edges);
    printf("Enter the edges (src dest weight):\n");
    int src, dest, weight;
    for (int i = 0; i < num_edges; i++)
    {
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(&graph, src, dest, weight);
        addEdge(&graph, dest, src, weight);
    }

    printf("Enter the start vertex for Prim's algorithm: ");
    int start;
    scanf("%d", &start);

    prims(&graph, start);

    return 0;
}