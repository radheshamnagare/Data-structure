/*declaration of header files*/
#include<stdio.h>
#include<stdlib.h>
/*declaration of macro for memory allowcation purpose*/
#define memory (struct node *)malloc(sizeof(struct node))
/*declaration of structure of node*/
struct node{
 int d;
 struct node *next;
};
/*init() initilize first list pointer to null*/
void init(struct node **head){
	*head = NULL;
}
/*newNode() create structure of node*/
struct node * newNode(int d){
	struct node *newnode;
   newnode = memory;
   newnode->next = NULL;
   newnode->d = d;
}
/*create_list() create circular list*/
struct node * create_list(struct node *head,int n){
int i,d;
struct node *temp;
   for(i=1;i<=n;i++){
   	printf("\nEnter the node data :");
   	scanf("%d",&d);
   	   if(head == NULL){
         head = temp = newNode(d);
         temp->next = head;
   	   }
   	   else
   	   {
         temp->next = newNode(d);
         temp = temp->next;
         temp->next = head;
   	   }
   }
	return head;
}
/*last_node() return last node in list*/
struct node *last_node(struct node *head){
  struct node *t;
    if(head == NULL)
      return NULL;
    for(t=head;t->next!=head && t->next!=NULL;t=t->next);
  
  return t;
}
/*isnode() find same node in two particular list*/
int isnode(struct node *head1,struct node *N){
  struct node *t = head1;
  
  do{
       if(t->d == N->d)
        return 0;
       t=t->next;
  }while(t!=head1);

return 1;
}
/*display_list() display created circular list*/
void disp_list(struct node *head){
  struct node *t = head;
  do{
     printf("%d ",t->d);
     t = t->next;
  }while(t!=head);
}
/*sublist() create small sublist*/
struct node * sublist(struct node *H,int d){
  struct node *tmp;
      if(H==NULL){
        H=tmp=newNode(d);
      }
      else
      {
        for(tmp=H;tmp->next!=NULL;tmp=tmp->next);
          tmp->next = newNode(d);
      }
      
   return H;  
}
/*marge_list() marge two list*/
void marge_list(struct node *head1,struct node *head2){

   struct node *t1,*t2,*H,*p;
   t1 = last_node(head1);
   t2 = head2;
   init(&H);
      do{
         
         if(isnode(head1,t2)){
          H = sublist(H,t2->d);
         }
         t2 = t2->next;
      }while(t2!=head2);
      
      t1=last_node(H);
      t2=last_node(head1);
      t2->next = H;
      t1->next = head1;
      disp_list(head1);
}
/*main() starting execution of programm*/
int main(int argc, char const *argv[])
{
	int lm1,lm2,ch;
	struct node *head1,*head2,*t;
	system("clear");

  do{
     
     printf("\n1-create list\n2-display list\n3-marge list");
     printf("\nEnter the choise:");
     scanf("%d",&ch);
     switch(ch){
     case 1:init(&head1);
            init(&head2);
            printf("\nEnter the 1st list size :");
            scanf("%d",&lm1);
            head1 = create_list(head1,lm1);
            printf("\nEnter the 2nd list size :");
            scanf("%d",&lm2);
            head2 = create_list(head2,lm2);
            break;

     case 2:printf("\n\nDisplay lists\n");
            printf("\n----------------------------------\n");
            printf("list 1: ");
            disp_list(head1);
            printf("\nlist 2: ");
            disp_list(head2);
            printf("\n");
            break;

     case 3:printf("\nMerge list:");
            marge_list(head1,head2);
            printf("\n");
            break;
    }
  }while(ch<4);
     
	return 0;
}