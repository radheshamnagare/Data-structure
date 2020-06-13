/*require header files*/
#include<stdio.h>
#include<stdlib.h>
/*declaration of macro for memory allowcation purpose*/
#define memory (struct node *)malloc(sizeof(struct node))
/*declaration of structure of node*/
struct node{
  
  int d;
  struct node *left,*right;
  struct node *next;
}*top1,*top2;
/*iinit() initilization root of tree to null*/
void init(struct node **root){
	*root = NULL;
}
/*push_ltor() helping to print element left to rigth*/
void push_ltor(struct node *N){
   
   if(top1 == NULL)
    top1 = N;
  else
  {
    N->next = top1;
    top1 = N;
  }

}
/*push_rtol() helping to print element right to left*/
void push_rtol(struct node *N){
  if(top2 == NULL)
    top2 = N;
  else
  {
    N->next = top2;
    top2 = N;
  }
}
/*ltor() poping element to for left to right printing*/
struct node * ltor(){
struct node *t;      
      if(top1 == NULL)
        return NULL;
      else
      {
          t = top1;
          top1 = top1->next;
          t->next = NULL;
      }
 return t;     
}
/*rtol() poping element to for right to left printing*/
struct node * rtol(){
 struct node *t;
    if(top2 == NULL)
      return NULL;
    else
    {
      t = top2;
      top2 = top2->next;
      t->next = NULL;
    }
 return t;   
}
/*newNode() return structure of node*/
struct node * newNode(int d){
	struct node *newnode;
	newnode = memory;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->d = d;
return newnode;	
}
/*insert_node() create BST & return root of tree*/
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
          	N->right = insert_node(N->right,d);
      }

 return N;
}
/*sprial_print() printing tree in sprial order*/
void sprial_print(struct node *N){
   struct node *t;

       init(&top1);
       init(&top2);
       push_ltor(N);

       while(1){
          
           while(top1!=NULL){
             t = ltor();
             push_rtol(t->left);
             push_rtol(t->right);
             printf("%d ",t->d);
           }

           while(top2!=NULL){
            t = rtol();
            push_ltor(t->right);
            push_ltor(t->left);
            printf("%d ",t->d);
           }

           if(top1 == NULL && top2 == NULL)
            break;
       }
}
/*postorder traversal of tree*/
void postorder(struct node *N){
  if(N == NULL)
    return;
  postorder(N->left);
  postorder(N->right);
  printf("%d ",N->d);
}
/*start main execution of programm*/
int main(int argc, char const *argv[])
{
  /*declaration of require variable*/
  int cho,d;
  struct node *root;

  system("clear");

  init(&root);//initilization of root of tree to null
  //choises
  do{
    printf("\n\t1-insert node\n\t2-postorder\n\t3-sprial order print\n\t4-exit\n\t:");
    scanf("%d",&cho);

      switch(cho){

        case 1: printf("\n\tEnter node :");
                scanf("%d",&d); 
                root = insert_node(root,d);
                break;
        case 2:printf("\n\tpostorder of tree : ");
               postorder(root);
               break;
        case 3:sprial_print(root);
               break;
        case 4:printf("\n\texit...");
               break;                      
      }
  }while(cho<4);

  return 0;
}
//end