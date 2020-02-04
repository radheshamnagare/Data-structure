#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char FNAME[22];
struct node *p;

struct node{
 char line[80];
 struct node *next,*prev;
};

void undo(){
   if(p->prev!=NULL)
   p=p->prev;
}

void redo(){
 if(p->next!=NULL)
 p=p->next;
}

struct node * createPara(struct node *start){   
struct node *temp,*newnode;
    
     while(1){
     newnode = (struct node *)malloc(sizeof(struct node));
     newnode->next = NULL;
       
       gets(&newnode->line);
          if(start==NULL){
            p=temp=start=newnode;
           
          }
          else{
            for(temp=start;temp->next!=NULL;temp=temp=temp->next);
            temp->next = p = newnode;
            newnode->prev = temp;
            
          
          }
        if(strcmp(newnode->line,"\e")==0)
         break;
     }
      
  return start;    
}


void dispDoc(){
 FILE *fp;
 char buff[80];
  printf("\nEnter the file name :");
  scanf("%s",FNAME);
  fp = fopen(FNAME,"r");
  if(fp==NULL)
   printf("ERROR OPENING DOCUMENT.");
  else{
    while(fgets(buff,80,fp)!=NULL)
     printf("%s",buff);
  } 
  fclose(fp);
}

void disp(struct node *start){
  struct node *temp;
  
  for(temp=start;temp!=p;temp=temp->next)
  printf("%s\n",temp->line);
}
void saveDoc(struct node *start){

FILE *fp;
struct node *temp;
  printf("\nEnter the file name:");
  scanf("%s",&FNAME);
  fp = fopen(FNAME,"w");
  if(fp==NULL)
   printf("ERROR");
  else{
    for(temp=start;temp!=p;temp=temp->next){
     fputs(temp->line,fp);
     fputc('\n',fp);
     }
     printf("\nfile save successfuly.");
  } 
  fclose(fp);
}
void updateLine(struct node *start){
  int lno,i;
  struct node *temp;
  
  printf("\nEnter the line number:");
  scanf("%d",&lno);
  
  for(i=1,temp=start;i<lno&&temp!=NULL;temp=temp->next,i++);
  
  printf("\nEnter the line to update :");
  scanf("%s",;temp->line);
  
}
int main(){
 
 char *p;
 int ch; 
 struct node *start=NULL;
 system("clear");   
 
  do{
  
     printf("\n\n1-create document\n2-save document\n3-open document\n4-undo\n5-redo\n6-update line");
     printf("\nEnter the option:");
     scanf("%d",&ch);
       switch(ch){
        case 1: start = createPara(start);break;
        
        case 2:saveDoc(start);break;
        
        case 3:dispDoc();break;
        
        case 4:undo();
               disp(start);
               break;
        
        case 5:redo();
               disp(start);
               break;
        case 6:updateLine(start);
               break;	      
       }
  }while(ch<7); 
  

return 0;
}
