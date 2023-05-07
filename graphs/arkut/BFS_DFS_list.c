#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100

// Structure for a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure for the adjacency list
struct AdjList {
    struct Node* head;
};

// Structure for the graph
struct Graph {
    int numVertices;
    struct AdjList* array;
};

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->array = (struct AdjList*)malloc(numVertices * sizeof(struct AdjList));

    for (int i = 0; i < numVertices; i++)
        graph->array[i].head = NULL;

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to perform BFS traversal of the graph
void BFS(struct Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = {0}; // Array to keep track of visited vertices
    struct Node* queue[MAX_VERTICES];
    int front = 0, rear = 0;

    visited[startVertex] = 1;
    queue[rear++] = graph->array[startVertex].head;

    printf("BFS Traversal: ");

    while (front < rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->vertex);

        while (current->next != NULL) {
            current = current->next;
            int adjVertex = current->vertex;

            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[rear++] = graph->array[adjVertex].head;
            }
        }
    }
}

void DFS(int adj_matrix[10][10],int start_vertex, int num_vertices,int visited[]) {
    int stack[10];
    int top = -1;
    stack[++top] = start_vertex;
    while (top >= 0) {
        int current_vertex = stack[top--];
        if (visited[current_vertex]==0) 
        {
            visited[current_vertex] = 1;
            printf("%d ", current_vertex);
        }
        for (int i =0; i < num_vertices; i++) {
            if (adj_matrix[current_vertex][i] == 1 && visited[i]!=1)
             {
                stack[++top] = i;
            }
        }
    }
}
int main() {
    int numVertices, i, j;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    struct Graph* graph = createGraph(numVertices);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            int value;
            printf("%d & %d : ",i,j);
            scanf("%d", &value);
            if (value == 1)
                addEdge(graph, i, j);
        }
    }

    int startVertex;
    printf("Enter the starting vertex for BFS traversal: ");
    scanf("%d", &startVertex);

    BFS(graph, startVertex);

    return 0;
}
