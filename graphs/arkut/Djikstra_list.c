#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct gnode 
{
    int vertex;
    int weight;
    struct gnode* next;
};

struct Adj_list
{
    struct gnode *head;
};

struct Graph{
    int size;

    struct Adj_list *Arr;
};

struct gnode * creategnode(int vertex,int weight)
{
    struct gnode* g=malloc(sizeof(struct gnode));
    g->vertex=vertex;
    g->weight=weight;
    g->next=NULL;
    return g;
}

struct Graph *creategraph(int size)
{
    struct Graph *g=malloc(sizeof(struct Graph));
    g->size=size;
    g->Arr=(struct Adj_list*)malloc(g->size *sizeof(struct gnode));
    for(int i=0;i<g->size;i++)
        g->Arr[i].head=NULL;
    return g;
}
void addEdge(struct Graph *g, int src, int dest, int weight)
{
    struct gnode *newnode =creategnode(dest,weight);
    newnode->next=g->Arr[src].head;
    g->Arr[src].head=newnode;

    struct gnode *node =creategnode(src,weight);
    node->next=g->Arr[dest].head;
    g->Arr[dest].head=node;
}

void shortestPath(struct Graph* graph, int start_vertex) {
int n=graph->size;
int distances[n];
int visited[n];
    for (int i = 0; i < graph->size; i++) {
        distances[i] = INT_MAX;
        visited[i] = 0;
    }
    distances[start_vertex] = 0;
    for (int i = 0; i < graph->size - 1; i++) 
    {
        int min_distance = INT_MAX;
        int min_vertex = -1;
        for (int j = 0; j < graph->size; j++) {
            if (!visited[j] && distances[j] < min_distance) {
                min_distance = distances[j];
                min_vertex = j;
            }
        }
        if (min_vertex == -1) {
            break;
        }
        visited[min_vertex] = 1;
        struct gnode* temp = graph->Arr[min_vertex].head;
        while (temp != NULL) {
            int u = min_vertex;
            int v = temp->vertex;
            int weight = temp->weight;
            if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
            }
            temp = temp->next;
        }
    }
    printf("Shortest paths from vertex %d:\n", start_vertex);
    for (int i = 0; i < graph->size; i++) {
        if (distances[i] == INT_MAX) 
        {
            printf("%d : No path\n");
} 
else {
printf("%d : %d\n", i, distances[i]);
}
}
}

void printGraph(struct Graph* graph) {
printf("Adjacency List:\n");
for (int i = 0; i < graph->size; i++) {
struct gnode* temp = graph->Arr[i].head;
printf("Vertex %d: ", i);
while (temp != NULL) {
printf("(%d, %d) ", temp->vertex, temp->weight);
temp = temp->next;
}
printf("\n");
}
}


int main() {
    int num_Vertices=5;
    int src,dest,weight;
    int start;
// printf("\nEnter the no. of vertices in your graph : ");
//   scanf("%d",&num_Vertices);

  struct Graph * graph = creategraph(num_Vertices);
//   printf("Enter the edges of the graph in the format <SRC> <DESTINATION> <WEIGHT> (enter -1 to exit):\n");
//   while(1){ 
//     scanf("%d %d %d",&src , &dest , &weight);
//     if(src == -1 &&  dest == -1 && weight == -1 )
//       break;
//     addEdge(graph,src,dest,weight);
//   }
addEdge(graph, 0, 1, 10);
addEdge(graph, 0, 4, 11);
addEdge(graph, 0, 3, 8);
addEdge(graph, 1, 2, 5);
addEdge(graph, 2, 1, 5);
addEdge(graph, 2, 3, 7);
addEdge(graph, 3, 4, 12);

printGraph(graph);


printf("\nEnter the start node : ");
scanf("%d",&start);
shortestPath(graph, start);
return 0;
}