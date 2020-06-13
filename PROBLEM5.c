/*required header files*/
#include<stdio.h>
#include<stdlib.h>

/*declaration & initilization of counter variable*/
int cnt = 0;
/*declaration of macro for memory allowcation*/
#define memory (struct node *)malloc(sizeof(struct node))
/*declaration node of structure */
struct node{
  int d;
  struct node *left,*rigth;
};
/*init() initilize first pointer structure of node to NULL*/
void init(struct node **root){
	*root = NULL;
}
/*newNode() return node of structure pointer*/
struct node * newNode(int d){
	struct node *newnode;
	newnode = memory;
	newnode->left = NULL;
	newnode->rigth = NULL;
	newnode->d = d;
return newnode;	
}
/*insert_node() create BST & return pointer*/
struct node * insert_node(struct node *N,int d){

      if(N == NULL)
        N = newNode(d);
      else
      {
          if(N == NULL)
          	return newNode(d);
          if(d < N->d)
           N->left = insert_node(N->left,d);
          else
          	N->rigth = insert_node(N->rigth,d);
      }

 return N;
}
/*preorder() print traversal of tree*/
void preorder(struct node *N){
	if(N == NULL)
		return;
	printf("%d ",N->d);
	preorder(N->left);
	preorder(N->rigth);
}
/*count_node() counts no of node within range*/
int count_node(struct node *N,int range){
     if(N == NULL)
     	return cnt;
     if(N->d <= range)
     	++cnt;
     count_node(N->left,range);
     count_node(N->rigth,range);

}
/*start execution of the programm*/
int main(int argc, char const *argv[])
{
	/*variable declaration*/
	int choise,nd,range;
	struct node *root;
      
      system("clear");
	  init(&root); // initilize 1st pointer of tree
	  //choises
	  do{
         
         printf("\n\t1-insert node in tree\n\t2-preorder of tree\n\t3-count nodes\n\tExit");
         printf("\n: ");
         scanf("%d",&choise);
          switch(choise){

          	case 1 :printf("\nEnter the node :");
          	        scanf("%d",&nd);  
          	        root = insert_node(root,nd);
          	        break;

          	case 2: preorder(root);
          	        break;

          	case 3: printf("\nEnter the range :");
          	        scanf("%d",&range);
          	        printf("\nNo of node in tree : %d" ,count_node(root,range));
          	        break;              

          	case 4:printf("\nExited ..."); 
          	        break;           
          }
	  } while(choise<4);

	return 0;
}