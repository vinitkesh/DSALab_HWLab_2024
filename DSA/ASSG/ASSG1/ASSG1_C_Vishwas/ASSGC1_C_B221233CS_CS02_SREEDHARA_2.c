#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;
node *createnode(int data){
    node *x=(node*) malloc(sizeof(node));
    x->data=data;
    x->next=NULL;
    return x;
}
 void insert(node**head,int val,int n){
    node *x=createnode(val);
  if(*(head+(val%n))==NULL){
       *(head+(val%n))=x;
  }
  else{
    node* temp=*(head+(val%n));
    if(temp->data==val){printf("-1\n");
                      return;}
    if(temp->data>x->data){
        *(head+(val%n))=x;
        x->next=temp;
    }
    else{
        node* prev=temp;
        while(temp && temp->data<=x->data){
             if(temp->data==val) {
                printf("-1\n");
                return;}
            prev=temp;
            temp=temp->next;
        }
        if(temp){
            x->next=prev->next;
            prev->next=x;
        }
        else{
            prev->next=x;
        }
    }
  }
  return;
}
void printele(node**head,int i){
    node*temp=*(head+i);
    if(!temp){
        printf("-1\n");
        return;
    }
    else{
        while(temp){
            printf("%d ",temp->data);
            temp=temp->next;
        }
         printf("\n");
    }
    return;
}
void search(node**head,int n,int val){
    int ind=val%n;
    node*temp=*(head+ind);
    int pos=1;
    while(temp && temp->data!=val){
        pos++;
        temp=temp->next;
    }
    if(temp){
        printf("%d %d\n",ind,pos);
        }
        else printf("-1\n");
}
int delete(node**head,int val,int n){
    int ind=val%n;
     int pos=1;
    if(head[ind]==NULL){
        printf("-1\n");
        return 0;
    }
    else{
        if(head[ind]->data==val){
            node *temp=head[ind];
            head[ind]=head[ind]->next;
            free(temp);
            printf("%d %d\n",ind,pos);
            return 1;
        }
        else{
            node *temp=head[ind];
            node*prev=temp;
            while(temp && temp->data!=val){
                pos++;
                prev=temp;
                temp=temp->next;
            }
            if(temp){
                 prev->next=temp->next;
                 free(temp);
                 printf("%d %d\n",ind,pos);
                 return 1;
            }
            else{
                printf("-1\n");return 0;}
        }
    }
    printf("-1\n");
    return 0;
}
void update(node**head,int n,int oldval,int newval){
      node *temp=head[newval%n];
      while(temp){
        if(temp->data==newval){
             printf("-1\n");
             return;}
             temp=temp->next;
        }
      if(delete(head,oldval,n)){
        insert(head,newval,n);
      }

}
int main(){
    int n;
    scanf("%d",&n);
 node* head[n];
 for(int i=0;i<n;i++){
    head[i]=NULL;
 }
  char ch;
  int val,newval;
  while(1){
    scanf(" %c",&ch);
    switch(ch){
        case 'i' : scanf("%d",&val);
                   insert(head,val,n);
                   break;
        case 'p' : scanf("%d",&val);
                printele(head,val);
                 break;
        case 's' : scanf("%d",&val);
                   search(head,n,val);
                   break; 
        case 'd' : scanf("%d",&val);
                   delete(head,val,n);  
                   break;
        case 'u' : scanf("%d",&val);
                   scanf("%d",&newval);    
                   update(head,n,val,newval);
                   break;                   
        case 'e' : return 1;                  
    }
  }
}