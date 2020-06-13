/*require header files*/
#include<stdio.h>
#include<stdlib.h>

int inx = 0;//index variable
int *arr; // dymanic array
/*declaration of macro for memory allowcation purpose*/
#define memory (struct node *)malloc(sizeof(struct node))
/*declaration structue of node*/
struct node{
  int d;
  struct node *left,*rigth;
};
/*init() initilization tree of root to NULL*/
void init(struct node **root){
	*root = NULL;
}
/*newNode() return structure of node pointer*/
struct node * newNode(int d){
	struct node *newnode;
	newnode = memory;
	newnode->left = NULL;
	newnode->rigth = NULL;
	newnode->d = d;
return newnode;	
}
/*create_tree() create BST and return root of node*/
struct node * create_tree(struct node *N,int v){
    if(N == NULL)
        N = newNode(v);
      else
      {
          if(N == NULL)
            return newNode(v);
          if(v < N->d)
           N->left = create_tree(N->left,v);
          else
            N->rigth = create_tree(N->rigth,v);
      }
      

 return N;
}
/*inorder_traversal() of tree for marge two diff tree*/
void inorder_traversal(struct node *N){
        if(N == NULL)
          return;
        inorder_traversal(N->left);
        arr[inx++] = N->d;
        inorder_traversal(N->rigth);
}

/*marge() storing all nodes of tree in k array*/
struct node * marge(int arr[],int ed1,int st2,int ed2){
 int i,j,inx=0;
 int *k;
 struct node *root;
      i = 0;
      j = st2;
      k =(int*)malloc(ed2*sizeof(int));
      while(i<ed1 && j<ed2){
        if(arr[i]<arr[j])
          k[inx++] = arr[i++];
        else
          k[inx++] = arr[j++];
      }
      while(i<ed1)
        k[inx++] = arr[i++];
      while(j<ed2)
        k[inx++] = arr[j++];
      
      init(&root);
      int mid = (inx/2);
      for(i=mid;i>=0;i--)
       root = create_tree(root,k[i]);
      for(i=mid+1;i<inx;i++)
        root = create_tree(root,k[i]);

  return  root;  
}
/*inorder traversal of tree*/
void inorder(struct node *N){
   if(N == NULL)
    return ;
 
  inorder(N->left);
  printf("%d ",N->d);
  inorder(N->rigth);
}
/*start main execution of tree*/
int main(int argc, char const *argv[])
{
  /*declaration of require variable*/
  struct node *root1,*root2;
  int cho,ed1,ed2,st2,d,i = 0 ,j,p=0;
  int *a = (int*)malloc(sizeof(int));
    
     system("clear"); 
      do{
        
         printf("\n\t1-create BST's\n\t2-inorder display\n\t3-marge\n\t4-exit\n\t:");
         scanf("%d",&cho);
           // choises
          switch(cho){
            
            case 1:printf("\n\tconstruct first tree(-1 enter to exit)");
                   while(1){
                     printf("\n\t:");
                     scanf("%d",&d);
                     if(d == -1)
                      break;
                    a[i++] = d;
                     a = (int*)realloc(a,sizeof(int));
                     p++;
                   }
                   
                   init(&root1);
                   for(j=0;j<i;j++)
                   root1 = create_tree(root1,a[j]);
                   
                   printf("\n\tconstruct second tree(-1 enter to exit)"); 
                   free(a);i=0;
                   a = (int*)malloc(sizeof(int));
                   while(1){
                     printf("\n\t:");
                     scanf("%d",&d);
                     if(d == -1)
                      break;
                    a[i++] = d;
                     a = (int*)realloc(a,sizeof(int));
                     p++;
                   }
                    init(&root2);
                    for(j=0;j<i;j++)
                    root2 = create_tree(root2,a[j]);
                    free(a);
                   break;

            case 2: printf("\n\tinorder 1st tree : ");
                    inorder(root1);
                    printf("\n\tinorder 2nd tree : ");
                    inorder(root2);
                    break;

             case 3: arr = (int*)malloc(p*sizeof(int));
                     inorder_traversal(root1);
                     ed1 = inx;
                     st2 = inx; 
                     inorder_traversal(root2);
                     ed2 = inx;
                     root1 = marge(arr,ed1,st2,ed2);
                     printf("\n\tinorder of marge tree : ");
                     inorder(root1);
                     break;

          }

      } while(cho<4);

  return 0;
}
//end