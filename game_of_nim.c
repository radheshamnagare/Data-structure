#include<stdio.h>
#include<stdlib.h>

int disp(int); 
int no_of_container;
int no_of_player;  

struct game_of_nim{
  struct stack{
     int data[1];
     int top;
  }st;
}*gon;

void init(int i){
 gon[i].st.top=-1;
}

int winner(){
 int i; 
  for(i=0;i<no_of_container;i++){
    if(gon[i].st.top!=-1)
     return 0;
  }
  
  return 1;
}
int isEmpty(int st_pos){
  if(gon[st_pos].st.top==-1)
  return 1;
  
  return 0;
}
int isFull(int st_pos){
  if(gon[st_pos].st.top==0)
   return 1;
   
   return 0;
}
void push(int st_pos,int data){
 int p;
  if(isFull(st_pos))
   printf("\ncontainer is full.");
  else{
    p=++gon[st_pos].st.top;
    gon[st_pos].st.data[p]=data;
 
  } 
}
void pop(int ply){
 
 int st_pos,stone,con,v,f=0,i;
  printf("\nEnter the container position for player %d:",ply);
  scanf("%d",&st_pos);
  
  if(st_pos<=0||st_pos>no_of_container)
    printf("\ninvalid container position you get chance next time." );
  else{    
  if(isEmpty(st_pos-1))
   printf("container is empty.");
    else{
     printf("\nhow many stone get from container%d :",st_pos);
     scanf("%d",&stone);
        
        if(stone>disp(st_pos-1))
         printf("\nno stone greater than container stone");
          for(i=0;i<no_of_container;i++){
            if(disp(i)!=0){
              if(stone>disp(i)){
               printf("\nenter mimimum stone with respect to all (non-zero) container.\n");
               f=1;
               break;
              }
            }
          }
                     if(f==0){
                       v=gon[st_pos-1].st.data[gon[st_pos-1].st.top--]-stone;
                       if(v==0)
                        init(st_pos-1);
                        else
                         push(st_pos-1,v);
                     }
   
    }
   }
}
int random_n(){
   int v;
   v = rand()%6;
  return v;
}

int disp(int st_pos){
 int j=0,val;
   if(isEmpty(st_pos))
    return 0;
  return gon[st_pos].st.data[j];
}
int main(){
 
 int i,j;
 system("clear");
 
  printf("\nEnter the no of container:");
  scanf("%d",&no_of_container);
  printf("\nEnter the no of player (<):");
  scanf("%d",&no_of_player);
  if(no_of_player<1)
   no_of_player=2;
  gon = (struct game_of_nim *)malloc(no_of_container*sizeof(struct game_of_nim));
   for(i=0;i<no_of_container;i++){
     init(i);
   }
 
   for(i=0;i<no_of_container;i++){
     push(i,random_n());
   }
   
   printf("\n*no_of_player %d",no_of_player);
   printf("\n*no_of_container %d and it's stone\n",no_of_container);
   for(i=0;i<no_of_container;i++){
     printf("container%d : no_of_stonne %d\n",(i+1),disp(i));
   }
   
   printf("\n\n\t*** Game start ***\n");
   
   while(1){
     for(i=0;i<no_of_player;i++){
       pop(i+1);
       if(winner()){
           printf("\n\t**** player %d is winner.***\n",(i+1));
            exit(0);
           }
       printf("\nno_of_container %d and it's stone\n",no_of_container);
       for(j=0;j<no_of_container;j++){
       printf("container%d : no_of_stonne %d\n",(j+1),disp(j));
         
   }
     }
   }
   
     
     
return 0;

}
