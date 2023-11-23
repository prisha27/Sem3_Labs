#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node*left;
	struct node*right;

};

struct node*create()
{
	struct node*nn;int x;
    nn=(struct node*)malloc(sizeof(struct node));
    printf("enter data(-1 if you dont want to enter that child)");
    scanf("%d",&x);
    nn->data=x;
    if(x==-1)
    	return NULL;
    else
    {
    	printf("enter the left child %d:",x);
    	
    	nn->left=create();
    	printf("enter the right child %d:",x);
    	
    	nn->right=create();


    }
     return nn;

}

struct node* preorder(struct node*root)
{
  if(root==NULL)
  	return NULL;
  
  	printf("-> %d",root->data);
  	preorder(root->left);
  	preorder(root->right);
  
}

void inorder(struct node*root)
{
  if(root==NULL)
  	return;
  else
  {
  	inorder(root->left);
  	printf("-> %d",root->data);
  	inorder(root->right);
  }
}

void posorder(struct node*root)
{
  if(root==0)
  	return;
  else
  {
  	posorder(root->left);
  	posorder(root->right);
  	printf("-> %d",root->data);
  	
  }
}


int main()
{
	struct node*root;
	root=create();
	printf("the preorder is:\n");
	
	preorder(root);

	printf("the inorder is:\n");
	inorder(root);
	printf("the post- order is:\n");
	posorder(root);
	
	return 0;

}