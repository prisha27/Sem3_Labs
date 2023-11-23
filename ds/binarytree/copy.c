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
    printf("enter data(-1 if you dont want to enter that child)\n");
    scanf("%d",&x);
    nn->data=x;
    if(x==-1)
    	return NULL;
    else
    {
    	printf("enter the left child %d : ",x);
    	
    	nn->left=create();
    	printf("enter the right child %d : ",x);
    	
    	nn->right=create();


    }
     return nn;

}

struct node*copy1(struct node*r)
{
	

	struct node*cpy =(struct node*)malloc(sizeof(struct node));
	cpy->data = r->data;
	cpy->left=r->left;
	cpy->right=r->right;
	 return cpy;
}

struct node* preorder(struct node*root)
{
  if(root==NULL)
  	return NULL;
  
  	printf("-> %d",root->data);
  	preorder(root->left);
  	preorder(root->right);
  
}



int main()
{
	struct node*root;
	root=create();
	printf("the orignal preorder is:\n");
	
	preorder(root);
    struct node*root1;
	root1=copy1(root);
	printf("the copied preorder is:\n");
	
	preorder(root1);
	
	return 0;

}