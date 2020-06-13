/*require header files*/
#include<stdio.h>
#include<stdlib.h>

/*declarion of macro for memory allowcation purpose*/
#define memory (struct node *)malloc(sizeof(struct node))
/*declaration of structure of node*/
struct node{
  int d;
  struct node *next;
  struct node *left,*right;
}*top;
/*init() initilize root of tree to NULL*/
void init(struct node **root){
	*root = NULL;
}
/*newNode() return  structure of node pointer*/
struct node * newNode(int d){
	struct node *newnode;
	newnode = memory;
	newnode->left = NULL;
	newnode->right = NULL;
  newnode->next = NULL;
	newnode->d = d;
return newnode;	
}
/*insert_node() create BST and return root of tree*/
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
/*push() pushing element in structure of node as stack*/
void push(struct node *N){
  if(top == NULL)
    top = N;
  else
  {
    N->next = top;
    top = N;
  }
}
/*pop() poping element form structure of node as stack*/
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
/*inorder() inorder traversal of tree*/
void inorder(struct node *N){
  
  if(N == NULL)
    return;
  inorder(N->left);
  printf("%d ",N->d);
  inorder(N->right);

}
/*preorder() preorder traversal of tree*/
void preorder(struct node *N){

  if(N == NULL)
    return;
  printf("%d ",N->d);
  preorder(N->left);
  preorder(N->right);

}
/*postorder() postorder traversal of tree*/
void postorder(struct node *N){

  if(N == NULL)
    return;
  postorder(N->left);
  postorder(N->right);
  printf("%d ",N->d);

}
/*find_min1() helping building root of right side of tree return max element for right side tree*/
int find_min1(struct node *root,struct node *N,int a[],int n){
  int i;
  for(i=n-1;i>=0;i--){
     if(a[i] > root->d && a[i] < N->d)
      return a[i];
  }

return -1;
}
/*find_max1() helping building root of right side of tree and return min element for right side tree */
int find_max1(struct node *root,struct node *N,int a[],int n){
 int i;
  for(i=n-1;i>=0;i--){
     if(a[i] > root->d && a[i] > N->d)
      return a[i];
  }

return -1; 
}
/*find_max1() helping building root of left side of tree and return min element for left side tree */
int find_min2(struct node *root,struct node *N,int a[],int n){
  int i;
  for(i=n-1;i>=0;i--){
   if(a[i] < root->d && a[i] < N->d)
      return a[i];  
  }

return -1;
}
/*find_max1() helping building root of left side of tree and return max element for left side tree */
int find_max2(struct node *root,struct node *N,int a[],int n){
 int i;
  for(i=n-1;i>=0;i--){
       if(a[i] < root->d && a[i] > N->d)
        return a[i];
  }

return -1; 
}
/*start main execution of programm*/
int main(int argc, char const *argv[])
{
  /*require declaration of variable*/
  int d;
  int j,cho,t1,t2;
  struct node *root,*t,*nd;

  system("clear");
 //choises
  do{
      printf("\n\t1-input postorder of tree\n\t2-construct tree\n\t3-traversal of tree\n\t4-exit\n:");
      scanf("%d",&cho);

      switch(cho){
         
         case 1: init(&top);
                 printf("\n\tenter -1 to exit");//create array
                 while(1){
                   printf("\n\t:");
                   scanf("%d",&d);
                   if(d == -1)
                    break;
                    push(newNode(d));
                 }
                 break;

          case 2: init(&root);// initilization of tree of root
                   while(top!=NULL){
                    root = insert_node(root,pop()->d);
                   }
                 break;    
            case 3:printf("\npreorder : "); //traversal of tree
                   preorder(root);
                   printf("\ninorder : ");
                   inorder(root);
                   printf("\npostorder : ");
                   postorder(root);
                   break;
           case 4:printf("\nexited...");
                  break;                  
      }

  }while(cho<4);

  return 0;
}
//end