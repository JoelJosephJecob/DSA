#include<stdio.h>
void towers(int,char,char,char);
int main()
{
 int n;
 printf("enter the number of disks:\n");
 scanf("%d",&n);
 towers(n,'S','A','D');
 return 0;
} 
void towers(int n,char S, char A, char D)
{
 if(n==1)
 {
  printf("\nmove disk 1 from peg %c to peg %c\n",S,D);
  return;
 }
 towers(n-1,S,D,A);
 printf("\nmove disk %d from peg %c to peg %c\n",n,S,D);
 towers(n-1,A,S,D);
}  
