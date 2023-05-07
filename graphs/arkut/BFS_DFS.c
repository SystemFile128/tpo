#include<stdio.h>
#include<stdlib.h>
#define max 10
struct gnode{
    int vertice;
    struct gnode *next;
};

struct queue{
    int size;
    int f;
    int r;
    int * arr;
};
int isEmpty(struct queue * q){
    if(q->r==q->f){
        return 1;
    }
return 0;
}
int isFull(struct queue * q){
    if(q->r==q->size-1){
        return 1;
    }
return 0;
}
void enqueue(struct queue *q,int data)
{
    if(isFull(q))
    printf("\nQueue is full");

    else{
        q->r++;
        q->arr[q->r] = data;
    }
}

int dequeue(struct queue* q)
{
    int a;
    if(isEmpty(q))
    printf("\nEmpty");
    else{
        q->f++;
        a= q->arr[q->f];
    }
    return a;
}
int adj_matrix[10][10]={ {0,2,0,0,0,4},
    {2,0,8,0,0,3},
    {0,8,0,6,1,0},
    {0,0,6,0,12,0},
    {0,0,1,12,0,4},
    {4,3,0,0,0,4}};
void BFS(int start_vertex, int num_vertices , int visited[])
{
    struct queue* q=malloc(sizeof(struct queue));
    q->f=q->r=0;
    q->size=num_vertices;
    enqueue(q,start_vertex);
    visited[start_vertex]=1;
    while(!isEmpty(q))
    {
        int temp= dequeue(q);
        printf("%d ",temp);
        for(int i=0;i<num_vertices;i++)
        {
            if(adj_matrix[start_vertex][i]==1 && visited[i]!=1)
            {
                enqueue(q,i);
                visited[i]=1;
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

int main()
{
    int no_vertices=6;
    int C;
    // printf("Enter no of vertices : ");
    // scanf("%d",&no_vertices);
    int graph[no_vertices][no_vertices];
    int visited[no_vertices];
    // for(int i=0;i<no_vertices;i++)
    // visited[i]=0;
    // printf("\nEnter the Adjacency Matrix : ");
    // for(int i=0;i<no_vertices;i++)
    // {
    //     for (int j = 0; j < no_vertices; j++)
    //     {
    //         printf("\n%d & %d : ",i,j);
    //         scanf("%d",&adj_matrix[i][j]);
    //     }        
    // }
BFS(1,no_vertices,visited);
   
return 0;
}