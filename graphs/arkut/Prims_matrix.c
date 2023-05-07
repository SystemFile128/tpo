#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 999
 
    int Adj_matrix[6][6]={ {0,2,0,0,0,4},
    {2,0,8,0,0,3},
    {0,8,0,6,1,0},
    {0,0,6,0,12,0},
    {0,0,1,12,0,4},
    {4,3,0,0,0,4}};
int MinKey(int key[],bool MST[],int V)
{
    int min=MAX;
    int minindex;
    for(int i=0;i<V;i++)
    {
        if(MST[i]==false && key[i]<min)
        {
            min=key[i];
            minindex=i;
        }
    }
    return minindex;
}
void Prim(int n)
{
   
    int Parent[n];
    int Key[n];
    bool MST[n];
    for(int i=0;i<n;i++)
    {
        Key[i]=MAX;
        MST[i]=false;
    }
    Parent[0]=0;
    Key[0]=0;
    for(int i=0;i<n;i++)
    {
        int u = MinKey(Key,MST,n);
        MST[u]=true;
        printf("\n%d",u);
        for(int i=0;i<n;i++)
        {
            if(Adj_matrix[u][i] && MST[i]==false && Adj_matrix[u][i] < Key[i])
            {
                Parent[i]=u;
                Key[i]=Adj_matrix[u][i];
            }
        }
    }
 }

int main()
{
   int no_vertices=6;
    // printf("Enter total no. of vertices : ");
    // scanf("%d",&no_vertices);
    // // Adj_matrix[no_vertices][no_vertices];
    // int value;
    // printf("\nEnter the Adjacency matrix : ");
    // for(int i=0;i<no_vertices;i++)
    // {
    //     for(int j=0;j<no_vertices;j++)
    //     {
    //         printf("\n%d : %d = ",i,j);
    //         scanf("%d",&Adj_matrix[i][j]);
    //     }
    // }

Prim(no_vertices);
    return 0;
}