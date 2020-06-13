/*required header files*/
#include<stdio.h>
#include<stdlib.h>
/*declaration of macro for memory allowcation purpose*/
#define memory (struct node*)malloc(sizeof(struct node))
/*declaration of structure of node*/
struct node{
 char d;	
 struct node *next;
};
/*init() initilize of first list pointer to null*/
void init(struct node **head){
	*head = NULL;
}
/*newNode() return structure of node*/
struct node *newNode(char d){
  struct node *newnode;

  newnode = memory;
  newnode->next = NULL;
  newnode->d = d;
 
 return newnode; 
}
/*create_list() create list*/
struct node *create_list(struct node *head,int n){
  int i;
  char d;
  struct node *temp;

   for(i=1;i<=n;i++){
   	printf("\nEnter the element :");
   	scanf(" %c",&d);
   	 if(head == NULL)
         head = temp = newNode(d);
      else
      {
      	temp -> next = newNode(d);
      	temp = temp -> next;
      }    
   }
 return head;      
}
/*order_search() find occurance of element in list and return count*/
int order_search(struct node *N,char d){
 int cnt = 1;
 struct node *p;
    if(N == NULL)
    	return cnt;
    else
    {
    	for(p=N;p!=NULL;p=p->next)
    		if(p->d == d && p->d!=-1){
    		 cnt ++;
    		 p->d = -1;
    		}
    }
   return cnt; 
}
/*start execution of program*/
int main(int argc, char const *argv[])
{
	int n;
    struct node *head,*p;
     system("clear");
    init(&head);
    printf("\nEnter the size of list :");
    scanf("%d",&n);
    head = create_list(head,n);
     printf("\noccurance of each element of list :\n");
     printf("element\tcount");
     printf("\n------------------------------------------");
     for(p=head;p!=NULL;p=p->next)
     {
     	if(p->d!=EOF)
     	printf("\n%c\t%d",p->d,order_search(p->next,p->d));
     }
     	
	return 0;
}
