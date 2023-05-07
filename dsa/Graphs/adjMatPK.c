#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100
#define MIN_WEIGHT 1

int parent[MAX_VERTICES];
int graph[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];

int find(int i)
{
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

void union_set(int a, int b)
{
    int parentA = find(a);
    int parentB = find(b);
    parent[parentB] = parentA;
}

void kruskals(int vertices)
{
    int min_cost = 0;
    for (int i = 0; i < vertices; i++)
        parent[i] = i;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (graph[i][j] != 0)
            {
                int set1 = find(i);
                int set2 = find(j);
                if (set1 != set2)
                {
                    printf("Edge (%d, %d) with cost %d included in the MST\n", i, j, graph[i][j]);
                    min_cost += graph[i][j];
                    union_set(set1, set2);
                }
            }
        }
    }
    printf("Minimum cost of the MST by Kruskal's algorithm: %d\n", min_cost);
}

void prims(int vertices)
{
    int min_cost = 0;
    int start = 0;
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = false;
        parent[i] = -1;
    }
    visited[start] = true;
    for (int i = 0; i < vertices - 1; i++)
    {
        int min = INT_MAX;
        int x, y;
        for (int j = 0; j < vertices; j++)
        {
            if (visited[j])
            {
                for (int k = 0; k < vertices; k++)
                {
                    if (!visited[k] && graph[j][k])
                    {
                        if (min > graph[j][k])
                        {
                            min = graph[j][k];
                            x = j;
                            y = k;
                        }
                    }
                }
            }
        }
        visited[y] = true;
        parent[y] = x;
        printf("Edge (%d, %d) with cost %d included in the MST\n", x, y, graph[x][y]);
        min_cost += graph[x][y];
    }
    printf("Minimum cost of the MST by Prim's algorithm: %d\n", min_cost);
}

int main()
{
    int vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("\n");
    printf("Kruskal's Algorithm:\n");
    kruskals(vertices);
    printf("\n");
    printf("Prim's Algorithm:\n");
    prims(vertices);
    return 0;
}
