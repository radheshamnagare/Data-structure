/*require header files*/
#include<stdio.h>
#include<stdlib.h>
/*declaration  of macro for memory allowcation*/
#define memory (struct node*)malloc(sizeof(struct node))
/*declarion of structure of node*/
struct node{
 int key;
 int height;
 struct node *left,*right;
};
/*init() initilization of root of tree to NULL*/
void init(struct node **root){
	*root = NULL;
}
/*max() return max height*/
int max(int a,int b){
	return (a>b)?a:b;
}
/*height return height of tree*/
int height(struct node *N){
	if(N == NULL)
		return 0;
	else
		return N->height;
}
/*get_bal() return balace of tree*/
int get_bal(struct node *N){
	return height(N->left) - height(N->right);
}
/*newNode() return structure of node pointer*/
struct node *newNode(int d){
	struct node *newnode;

	newnode = memory;
	newnode->key = d;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1;

  return newnode;  
}
/*leftRotate() left rotation of tree*/
struct node * leftRotate(struct node *x){

   struct node *y = x -> right;
   struct node *T = y -> left;
 
      y->left = x;
      x->right = T; 
   x->height = 1 + max(height(x->left),height(x->right));
   y->height = 1 + max(height(y->left),height(y->right));

   return y;
}
/*rightRotate() right rotation of tree*/
struct node * rightRotate(struct node *y){
  
  struct node *x = y -> left;
  struct node *T = x -> right;

    x -> right = y;
    y->left = T;

    x->height = 1 + max(height(x->left),height(x->right));
    y->height = 1+ max(height(y->left),height(y->right));

   return x; 
}
/*insert() create AVL tree*/
struct node * insert(struct node *node,int key){
	 if(node == NULL)
	 	return newNode(key);
	 else if(key<node->key)
	 	node->left = insert(node->left,key);
	 else
	 	node->right = insert(node->right,key);

     node->height = 1 + max(height(node->left),height(node->right));
     int bal = get_bal(node);

     if (bal > 1 && key < node->left->key) 
		return rightRotate(node); 
	  if (bal < -1 && key > node->right->key) 
		return leftRotate(node);  
  	
    if (bal > 1 && key > node->left->key) 
	  { 
		node->left = leftRotate(node->left); 
		return rightRotate(node); 
	  } 

  	if (bal < -1 && key < node->right->key) 
	  { 
		 node->right = rightRotate(node->right); 
		 return leftRotate(node); 
	  } 

 return node;
}
/*minValueNode() return last left side of node*/
struct node * minValueNode(struct node* node)  
{  
    struct node* current = node;  

    while (current->left != NULL)  
        current = current->left;  
  
    return current;  
} 
/*deleteNode() delete require node from tree*/
struct node* deleteNode(struct node* root, int key) 
{ 
    
    if (root == NULL) 
        return root; 
    if ( key < root->key ) 
        root->left = deleteNode(root->left, key); 
    else if( key > root->key ) 
        root->right = deleteNode(root->right, key); 
    else
    { 
        if( (root->left == NULL) || (root->right == NULL) ) 
        { 
            struct node *temp = root->left ? root->left : root->right; 
 
            if (temp == NULL) 
            { 
                temp = root; 
                root = NULL; 
            } 
            else 
             root = temp; 
            free(temp); 
        } 
        else
        { 
            struct node* temp = minValueNode(root->right); 
            root->key = temp->key; 
            root->right = deleteNode(root->right, temp->key); 
        } 
    } 
   
    if (root == NULL) 
      return root; 
    root->height = 1 + max(height(root->left), 
                           height(root->right));  
    int balance = get_bal(root); 
   
    if (balance > 1 && get_bal(root->left) >= 0) 
        return rightRotate(root); 
   
    if (balance > 1 && get_bal(root->left) < 0) 
    { 
        root->left =  leftRotate(root->left); 
        return rightRotate(root); 
    } 
  
    if (balance < -1 && get_bal(root->right) <= 0) 
        return leftRotate(root); 
  
    if (balance < -1 && get_bal(root->right) > 0) 
    { 
        root->right = rightRotate(root->right); 
        return leftRotate(root); 
    } 
  
    return root; 
}
/*preorder() preorder traversal of tree*/
void preorder(struct node *N){
	if(N == NULL)
		return;
	printf("%d ",N->key);
	preorder(N->left);
	preorder(N->right);
}
/*starting main execution of programm*/
int main(int argc, char const *argv[])
{
  /*require variable declarion */
	struct node *root;
	int cho,d;
  system("clear");
  init(&root);// initilization tree of root to NULLL
 //choises
   do{
     
      printf("\n\t1-insert\n\t2-delete node\n\t3-preoder of tree\n\t4-exit\n:");
      scanf("%d",&cho);

         switch(cho){

          case 1: printf("\nEnter the value :");
                  scanf("%d",&d); 
                  root = insert(root,d);
                  break;
          case 2: printf("\nEnter node to delete :");
                  scanf("%d",&d);
                 root = deleteNode(root,d);
                 break;
          case 3: printf("\npreorder of tree:");
                  preorder(root);
                  break;
          case 4:printf("\nExited...");
                 break;                        
         }
   }while(cho<4);

	return 0;
}
//end