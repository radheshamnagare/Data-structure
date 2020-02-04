#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 3

struct tower1{
 
 int t1_plate[max];
 int top;
 
}t1;
struct tower2{
  int t2_plate[max];
  int top;
 }t2;

struct tower3{
  int t3_plate[max];
  int top;
 }t3;

void init(){
  t1.top=t2.top=t3.top=-1;
}

int winner(){
   if(t3.top==max-1 && t3.t3_plate[t3.top]==1 && t3.t3_plate[t3.top-1]==2 && t3.t3_plate[t3.top-2]==3)
    return 1;
   return 0; 
}
int isEmpty(int st_pos){
   if(st_pos==1&&t1.top==-1)
    return 1;
   if(st_pos==2&&t2.top==-1)
    return 1;
   if(st_pos==3&&t3.top==-1)
    return 1; 
    
  return 0;  
}

int isFull(int st_pos){
   if(st_pos==1&&t1.top==max-1)
    return 1;
   if(st_pos==2&&t2.top==max-1)
    return 1;
   if(st_pos==1&&t3.top==max-1)
    return 1; 
    
  return 0;
}
int push(int st_pos,int data){
  if(isFull(st_pos))
   printf("stack is full.");
  else {
  if(st_pos==1){
    if(t1.top==-1){
     t1.top++;
     t1.t1_plate[t1.top]=data;
       return 1;
     }
     else if(t1.t1_plate[t1.top]>data){
       t1.top++;
       t1.t1_plate[t1.top]=data;
       return 1;
     }
     else
      printf("we can't move larger plate over smaller plate.");
  }
  else if(st_pos==2){
    if(t2.top==-1){
     t2.top++;
     t2.t2_plate[t2.top]=data;
       return 1;
     }
     else if(t2.t2_plate[t2.top]>data){
       t2.top++;
       t2.t2_plate[t2.top]=data;
       return 1;
     }
     else
      printf("we can't move larger plate over smaller plate.");
  }
  else if(st_pos==3){
    if(t3.top==-1){
     t3.top++;
     t3.t3_plate[t3.top]=data;
      return 1;
     }
     else if(t3.t3_plate[t3.top]>data){
       t3.top++;
       t3.t3_plate[t3.top]=data;
       return 1;
     }
     else
      printf("we can't move larger plate over smaller plate.");
  }
  
  }
  
  return 0;
}
int pop(int st_pos){
 
  if(isEmpty(st_pos))
   printf("Tower%d is empty we can't move plates.",st_pos);
  else{
    if(st_pos==1)
      return t1.t1_plate[t1.top];
    if(st_pos==2)
      return t2.t2_plate[t2.top];
    if(st_pos==3)
      return t3.t3_plate[t3.top]; 
  }
  
  return -1;   
}
void top_decr(int st_pos){
  if(st_pos==1)
   t1.top--;
  if(st_pos==2)
   t2.top--;
  if(st_pos==3)
   t3.top--; 
}
void disp(){
int i;  
   system("clear");
  if(isEmpty(1))
   printf("\nTower 1\nEmpty.");
  else{
     printf("\nTower 1 :");
     for(i=t1.top;i>=0;i--)
     printf("\n%d",t1.t1_plate[i]);
  } 
   
  if(isEmpty(2)) 
   printf("\nTower 2\nEmpty.");
  else{
     printf("\nTower 2 :");
     for(i=t2.top;i>=0;i--)
     printf("\n%d",t2.t2_plate[i]);
  }
  
  if(isEmpty(3)) 
   printf("\nTower 3\nEmpty.");
  else{
     printf("\nTower 3 :");
     for(i=t3.top;i>=0;i--)
     printf("\n%d",t3.t3_plate[i]);
  } 
}
int main(){
 int i,st_pos1,st_pos2,plate;
system("clear");
    init();
    
      if(push(1,3)!=1)
       printf("Error");
      if(push(1,2)!=1)
       printf("Error");
      if(push(1,1)!=1)
       printf("Error");
      printf("\n\n\t******Game is start*********\n");
      while(1){
       
        disp();
        printf("\nEnter the tower position to get plate:");
        scanf("%d",&st_pos1);
        plate = pop(st_pos1);
          if(plate==-1)
           continue;
        printf("\nEnter the tower position to move plate:");
        scanf("%d",&st_pos2);
           if(!(st_pos1>=0 && st_pos2>=0 && st_pos1<=3 && st_pos2<=3)){
            printf("invalid tower position ...");
            exit(0);
           }
          
           
           if(plate!=-1&&push(st_pos2,plate))
              top_decr(st_pos1);
              
            if(winner()){
              disp();
             printf("\n\t*********You are the Winner********\n");
             break;
            }  
      }
      
return 0;
}

