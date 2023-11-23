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

    {
      struct node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
       temp->next = nn;
    }


}



void display(struct node*head)
{
	while(head!=NULL)
	{

		printf("-> %d ",head->data);
		
		head=head->next;
	}

}

struct node* mergelist(struct node*l1,struct node*l2)
{
	struct node*result;
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

int main()
{
	struct node*classa=NULL;
	struct node*classb=NULL;
	
	int a,b,i;

	printf("enter size of class A\n");
	scanf("%d",&a);
    printf("enter size of class B\n");
	scanf("%d",&b);

      printf("enter class A elements\n");
      for(i=0;i<a;i++)
      {
        int ele;
        scanf("%d",&ele);
        insert(&classa,ele);

	}

	 printf("enter class B elements\n");
      for(i=0;i<b;i++)
      {
        int ele;
        scanf("%d",&ele);
        insert(&classb,ele);

	}
	
     printf("line of class A : \n");
     display(classa);
     printf("\n line of class B : \n");
     display(classb);\

     printf("\nMerged array");
     struct node*r=mergelist(classa,classb);

     display(r);
 



	/* code */
	return 0;
}