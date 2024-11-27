#include<stdio.h>
#include<stdlib.h>
struct bst
{
   int data;
   struct bst*left;
   struct bst*right;
};
typedef struct bst NODE;
NODE*node;
NODE*creatree(NODE*node,int data)
{
  if(node==NULL)
  {
    NODE*temp;
    temp=(NODE*)malloc(sizeof(NODE));
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
  }
  if(data<(node->data))
  {
    node->left=creatree(node->left,data);
  }
  else if(data>node->data)
  {
    node->right=creatree(node->right,data);
  }
  return node;
}
void inorder(NODE*node)
{
  if(node!=NULL)
  {
   inorder(node->left);
   printf("%d\t",node->data);
   inorder(node->right);
  }
}
void preorder(NODE*node)
{
  if(node!=NULL)
  {
   printf("%d\t",node->data);
   preorder(node->left);
   preorder(node->right);
  }
}
void postorder(NODE*node)
{
  if(node!=NULL)
  {
   postorder(node->left);
   postorder(node->right);
   printf("%d\t",node->data);
  }
}      
NODE*search(NODE*node,int data)
{
  if(node==NULL)
  printf("\n element not found");
  else if(data<node->data)
  {
    node->left=search(node->left,data);
  } 
  else if(data>node->data)
  {
    node->right=search(node->right,data);
  }
  else
  printf("\n element found is :%d",node->data);
  return node;
}
void main()
{
 int data,ch,i,n;
 NODE*root=NULL;
 printf("\n1.bst insertion 2.inorder 3.preorder 4.postorder  5.search element 6.exit\n");
 while(1)
 {
   printf("\n enter your choice\n");
   scanf("%d",&ch);
   switch(ch)
   {
     case 1:printf("\n enter n value:\n");
            scanf("%d",&n);
            printf("\n enter the values to create bst\n");
            for(i=0;i<n;i++)
            {
              scanf("%d",&data);
              root=creatree(root,data);
            }
            break;
     case 2:printf("\n inorder traversal:\n");
            inorder(root);
            break;
     case 3:printf("\n preorder traversal:\n");
            preorder(root);
            break;
     case 4:printf("\n postorder traversal:\n");
            postorder(root);
            break;
     case 5:printf("\n enter the element to search:\n");
            scanf("%d",&data);
            root=search(root,data);
            break;
     case 6:exit(0);
     default:printf("\n wrong option");
             break;
    }
}
}                                               
         



  
