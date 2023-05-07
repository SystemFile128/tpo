#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

struct ListNode
{
    int vertex;
    struct ListNode *next;
};

int n;                              // number of vertices
struct ListNode *adj[MAX_VERTICES]; // adjacency list
bool visited[MAX_VERTICES];         // to keep track of visited vertices

// Function to add an edge to the adjacency list
void addEdge(int source, int dest)
{
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->vertex = dest;
    newNode->next = adj[source];
    adj[source] = newNode;
}

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

        struct ListNode *temp = adj[current];
        while (temp)
        {
            int dest = temp->vertex;
            if (!visited[dest])
            {
                queue[rear++] = dest;
                visited[dest] = true;
            }
            temp = temp->next;
        }
    }
}

// DFS function
void DFS(int current)
{
    int stack[n], top = -1;
    stack[++top] = current;
    visited[current] = true;

    while (top != -1)
    {
        current = stack[top--];
        printf("%d ", current);

        struct ListNode *temp = adj[current];
        while (temp)
        {
            int dest = temp->vertex;
            if (!visited[dest])
            {
                stack[++top] = dest;
                visited[dest] = true;
            }
            temp = temp->next;
        }
    }
}

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int m; // number of edges
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the edges:\n");
    for (int i = 0; i < m; i++)
    {
        int source, dest;
        scanf("%d%d", &source, &dest);
        addEdge(source, dest);
    }

    printf("BFS Traversal: ");
    BFS(0);
    printf("\n");

    // Resetting the visited array for DFS
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    printf("DFS Traversal: ");
    DFS(0);
    printf("\n");

    return 0;
}
