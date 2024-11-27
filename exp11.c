#include<stdio.h>
#include<stdlib.h>
int a[20][20],q[20],visited[20],reach[10],n,i,j,f=0,r=-1,count=0,v,choice;
void DFS_connectivity(int v)
{
  reach[v]=1;
  for(i=1;i<=n;i++)
  {
    if(a[v][i]&&!reach[i])
    {
       printf("\n %d->%d",v,i);
       count++;
       DFS_connectivity(i);
     
    }  
  }  
}
void main()
{
  printf("\nenter the  number of vertices:\n");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  reach[i]=0;
  printf("\n enter graph data in matrix form:\n");
  for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
  scanf("%d",&a[i][j]);
  printf("DFS_connectivity check\n");
  DFS_connectivity(1);
  if(count==n-1)
  printf("\n graph is connected");
  else
  printf("\n graph is not connected");
 } 
  
