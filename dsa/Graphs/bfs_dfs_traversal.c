#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Function to add an edge to the graph
void add_edge(int graph[][MAX_NODES], int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

// Function to perform Breadth First Search on the graph
void bfs(int graph[][MAX_NODES], int num_nodes, int start_node) {
    int visited[MAX_NODES] = {0};
    int queue[MAX_NODES];
    int front = 0, rear = 0;

    visited[start_node] = 1;
    queue[rear++] = start_node;

    printf("BFS Traversal: ");

    while (front < rear) {
        int curr_node = queue[front++];

        printf("%d ", curr_node);

        for (int i = 0; i < num_nodes; i++) {
            if (graph[curr_node][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\n");
}

// Function to perform Depth First Search on the graph
void dfs(int graph[][MAX_NODES], int num_nodes, int start_node, int visited[]) {
    visited[start_node] = 1;
    printf("%d ", start_node);

    for (int i = 0; i < num_nodes; i++) {
        if (graph[start_node][i] && !visited[i]) {
            dfs(graph, num_nodes, i, visited);
        }
    }
}

int main() {
    int num_nodes, num_edges;
    int graph[MAX_NODES][MAX_NODES] = {0};
    int visited[MAX_NODES] = {0};

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    printf("Enter the edges: \n");
    for (int i = 0; i < num_edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(graph, u, v);
    }

    // Display the adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    // Perform BFS traversal
    bfs(graph, num_nodes, 0);

    // Perform DFS traversal
    printf("DFS Traversal: ");
    dfs(graph, num_nodes, 0, visited);

    printf("\n");
    return 0;
}
