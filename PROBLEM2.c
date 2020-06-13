/*require header files*/
#include<stdio.h>
#include<stdlib.h>
/*declaration of macro for memory allowcation*/
#define memory (struct node *)malloc(sizeof(struct node))
/*declaration structure of node for tree and stack*/
struct node{
  int d;
  int isthread ;
  struct node *next;
  struct node *left,*right;
}*top;
/*init() initilization root of tree to null*/
void init(struct node **root){
    *root = NULL;
}
/*newNode() returns structure of node pointer*/
struct node * newNode(int d){
    struct node *newnode;
    newnode = memory;
    newnode->next = NULL;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->isthread = 0;
    newnode->d = d;
return newnode; 
}
/*insert_node() create tree as return root of tree*/
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
/*pushing left node of tree to helping threaded tree*/
void push(struct node *N){
  if(top == NULL)
    top = N;
  else
  {
    N->next = top;
    top = N;
  }
}
/*poping node from stack of structure of node*/
struct node * pop(){
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
 /*finding last left node of subtree*/
struct node* left_node(struct node *n) 
{ 
    if (n == NULL) 
    return NULL; 

    while (n->left != NULL) 
        n = n->left; 

    return n; 
} 
/*finding subtree of all left nodes*/
void put_left(struct node *N){
    if(N == NULL)
        return;
        push(N);
        put_left(N->left);
    
}
/*create BT to threaded binary tree and return root of tree*/
struct node * create_thread(struct node *root) { 
struct node *t;   
      put_left(root);

      while(top!=NULL){
          t = pop();
          if(t->left == NULL && t->right == NULL && top!=NULL){
            t->right = top;
            t->isthread = 1;
          } 
          else if(top!=NULL){
            t=t->right;
            if(t->left == NULL && t->right == NULL && top!=NULL){
            t->right = top;
            t->isthread = 1;
            } 
            else
                put_left(t);
          }
      }

 return root;
} 

 /*inorder traversal of tree printing node of threaded tree*/
void inorder(struct node *root) 
{ 
    struct node *p = left_node(root); 
    while (p != NULL) 
    { 
        printf("%d ",p->d); 
 
        if (p->isthread) 
            p = p->right; 
        else  
            p = left_node(p->right); 
    } 
}
/*start main execution of programm*/
int main(int argc, char const *argv[])
{
  /*require variable declaration of tree*/
    int cho,d;
    struct node *root,*t;
    system("clear");

    do{
        
        printf("\n\t1-create tree\n\t2-construct threaded tree\n\t3-display threaded tree\n\t4-exit");
        printf("\n:");
        scanf("%d",&cho);
        // choises
        switch(cho){

            case 1 :init(&root);  // initilization root of tree
                    while(1){
                      printf("\n\tEnter the node :");
                      scanf("%d",&d);
                      if(d==-1)
                        break;
                      root = insert_node(root,d);
                     }
                     break;

            case 2: init(&top);
                    t = root->right;  
                    root->right = NULL;
                    root = create_thread(root);
                    t = create_thread(t);
                    root->right = t;
                    break;

             case 3: inorder(root);
                     break;

             case 4 :printf("\n\texited...");
                     break;                        
        }
    }while(cho<4);

    return 0;
}
//end