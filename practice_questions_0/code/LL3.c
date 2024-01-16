// Merge 2 sorted linked list 

#include <stdio.h>
#include <stdlib.h>

struct SLL {
    int val;
    struct SLL * next ;
};

typedef struct SLL * node;

node createNode(int x);
node insert_back(node *head,node *tail,int x);
node merge_sorted(node head1,node head2);
void displayLL(node head);

int main()
{
    node head1=NULL;
    node head2=NULL;
    node tail1=NULL;
    node tail2=NULL;

    int n,x;

    printf("Enter number of elements for list 1: ");
    scanf("%d",&n);
    printf("Enter sorted elements for list 1: ");
    
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        tail1 = insert_back(&head1,&tail1,x);
    }

    printf("Enter number of elements for list 2: ");
    scanf("%d",&n);
    printf("Enter sorted elements for list 2: ");

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        tail2 = insert_back(&head2,&tail2,x);
    }

    node head3 = merge_sorted(head1,head2);
    displayLL(head3);
    
    return 0;
}

//////////////////////////////////////
node createNode(int x){
    node newnode = (node)malloc(sizeof(struct SLL));
    newnode->val=x;
    newnode->next=NULL;
    return newnode;
}
//////////////////////////////////////
node insert_back(node *head, node *tail, int x) {
    if (*tail == NULL) {
        *tail = createNode(x);
        *head = *tail;
    } else {
        (*tail)->next = createNode(x);
        *tail = (*tail)->next;
    }
    return *tail;
}

//////////////////////////////
node merge_sorted(node head1, node head2) {
    node ptr1=head1;
    node ptr2=head2;
    node head3=NULL;


    node tail3=NULL;

    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->val < ptr2->val){
            insert_back(&head3,&tail3,ptr1->val);
            ptr1=ptr1->next;
        }
        else{
            insert_back(&head3,&tail3,ptr2->val);
            ptr2=ptr2->next;
        }
    }
    if(ptr1==NULL){
        while(ptr2!=NULL){
            insert_back(&head3,&tail3,ptr2->val);
            ptr2=ptr2->next;
        }
    }
    else{
        while(ptr1!=NULL){
            insert_back(&head3,&tail3,ptr1->val);
            ptr1=ptr1->next;
        }
    }

    return head3;
}

////////////////////////////
void displayLL(node head){
    if(head==NULL){
        printf("Empty list\n");
        return;
    }
    node temp=head;

    while(temp!=NULL){
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");

}
