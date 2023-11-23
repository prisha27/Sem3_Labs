#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node*left;
	struct node*right;

};

struct node*create()

{
	 struct node* stack[100];
	struct node*root=NULL;
	struct node*curr;
	struct node*temp;
    int top=-1;
    struct node*nn;int x;
    nn=(struct node*)malloc(sizeof(struct node));
    printf("enter data");
    scanf("%d",&x);

    nn->data=x;
    nn->left=nn->right=NULL;

    stack[++top]=nn;

    while(top!=-1)
    {
    	curr=stack[top--];

    	printf("Enter the left child of %d (-1 for no child): ", curr->data);
        scanf("%d", &x);

        if (x != -1) {

    	temp = (struct node *)malloc(sizeof(struct node));
            temp->data = x;
            temp->left = temp->right = NULL;

        curr->left=temp;
        stack[++top]=temp;
    }
    printf("Enter the right child of %d (-1 for no child): ", curr->data);
        scanf("%d", &x);

        if (x != -1) {

    	temp = (struct node *)malloc(sizeof(struct node));
            temp->data = x;
            temp->left = temp->right = NULL;

        curr->right=temp;
        stack[++top]=temp;
    }
}
return(root);
}

int main()
{
	struct node *root = create();
	return 0;
}



