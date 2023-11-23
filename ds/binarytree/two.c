#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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


struct node* preorder(struct node*root)
{
  if(root==NULL)
  	return NULL;
  
  	printf("-> %d",root->data);
  	preorder(root->left);
  	preorder(root->right);
  
}
bool areEqual(struct node* root1, struct node* root2) {
    // If both trees are empty, they are equal
    if (root1 == NULL && root2 == NULL) {
        return true;
    }
    
    // If one tree is empty and the other is not, they are not equal
    if (root1 == NULL || root2 == NULL) {
        return false;
    }

    // Check if the current nodes have the same data
    if (root1->data != root2->data) {
        return false;
    }

    return areEqual(root1->left, root2->left) && areEqual(root1->right, root2->right);


}


int main()
{
	printf("\nelements of 1st binary tree\n");
	struct node*root;
	root=create();
	printf("\nthe 1st preorder is:\n");
	
	preorder(root);
	printf("\nelements of 2nd binary tree\n");
    struct node*root1;
	root1=create(root);
	printf("\nthe 2nd preorder is:\n");
	preorder(root1);

	if (areEqual(root, root1)) {
        printf("\nThe two binary trees are equal.\n");
    } else {
        printf("\nThe two binary trees are not equal.\n");
    }

	
	return 0;

}