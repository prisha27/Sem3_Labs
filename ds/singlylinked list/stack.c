#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node*next;
};
struct node*top=NULL;

void push(int x)
{
	struct node*nn;
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=x;
    nn->next=top;
    top=nn;
    
}

void pop()
{
	struct node*temp=top;
	
		printf("element popped: %d",top->data);
		top = top->next;
		free(temp);

	
}

void display()

{
	struct node* temp=top;
	while(temp!=NULL)
	{

		printf(" element pushed : %d \n",temp->data);
		
		temp=temp->next;
	}

}

int main()
{
	
	int ch=1,pos;
	
	do{
	printf("enter your choice::\n 1.push elements\n 2.display stack\n 3.pop element\n  0. exit\n");
	  scanf("%d",&ch);
      	
	if(ch==1)
	{
		printf("enter element to add\n");
		scanf("%d",&pos);
		push(pos);
}

if (ch==2)
	display();
if(ch==3)
	pop();
}while(ch!=0);
}