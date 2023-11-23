#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
   char* data;
   struct node*next;
};
void display(struct node*head)
{
   struct node*temp=head;
   while(temp!=NULL)
   {
      printf("element : %s \n",temp->data);
      temp=temp->next;
   }
}

void reverse(struct node**head)

{
   struct node*prev=NULL;
   struct node*curr=*head;
   struct node*nextnode=NULL;

   while(curr!=NULL)
   {
      nextnode=curr->next;
      curr->next=prev;
      prev=curr;
      curr=nextnode;
   }
   *head=prev;
   printf("successfully reversed\n");
   display(*head);
}
int main()
{
   struct node*head,*nn,*temp;
   head=NULL;
   int ch;
   do{
      printf("enter your choice::\n 1.Add elements\n 2.display the list\n 3.reverse\n 0. exit\n");
     scanf("%d",&ch);
      if (ch==1)
      {
      
      nn=(struct node*)malloc(sizeof(struct node));

      nn->data=(char*)malloc(100*sizeof(char));
      printf("enter data --- ");
      scanf("%s", nn->data);
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
      reverse(&head);
}while(ch!=0);
}