/*required header file declaration */
#include<stdio.h>
#include<stdlib.h>

int *a; //array declaration
int cnt = 0;//counter variable
/*declaration of macro for memory allowcation purpose*/
#define memory (struct node *)malloc(sizeof(struct node))
/*declaration of structure of node*/
struct node{
  int d;
  struct node *next;
  struct node *left,*right;
}*top;
/*initilization root of tree to NULL*/
void init(struct node **root){
	*root = NULL;
}
/*newNode() return structure of node pointer*/
struct node * newNode(int d){
	struct node *newnode;
	newnode = memory;
	newnode->left = NULL;
	newnode->right = NULL;
  newnode->next = NULL;
	newnode->d = d;
return newnode;	
}
/*push() push element in structure of node as stack*/
void push(struct node *N){
  struct node *t;
  if(top == NULL)
    top = N;
  else
  {
    for(t=top;t->next!=NULL;t=t->next);
     t->next = N;
  }
}
/*pop() element form structure of node as stack*/
struct node * pop()
{
  struct node *t;
  if(top == NULL)
    return NULL;
  else
  {
    t = top;
    top = top->next;
    t->next = NULL;
  }

  return t;
}
/*insert_node() creating BT and return root of tree*/
struct node * insert_node(struct node *N,int d){
struct node *t,*nd;
   
      if(N == NULL){
        N = newNode(d);
        push(N); 
      }
      else
      {
          if(top!=NULL){
            
            if(top->left!=NULL && top->right!=NULL)
              pop();

            if(top->left == NULL){
               nd = newNode(d);
               top->left = nd;
               push(nd);
            }
            else if(top->right == NULL){
               nd = newNode(d);
               top->right = nd;
               push(nd);
            }

          }
      }

 return N;
}
/*postorder() postorder traversal of tree*/
void postorder(struct node *N){
  if(N == NULL)
    return;
  postorder(N->left);
  postorder(N->right);
  printf("%d ",N->d);
}
/*delete_node() delete node within range*/
void delete_node(struct node *N,int k){

            if(N == NULL)
              return ;

            if(N->d<k)
            {
              a[cnt++] = N->d;
              a = (int *)realloc(a,sizeof(int));
            }

            delete_node(N->left,k);
            delete_node(N->right,k);

}
/*start main execution of programm*/
int main(){

  /*require declaration of variable*/
  int cho,d,k,i;
  struct node *root,*root1;
  system("clear");
  
  init(&root);//initilization root of tree
  // choises
  do{

       printf("\n\t1-insert in BT \n\t2-delete all node gt k\n\t3-postorder of tree\n\t4-exit\n:");
       scanf("%d",&cho);

       switch(cho){
           case 1: printf("\nEnter the node :");
                   scanf("%d",&d);
                   root = insert_node(root,d);
                   break;

           case 2:printf("\nEnter the k :");
                  scanf("%d",&k);
                  a = (int *)malloc(sizeof(int));
                  delete_node(root,k);
                  init(&root);
                  init(&top);
                  for(i=0;i<cnt;i++){
                    root = insert_node(root,a[i]);
                  }       
                  break;

           case 3: postorder(root);
                   break;

           case 4:printf("\nexited ...");
                  break;

       }

  }while(cho<4);

  return 0;
}
//end