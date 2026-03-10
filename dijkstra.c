#include <stdio.h>
#define N 5
#define INF 999

int main()
{
    int cost[N][N] = {
        {0,2,999,1,999},
        {2,0,3,2,999},
        {999,3,0,999,1},
        {1,2,999,0,4},
        {999,999,1,4,0}
    };

    int dist[N], visited[N]={0};
    int i,j,min,u;

    // Initialize distance
    for(i=0;i<N;i++)
        dist[i]=cost[0][i];

    visited[0]=1;

    for(i=1;i<N;i++)
    {
        min=INF;

        for(j=0;j<N;j++)
        {
            if(!visited[j] && dist[j]<min)
            {
                min=dist[j];
                u=j;
            }
        }

        visited[u]=1;

        for(j=0;j<N;j++)
        {
            if(!visited[j] && dist[u]+cost[u][j] < dist[j])
                dist[j]=dist[u]+cost[u][j];
        }
    }

    printf("Shortest distances from node 0:\n");
    for(i=0;i<N;i++)
        printf("0 -> %d = %d\n",i,dist[i]);

    return 0;
}