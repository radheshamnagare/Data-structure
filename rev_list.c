/*required header files */
#include<stdio.h>
#include<stdlib.h>

/*declaration of macro for dymanic memory allocation*/
#define memory (struct node *)malloc(sizeof(struct node))

/*declaration of structure of the list node*/
struct node{
  int data;
  struct node *next;
};
/*init() initilize the first list pointer to null*/
void init(struct node **head){
	*head = NULL;
}
/*newNode() return the node type of structure pointer*/
struct node * newNode(int d){
	struct node *newnode;

	newnode = memory;
	newnode->data = d;
    newnode->next = NULL;

   return newnode; 
}
/*create_list() craete n node of the list*/
struct node * create_list(struct node *head,int n){
    int i;
    struct node *newnode,*temp;
    for(i=1;i<=n;i++){
       if(head == NULL)
     	 head = temp =newNode(i);
      else
      {
        temp -> next = newNode(i);
        temp = temp -> next;  
      }		
    }
     
	return head;
}
/*last_node() return the last pointer of list with help of size*/
struct node * last_node(struct node *N,int n){
   int i;
   struct node *p;
   for(i=1,p=N;p->next!=NULL&&i<n;i++,p=p->next);

   	return p;
}
/*display_list() display the original created list*/
void display_list(struct node *N){
	struct node *p;
	for(p=N;p!=NULL;p=p->next)
		printf("%d ",p->data);
}
/*rev_list() prints reverse list given group size*/
void rev_list(struct node *H,int n){

	if(n<=0 || H==NULL)
		return;
	
	rev_list(H->next,--n);
	printf("%d ",H->data);
}
/*starts the execution of programms*/
int main(int argc, char const *argv[])
{
	int lim,size,lp,i;
	struct node *head,*N,*H;
	system("clear");
	   
	   printf("\nEnter the list size :");
	   scanf("%d",&lim);
	   printf("\nEnter the size of the group :");
	   scanf("%d",&size);

	   init(&head);
       lp = (lim/size);
        if(lim%size !=0)
        	++lp;
       i = 1;
       head = create_list(head,lim);
       N = head;
       printf("\nOriginal list :\n");
       display_list(head);
       printf("\nNo of groups \n");
       printf("--------------------------------\n");
       
       while(lp>0)
       {
       	printf("\n(%d) : ",i++);
       	rev_list(N,size);	
       	N = last_node(N,size)->next;
       	lp--;
       }
       	  
	return 0;
}