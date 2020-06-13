
/*declaration of headre files*/
#include<stdio.h>
#include<stdlib.h>
/*declaration of structure of node*/
struct Node
{
  int data;
  struct Node *next;
};
/*printL() list*/
void printL(struct Node* n)
{
  if(n==NULL)
    printf("\nLinked List is Empty\n");
  while(n!=NULL)
  {
    printf("%d\t",n->data);
    n=n->next;
  }
  printf("\n");
}
/*append() insert node in list*/
void append(struct Node** head_ref,int new_data)
{
  struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
  new_node->data=new_data;
  new_node->next=NULL;

  struct Node *last=*head_ref;
  if(*head_ref==NULL)
  {
    *head_ref=new_node;
    return;
  }
  while((last->next)!=NULL)
    last=last->next;
  last->next=new_node;
  return;
}
/*deleten() delete left side node have greater value*/
void deleten(struct Node **head)
{
  if(*head==NULL)
  {
    printf("\nLinked List Empty\n");
    return;
  }
  struct Node *c,*n;
  n=NULL;
  c=*head;
  while(c->next!=NULL)
  {
    n=c->next;
    if(c->data>n->data)
    {
      c->next=n->next;
      free(n);
    }
    else
      c=c->next;
    if(c==NULL)
    {
      printf("\nReached end of Linked List\n");
      break;
    }
  }
}
/*start execution of program*/
void main()
{
  struct Node* head=NULL;
  int ch,d;
  do
  {
    printf("\nEnter the Choice from refrence\n\t1.Insert\n\t2.Print\n\t3.Delete\n\t0.Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
        printf("\nEnter the data to be inserted\t");
        scanf("%d",&d);
        append(&head,d);
        break;
      case 2:
        printL(head);
        break;
      case 3:
        printf("\nDelteing node which have greater value on their left side\n");
        deleten(&head);
        break;
      case 0:
        printf("\nEXITING...From this loop of entries\n");
        break;
      default:
        printf("\nInvalid INPUT");
    }
  }while(ch!=0);
}

