/*require header files*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
/*declaration of macro for memory allowcation purpose*/
#define memory (struct node *)malloc(sizeof(struct node))
/*declaration node of structure used as tree and stack*/
struct node{
  char d;
  struct node *left,*right ,*next;
}*top1;
/*declaration structure of ope for storing operator and brackes as stack*/
struct ope{
 char d;
 struct ope *next;
}*top2;

/*init() initilize root of tree to NULL*/
void init(struct node **node){
	*node = top1 = NULL;
	top1 = NULL;
}
/*newNode() return structure of node pointer*/
struct node * newNode(char d){
	struct node *newnode;
	
	newnode = memory;
	newnode->d = d;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->next = NULL;

 return newnode;	
}
/*push_opernd() for storing operand in stack*/
void push_opernd(struct node *newnode){
   
   if(top1 == NULL){
      top1 = newnode;
   } 
   else
   {
   	newnode->next = top1;
   	top1 = newnode;
   }
}
/*push_ope() storing operator in structure of ope as stack*/
void push_ope(char d){
   struct ope *newnode;

   newnode = (struct ope*)malloc(sizeof(struct ope));
   newnode->d = d;
   newnode->next = NULL;

   if(top2 == NULL)
   	top2 = newnode;
   else
   {
   	 newnode->next = top2;
   	 top2 = newnode;
   }
}
/*pop_opernd() poping element structure of node as stack and return pointer of node*/
struct node * pop_opernd(){
 struct node *t;
    
    if(top1 == NULL)
    	return '\0';
    t = top1;
    top1 = top1->next;
    t->next = NULL;

 return t;   
}
/*pop_ope() poping element structure of ope as stack and return pointer of ope*/
char pop_ope(){
 struct ope *t;

  if(top2 == NULL)
   return '\0';
  t = top2;
  top2 = top2->next;
  t->next = NULL;

return t->d;    
}
/*create_tree() craete BST and return 1st pointer of tree*/
struct node * create_tree(struct node *root,char expr[]){
int i;
char ch;
struct node *t1,*t2,*t;
     for(i=0;expr[i]!='\0';i++){

     	  if(isdigit(expr[i])){
            push_opernd(newNode(expr[i]));// if operand then push in structure of node
     	  }
     	  else if(ispunct(expr[i]) || expr[i]=='/'){ // arithmatic and brackes occer
             ch = expr[i];
             if(ch == ')'){
             	while(ch != '('){
             		t = newNode(pop_ope());
             		ch = pop_ope();
             	}

             	t1 = pop_opernd();
             	t2 = pop_opernd();

             	t->left = t2;
             	t->right = t1;
                push_opernd(t);
             }
             else
             	push_ope(ch);

     	  }

     }

   return t;  
}
/*postorder() for print postfix expresion from tree*/
void postorder(struct node *N){
	if(N == NULL)
		return;
	
	postorder(N->left);
	postorder(N->right);
	printf("%c",N->d);
}
/*preorder() for print prefix expresion from tree*/
void preorder(struct node *N){
	 if(N == NULL)
	 	return;

     printf("%c",N->d);
	 preorder(N->left);
	 preorder(N->right);
}
/*inorder() for print infix expresion from tree*/
void inorder(struct node *N){
	 if(N == NULL)
	 	return;

	 inorder(N->left);
	 printf("%c",N->d);
	 inorder(N->right);
}
/*start execution of tree*/
int main(int argc, char const *argv[])
{
	/*require variable declaration*/
    char *expr;
    int choise;
    struct oprnd *t1;
    struct ope *t2;
    struct node *root;
   
    system("clear");
    
    init(&root);// initilize root of tree to NULL
    //choises
    do{
        printf("\n\t1-Enter infix expresion\n\t2-prefix\n\t3-postfix\n\t4-infix\n\t5-Exit");
        printf("\n\t:");
        scanf("%d",&choise);

        switch(choise){
           case 1:init(&root);
                  printf("\n\t:");
                  scanf("%s",expr);
                  root = create_tree(root,expr);
                  break;

           case 2:printf("\n\tprefix expresion : ");
                  preorder(root);
                  break;

           case 3:printf("\n\tpostorder expresion : ");
                  postorder(root);
                  break;

           case 4:printf("\n\tinfix expresion : ");
                  inorder(root);
                  break;

           case 5 :printf("\n\tExited...");
                   break;           
        }  

    }while(choise<5);

return 0;
}

//end