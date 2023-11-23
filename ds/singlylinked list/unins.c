#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node*next;
};
void insert(struct node**head,int data)
{
	struct node*nn;
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=data;
    nn->next=NULL;

    
    if(*head==NULL)
    {
    	*head=nn;
    }
    else

    {struct node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
       temp->next = nn;
    }
  }


struct node*unionlist(struct node*l1,struct node*l2)
{
	struct node*result=NULL;
	while(l1!=NULL)
	{
		insert(&result,l1->data);
		l1=l1->next;
	}

	while(l2!=NULL)
	{
		insert(&result,l2->data);
		l2=l2->next;
	}

	return result;
}

struct node*interlist(struct node*l1,struct node*l2)
{
	struct node*result=NULL;
	while(l1!=NULL)
	{
		struct node*temp=l2;
		while(temp!=NULL)
		{
			if(l1->data==temp->data)
				{ insert(&result,l1->data);
			break;
		}
		temp=temp->next;

		}
		l1=l1->next;
	}

	return(result);
}



void display(struct node*head)
{
	while(head!=NULL)

	{

		printf("-> %d ",head->data);
		
		head=head->next;
	}

}
int main()
{
	struct node*lis1=NULL;
	struct node*lis2=NULL;
	
	int a,b,i;

	printf("enter size of A\n");
	scanf("%d",&a);
    printf("enter size of B\n");
	scanf("%d",&b);

      printf("enter elements list1\n");
      for(i=0;i<a;i++)
      {
        int ele;
        scanf("%d",&ele);
        insert(&lis1,ele);
      }

      printf("enter elements list2\n");
      for(i=0;i<b;i++)
      {
        int ele;
        scanf("%d",&ele);
        insert(&lis2,ele);

	}
   printf("\nunion\n");
	struct node*u=unionlist(lis1,lis2);
  display(u);
  printf("\nintersection\n");
  struct node*i1=interlist(lis1,lis2);
  display(i1);
	//struct node*ins=union(lis1,lis2);
	//display(ins);

}