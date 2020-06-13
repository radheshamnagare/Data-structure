/*require header files*/
#include<stdio.h>
#include<stdlib.h>
 /*declaration of structure of node*/
struct node{
    int data;    
    char color;  
    struct node *left, *right, *parent;
};
 /*initilization root of tree to null*/
void init(struct node **root){
    *root = NULL;
} 
/*left rotation of tree*/
void LeftRotate(struct node **root,struct node *x)
{
    struct node *y = x->right;
    x->right = y->left;
    if (x->right != NULL)
        x->right->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        (*root) = y;

    else if (x == x->parent->left)
        x->parent->left = y;
    else    x->parent->right = y;
    y->left = x;
    x->parent = y;
}
 /*right rotation of tree*/
void rightRotate(struct node **root,struct node *y)
{
    struct node *x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;
    x->parent =y->parent;
    if (x->parent == NULL)
        (*root) = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else y->parent->right = x;
    x->right = y;
    y->parent = x;
}
 
/* fixup the Red-Black tree after standard BST insertion*/
void insertFixUp(struct node **root,struct node *z)
{
    while (z != *root && z->parent->color == 'R')
    {
        struct node *y;
        if (z->parent == z->parent->parent->left)
            y = z->parent->parent->right;
        else
            y = z->parent->parent->left;
 
        if (y->color == 'R')
        {
            y->color = 'B';
            z->parent->color = 'B';
            z->parent->parent->color = 'R';
            z = z->parent->parent;
        }
 
        else
        {
            if (z->parent == z->parent->parent->left &&
                z == z->parent->left)
            {
                char ch = z->parent->color ;
                z->parent->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                rightRotate(root,z->parent->parent);
            }
 
            if (z->parent == z->parent->parent->left &&
                z == z->parent->right)
            {
                char ch = z->color ;
                z->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                LeftRotate(root,z->parent);
                rightRotate(root,z->parent->parent);
            }
           if (z->parent == z->parent->parent->right &&
                z == z->parent->right)
            {
                char ch = z->parent->color ;
                z->parent->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                LeftRotate(root,z->parent->parent);
            }
 
            if (z->parent == z->parent->parent->right &&
                z == z->parent->left)
            {
                char ch = z->color ;
                z->color = z->parent->parent->color;
                z->parent->parent->color = ch;
                rightRotate(root,z->parent);
                LeftRotate(root,z->parent->parent);
            }
        }
    }
    (*root)->color = 'B'; 
}
 /*insertion in RED-BLACK tree*/
void insert(struct node **root, int data)
{
    
    struct node *z = (struct node*)malloc(sizeof(struct node));
    z->data = data;
    z->left = z->right = z->parent = NULL;
 
    if (*root == NULL)
    {
        z->color = 'B';
        (*root) = z;
    }
    else
    {
        struct node *y = NULL;
        struct node *x = (*root);
 
        while (x != NULL)
        {
            y = x;
            if (z->data < x->data)
                x = x->left;
            else
                x = x->right;
        }
        z->parent = y;
        if (z->data > y->data)
            y->right = z;
        else
            y->left = z;
        z->color = 'R';
 
        insertFixUp(root,z);
    }
}
 
/* traverse Red-Black tree in inorder fashion*/
void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
 /*start main execution of programm*/
int main()
{
    /*require variable declaration */
   struct node *root;
   int cho,d;
   system("clear");
    init(&root);// initilization root of tree to NULL
    //choises
    do{
        printf("\n\t1-insert\n\t2-inorder of tree\n\t3-exit\n:");
        scanf("%d",&cho);

         switch(cho){

            case 1:printf("\n\tEnter node :");
                   scanf("%d",&d); 
                   insert(&root,d);
                   break;

            case 2: printf("\n\tinorder of tree : ");
                    inorder(root);      
                    break;

              case 3:printf("\nExit..."); 
                      break;      
         }
    }while(cho<3);
    return 0;
}
//end