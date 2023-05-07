#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int n;                               // number of vertices
int adj[MAX_VERTICES][MAX_VERTICES]; // adjacency matrix
bool visited[MAX_VERTICES];          // to keep track of visited vertices

// BFS function
void BFS(int start)
{
    int queue[MAX_VERTICES], front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = true;

    while (front != rear)
    {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < n; i++)
        {
            if (adj[current][i] == 1 && !visited[i])
            {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }
}

// DFS function
void DFS(int current)
{
    printf("%d ", current);
    visited[current] = true;

    for (int i = 0; i < n; i++)
    {
        if (adj[current][i] == 1 && !visited[i])
        {
            DFS(i);
        }
    }
}

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("BFS Traversal: ");
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            BFS(i);
        }
    }
    printf("\n");

    // Resetting the visited array for DFS
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    printf("DFS Traversal: ");
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            DFS(i);
        }
    }
    printf("\n");

    return 0;
}
