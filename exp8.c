#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
 char ssn[15],name[20],dept[5],designation[10];
 int salary;
 long long int phno;
 struct node*left;
 struct node*right;
}*first=NULL;
struct node *last,*temp1,*temp2;

void create(char s[15],char n[20],char dpt[5],char des[10],int sal,long long int p)
{
 temp1=(struct node*)malloc(1*sizeof(struct node));
 strcpy(temp1->ssn,s);
 strcpy(temp1->name,n);
 strcpy(temp1->dept,dpt);
 strcpy(temp1->designation,des);
 temp1->salary=sal;
 temp1->phno=p;
 temp1->left=NULL;
 temp1->right=NULL;
 if(first==NULL)
 {
  first=last=temp1;
 }
 else
 {
  last->right=temp1;
  temp1->right=NULL;
  temp1->left=last;
  last=temp1;
 }
}
void display()
{
 int count=0;
 temp1=first;
 if(first==NULL)
 {
  printf("empty lsit\n");
  return;
 }
 printf("employee details.......\n");
 while(temp1!=NULL)
 {
  printf("SSN:%s\n NAME:%s\nDEPT:%s\nDESIGN:%s\nSALARY:%d\n PHN:%lld\n",temp1->ssn,temp1->name,temp1->dept,temp1->designation,temp1->salary,temp1->phno);
 
  temp1=temp1->right;
  count++;
 }
 printf("number of nodes=%d\n",count); 
}    
void ins_beg(char s[15],char n[20],char dpt[5],char des[10],int sal,long long int p)
{
 temp1=(struct node*)malloc(1*sizeof(struct node));
 strcpy(temp1->ssn,s);
 strcpy(temp1->name,n);
 strcpy(temp1->dept,dpt);
 strcpy(temp1->designation,des);
 temp1->salary=sal;
 temp1->phno=p;
 first->left=temp1;
 first=temp1;
 temp1->left=NULL;  
 
}
void ins_end(char s[15],char n[20],char dpt[5],char des[10],int sal,long long int p)
{
 temp1=(struct node*)malloc(1*sizeof(struct node));
 strcpy(temp1->ssn,s);
 strcpy(temp1->name,n);
 strcpy(temp1->dept,dpt);
 strcpy(temp1->designation,des);
 temp1->salary=sal;
 temp1->phno=p;
 last->right=temp1;
 temp1->left=NULL;  
 temp1->right=NULL;  
 last=temp1;
} 
void del_beg()
{
 if(first==NULL)
 {
  printf("list is empty \n");
 }
 else
 {
  temp1=first->right;
  if(temp1!=NULL)
  {
   temp1->left=NULL;
   printf("deleted node is:\n");
  
   printf("SSN:%s\n",first->ssn);
   
   free(first);
   first=temp1;
  }
  else 
  {
   printf("deleted nodeis :\n");
   
   printf("SSN:%s\n",first->ssn);
   
   free(first);
   first=NULL;
  }
 }
}
void del_end()
{
 if(first==NULL)
 {
  printf("list is empty \n");
 }
 else
 {
  temp1=last;
  if(first==last)
  {   
   printf("deleted node is:\n");
   
   printf("SSN:%s\n",last->ssn);
   
   first=last=NULL;
   free(temp1);
  }
  else 
  {
   printf("deleted nodeis :\n");
  
   printf("SSN:%s\n",last->ssn);
   
   last=temp1->left;
   last->right=NULL;
   free(temp1);
  }
 }
}
void main()
{
 int choice;
 char s[15],n[20],dpt[5],des[10];
 int sal;
 long long int p;
 printf("1.create\n2.display\n3.insert at beginning\n4.insert at end\n5.delete at beginning\n6.delete at end\n7.exit\n");
 while(1)
 {
  printf("\n enter your choice\n");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:printf("enter the required data(Empno,Name,Dept,Design,sal,phno");
          scanf("%s%s%s%s%d%lld",s,n,dpt,des,&sal,&p);
          create(s,n,dpt,des,sal,p);
          break;
   case 2:display();
          break;
   case 3:printf("enter the required data(Empno,Name,Dept,Design,sal,phno");
          scanf("%s%s%s%s%d%lld",s,n,dpt,des,&sal,&p);
          ins_beg(s,n,dpt,des,sal,p);
          break;  
   case 4:printf("enter the required data(Empno,Name,Dept,Design,sal,phno");
          scanf("%s%s%s%s%d%lld",s,n,dpt,des,&sal,&p);
          ins_end(s,n,dpt,des,sal,p);
          break;         
   case 5:del_beg();
          break;
   case 6:del_end();
          break;
   case 7:exit(0);
  }
 }                                    
}   












