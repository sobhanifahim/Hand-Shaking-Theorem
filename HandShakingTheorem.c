#include<stdio.h>
#include<conio.h>
#include<time.h>
#define max 5000

int n=2000,adj[max][max];
void main()
{
    int i,j,deg,degd,sum_deg=0,edge=0;
    double executionTime;
    printf("Adjacency Matrix is :\n");
    clock_t startTime=clock();
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            adj[i][j]=rand()%2;
            adj[j][i]=adj[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        deg=0;
        degd=0;
        for(j=0;j<n;j++)
        {
            if(adj[i][j]==1)
            {
                deg++;
            }
            if(i==j&&adj[i][j]==1)
            {
                degd++;
            }
            if(adj[i][j]==1&&i>=j)
            {
                edge++;
            }
        }
         sum_deg=sum_deg+(deg+degd);
    }
    printf("Degree=%d\n",sum_deg);
    printf("Edge=%d\n",edge);
    if(sum_deg==2*edge)
    {
        printf("HAND SHAKING THEORY PROVED\n");
    }
    else
    {
        printf("SOMETHING WRONG\n");
    }
    clock_t endTime=clock();
    executionTime=((double)(endTime-startTime)/CLOCKS_PER_SEC);
    printf("execution time=%lf s\n",executionTime);
    getch();
}
