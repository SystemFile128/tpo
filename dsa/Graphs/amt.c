#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
int adj[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];
int n;

void bfs(int i)
{
    int queue[MAX_VERTICES], front = 0, rear = 0;
    queue[rear++] = i;
    visited[i] = true;
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

void dfs(int i)
{
    int stack[n], top = -1;
    stack[++top] = i;
    visited[i] = true;
    while (top != -1)
    {
        int current = stack[top--];
        printf("%d ", current);
        for (int i = 0; i < n; i++)
        {
            if (adj[current][i] == 1 && !visited[i])
            {
                stack[++top] = i;
                visited[i] = true;
            }
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

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    bfs(0);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    dfs(0);
    printf("\n");
}