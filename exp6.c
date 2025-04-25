#include<stdio.h>
void main()
{
 float p[10],w[10],ratio[10],temp,total=0;
 int n,m,i,j;
 printf("enter the number of item:\n");
 scanf("%d",&n);
 printf("enter the maximum capcity:\n");
 scanf("%d",&m);
 printf("enter the number of profit:\n");
 for(i=0;i<n;i++)
 scanf("%f",&p[i]);
 printf("enter the number of weight:\n");
 for(i=0;i<n;i++)
 scanf("%f",&w[i]);
 for(i=0;i<n;i++)
 ratio[i]=p[i]/w[i];
 for(i=0;i<n;i++)
 for(j=i+1;j<n;j++)
 if(ratio[i]<ratio[j])
 {
  temp=ratio[j];
  ratio[j]=ratio[i];    //to swap ratio
  ratio[i]=temp;
  
  temp=w[j];
  w[j]=w[i];             //swap weight
  w[i]=temp;
  
  temp=p[j];
  p[j]=p[i];                 //swap profit
  p[i]=temp;
 } 
 printf("knapsack prb using greedy alg:\n");
 for(i=0;i<n;i++)
 {
  if(w[i]>m)break;
  else
  {
   total=total+p[i];
   m=m-w[i];
  }
 }
 if(i<n)
 {
  total=total+(ratio[i]*m);
 }
 printf("the maximum prf is %f \n",total);
}    

