#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void deletefront(struct node**head)
{
	struct node*temp=*head;
	*head=(*head)->next;
	free(temp);
}

void deleteend(struct node**head)
{
	struct node *temp=*head;
	struct node *curr=temp;
	while(temp->next!=NULL)//element to delete while(temp->next->next!=NULL) befor that node element will  be deleted
	{
		temp=temp->next;
	}
	curr=temp->next;
	temp->next=NULL;
	free(curr);



}

void deleteafter(struct node*head,int pos)
{
	struct node *temp=head;
    struct node *curr=NULL;
	while(temp->data!=pos)
	{
		curr=temp;
		temp=temp->next;
	}
    curr->next=temp->next;
    
    free(temp);

}

void display(struct node*head)
{
	struct node*temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("element : %d\n",temp->data);
		temp=temp->next;
	}
}
void length(struct node*head)
{
	struct node*temp=head;
	int i=0;
	while(temp!=NULL)
	{
		i++;
		temp=temp->next;
	}
	printf("length of the link list is %d \n:",i);
}


int main()
{
	struct node *head,*nn,*temp;
	head=NULL;
	int ch,pos;
    do{
      printf("enter your choice::\n 1.Add elements\n 2.display the list\n 3.delete infront\n 4.delete at end\n 5.delete between\n 6. length of list\n 0. exit\n");
	  scanf("%d",&ch);
    	if (ch==1)
    	{
      
      nn=(struct node*)malloc(sizeof(struct node));
      printf("enter data --- ");
      scanf("%d", &nn->data);
      nn->next=NULL;
      if(head==NULL)
      {
      	head=temp=nn;
      }
      else
      {
      	temp->next=nn;
      	temp=nn;
      }


    	}
    	else if(ch==2)
    		display(head);
    	else if(ch==3)
    		deletefront(&head);
    	else if(ch==4)
    		deleteend(&head);
    	else if(ch==5)
    	{
    		printf("Enter the data of the node you want to delete: ");
            scanf("%d", &pos);
            deleteafter(head,pos);

    	}
    	else if(ch==6)
    		length(head);
    } while(ch!=0);
}