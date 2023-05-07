#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 999
struct gnode{
    int vertice;
    int weight;
    struct gnode *next;
};

struct Adj_Lists
{
    struct gnode *head;
};

struct Graph{
    int num_vertices;
    struct Adj_Lists *adj_list;
};

struct gnode *creategnode(int data,int weight)
{
    struct gnode *newnode = malloc(sizeof(struct gnode));
    newnode->vertice=data;
    newnode->weight=weight;
    newnode->next=NULL;
    return newnode;
}

struct Graph *creategraph(int size)
{
    struct Graph *g=(struct Graph*)malloc(sizeof(struct Graph));
    g->num_vertices=size;
    g->adj_list=(struct Adj_Lists *)malloc(g->num_vertices * sizeof(struct Adj_Lists));
    for(int i=0;i<g->num_vertices;i++)
    {
        g->adj_list[i].head = NULL;
    }
    return g;
}
void addEdge(struct Graph *g,int src,int dest, int weight)
{
    struct gnode *newnode=creategnode(dest,weight);
    newnode->next= g->adj_list[src].head;
    g->adj_list[src].head=newnode;

    struct gnode *node=creategnode(src,weight);
    node->next=g->adj_list[dest].head;
    g->adj_list[dest].head=node;
}

int Minkey(int Key[],bool MSTSet[],int n)
{
    int min,minIndex;
    min=MAX;
    for(int i=0;i<n;i++)
    {
        if(MSTSet[i]==false && Key[i]<min)
        {
            min = Key[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void displayMST(int parent[], int weight[], int v){
    for(int i = 0; i < v; i++){
        printf("\n%d = Parent: %d & Weight: %d", i, parent[i], weight[i]);
    }
}


void Prim(struct Graph * g)
{
    int n=g->num_vertices;
    int Parent[n];
    bool MST[n];
    int Key[n];
    struct gnode *p;
    for(int i=0;i<n;i++)
    {
        Key[i]=999;
        MST[i]=false;
    }
    Parent[0]=-1;
    Key[0]=0;
    for(int i=0;i<n;i++)
    {
        int u = Minkey(Key,MST,n);
        MST[u]=true;
        p =g->adj_list[u].head;
        printf("%d\n",u);
        while(p!=NULL)
        {
            if(MST[p->vertice] == false && p->weight<Key[p->vertice])
            {
                Key[p->vertice]=p->weight;
                Parent[p->vertice]=u;
            }
            p=p->next;
        }
    }
        displayMST(Parent,Key, n);
}

void printgraph(struct Graph *g)
{
    printf("\nAdjacency List : ");
    for(int i=0;i<g->num_vertices;i++)
    {
        struct gnode *temp = g->adj_list[i].head;
        printf("\nVertex %d : ",i);
        while(temp!=NULL)
        {
            printf("%d = %d ,",temp->vertice,temp->weight);
            temp=temp->next;
        }
    }
}
int main()
{
    int no_vertices=6;
    // printf("Enter total no. of vertices : ");
    // scanf("%d",&no_vertices);
    int src,dest,weight;
    struct Graph * graph =creategraph(no_vertices);
//      printf("Enter the edges of the graph in the format <SRC> <DESTINATION> <WEIGHT> (enter -1 to exit):\n");
//   while(1){ 
//     scanf("%d %d %d",&src , &dest , &weight);
//     if(src == -1 &&  dest == -1 && weight == -1 )
//       break;
//     addEdge(graph,src,dest,weight);
//   }
addEdge(graph, 0, 1, 2);
addEdge(graph, 0, 5, 4);
addEdge(graph, 1, 5 ,3);
addEdge(graph, 1, 2, 8);
addEdge(graph, 2, 4, 1);
addEdge(graph, 5, 4, 2);
addEdge(graph, 2, 3, 6);
addEdge(graph, 3, 4, 12);
// printgraph(graph);
Prim(graph);
return 0;
}