#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    char name[50];
    char roll[10];
    int age;
    struct node *next;
}node;
node *createnode(char *name,char *roll,int age){
    node *x=(node*) malloc(sizeof(node));
    strcpy(x->name,name);
    strcpy(x->roll,roll);
    x->age=age;
    x->next=NULL;
    return x;
}
void insert(node**head,int n,char*name,char *roll,int age){
    int ind=age;
    for(int i=0;name[i]!='\0';i++){
        ind+=name[i];
    }
    //printf("%d",ind);
    ind%=4;
    //printf("->%d\n",ind);
    node *x=createnode(name,roll,age);
    node *temp=head[ind];
    if(!temp){
        head[ind]=x;
    }
    else{
        while(temp->next){
            temp=temp->next;
        }
        temp->next=x;
    }
    
}
void display(node**head,int ind){
    node *temp=head[ind];
    int count=0;
    while(temp){
        count++;
        temp=temp->next;
    }
    printf("%d ",count);
    if(count==0){
       // printf("-1\n");
        return;
    }
    else{
        temp=head[ind];
        while(temp){
        printf("%s ",temp->name);
        temp=temp->next;
    }
   
    }
    return;
}
void specgrpdis(node**head,int ind,char a,char b){
   node *temp=head[ind];
    int count=0;
     //  printf("%c %c",a,b);
      while(temp){
        //printf("%s->",temp->roll);
      // printf("->%c %c",temp->roll[7],temp->roll[8]);
     if((temp->roll[7]==a && temp->roll[8]==b) || (temp->roll[7]==a-32 && temp->roll[8]==b-32)){
        //printf("hi");
           printf("%s ",temp->name); 
           count=1;
        }
        
        temp=temp->next;
    }
    if(count==0){
         printf("-1");
        return;
    }
    return;
}
int main(){
    int n;
    scanf("%d",&n);
    char name[50];
    char roll[10];
    int age;
    node *head[4]={NULL,NULL,NULL,NULL};
    for(int i=0;i<n;i++){
          scanf("%s %s %d",name,roll,&age);
          //printf("%s %s %d",name,roll,age);
          insert(head,n,name,roll,age);
    }
    char ch;
    int ind;
    char grp[3];
    while(1){
         scanf(" %c",&ch);
         switch(ch){
            case 'c' : scanf("%d",&ind);
                       display(head,ind);
                        printf("\n");
                       break;
            case '1' :
            case '2' :
            case '3' :
            case '0' :  scanf("%s",grp);
                        specgrpdis(head,ch-'0',grp[0],grp[1]);
                         printf("\n");
                        break;
            case 'e' : return 1;            
                       
         }
    }
}