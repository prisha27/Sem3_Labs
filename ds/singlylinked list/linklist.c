#include<stdio.h>
#include<stdlib.h>

struct node //creating your data type
{
	int data;
	struct node *next;
};



void display(struct node*head)
{
  struct node *temp;
  temp=head;
  while(temp!=NULL)
  {
    {   int i=1;
		printf("element %d : %d \n",i,temp->data);
		i++;
		temp=temp->next;
	}
  }

}

void addfront(struct node **head)
{
	struct node *newn;
	newn=(struct node*)malloc(sizeof(struct node));
      printf("enter data to be inserted");
      scanf("%d", &newn->data);
      newn->next=*head;
      *head=newn;
}
void addend(struct node**head)
{
	struct node*temp=*head;
	struct node*newn;
	if(temp->next!=NULL)
    	{
    		temp=temp->next;
    	}
      newn=(struct node*)malloc(sizeof(struct node));
      printf("enter data to be inserted");
      scanf("%d", &newn->data);
      temp->next=newn;
      newn->next=NULL;
     
}

	void insertAfter(struct node *head, int pos)
{
    struct node *temp = head;
    while (temp != NULL && temp->data != pos)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Node with data %d not found.\n", pos);
        return;
    }

    struct node *newn = (struct node *)malloc(sizeof(struct node));
    printf("enter data to be inserted: ");
    scanf("%d", &newn->data);
    newn->next = temp->next;
    temp->next = newn;

    
}



int main()
{
	// code 
	struct node *head,*nn,*temp, *newn;
	head=NULL;
	int ch=1,pos;
	
	do{
	printf("enter your choice::\n 1.Add elements\n 2.display the list\n 3.add infront\n 4.add at end\n 0. exit\n");
	  scanf("%d",&ch);
      	
	if(ch==1)
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
    {
    	addfront(&head);
     
    }
    else if(ch==4)
    {
    	addend(&head);
    }
    else if(ch==5)
    {
      printf("Enter the data of the node after which you want to insert: ");
            scanf("%d", &pos);
            insertAfter(head, pos);
    }
 } while(ch!=0);

	return 0;
}