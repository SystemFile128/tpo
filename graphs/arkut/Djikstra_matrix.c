#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 999
#define m 6
int Graph[m][m] = { {0,2,0,0,0,4},
    {2,0,8,0,0,3},
    {0,8,0,6,1,0},
    {0,0,6,0,12,0},
    {0,0,1,12,0,4},
    {4,3,0,0,0,4}}; 
void Djikstra(int start, int n)
{
    int cost[n][n], visited[n], distance[n], pred[n];
    int count,nextnode,min_dist;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(Graph[i][j]==0)
            cost[i][j]=MAX;
            else
            cost[i][j]=Graph[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        distance[i]=cost[start][i];
        pred[i]=start;
        visited[i]=0;
    }

    distance[start]=0;
    visited[start]=1;
    count =0;
    while(count<n-1)
    {
        min_dist=MAX;
        for(int i=0;i<n;i++)
        {
            if(distance[i]<min_dist && !visited[i])
            {
                min_dist=distance[i];
                nextnode=i;
            }
        }

        visited[nextnode]=1;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                if(min_dist + cost[nextnode][i] < distance[i])
                {
                    distance[i]=min_dist + cost[nextnode][i];
                    pred[i]=nextnode;
                }
            }
        }
        count++;
    }


    // Printing the distance
  for (int i = 0; i < n; i++)
    if (i != start) {
      printf("\nDistance from source to %d: %d", i, distance[i]);
    }
}

int main()
{
int start_node=0;
int no_vertices=6;

Djikstra(start_node,no_vertices);
    return 0;
}