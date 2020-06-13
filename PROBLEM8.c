/*required header files*/
#include<stdio.h>
#include<stdlib.h>

int cnt = 0;//declaration of counter
/*declaration of macro for memory allowcation purpose*/
#define memory (struct node *)malloc(sizeof(struct node))
/*declaration structure of node*/
struct node{
  int d;
  struct node *left,*rigth;
};
/*init() initilize first pointer of tree to NULL*/
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
/*insert_node() create BST and return 1st pointer of the tree*/
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
/*preorder() traversal of the tree*/
void preorder(struct node *N){
	if(N == NULL)
		return;
	printf("%d ",N->d);
	preorder(N->left);
	preorder(N->rigth);
}
/*print_leaf() print leaf nodes in tree*/
int print_leaf(struct node *N){
     if(N == NULL)
     	return cnt;
     if(N->left == NULL && N->rigth == NULL)
     	printf("%d ",N->d);
     print_leaf(N->left);
     print_leaf(N->rigth);

}
/*start main execution of the programm*/
int main(int argc, char const *argv[])
{
  /*require variable declaratiob*/
	int choise,nd;
	struct node *root;
      
      system("clear");
	  init(&root); // initilization of root of tree to NULL
	  //choises
	  do{
         
         printf("\n\t1-insert node in tree\n\t2-preorder of tree\n\t3-print leaf node\n\t4-Exit");
         printf("\n: ");
         scanf("%d",&choise);
          switch(choise){

          	case 1 :printf("\nEnter the node :");
          	        scanf("%d",&nd);  
          	        root = insert_node(root,nd);
          	        break;

          	case 2: preorder(root);
          	        break;

          	case 3: printf("\nleaf nodes : ");
                    print_leaf(root);
          	        break;              

          	case 4:printf("\nExited ..."); 
                   break;          
          }
	  } while(choise<4);

	return 0;
}