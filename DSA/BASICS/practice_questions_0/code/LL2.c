// ALternatively merging 2 linked lists

#include <stdio.h>
#include <stdlib.h>

struct SLL {
    int val;
    struct SLL * next ;
};

typedef struct SLL * node;

node createNode(int x);
node insert_back(node *head,node *tail,int x);
node merge_alternate(node head1,node head2);
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
    printf("Enter elements for list 1: ");
    
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        tail1 = insert_back(&head1,&tail1,x);
    }

    printf("Enter number of elements for list 2: ");
    scanf("%d",&n);
    printf("Enter elements for list 2: ");
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        tail2 = insert_back(&head2,&tail2,x);
    }

    node head3 = merge_alternate(head1,head2);
    displayLL(head3);
    
    return 0;
}

////////////////////////////
node createNode(int x){
    node newnode = (node)malloc(sizeof(struct SLL));
    newnode->val=x;
    newnode->next=NULL;
    return newnode;
}
////////////////////////////
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
node merge_alternate(node head1, node head2) {

    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }

    node ptr1 = head1;
    node ptr2 = head2;

    node mergedHead = ptr1;// decalring head of merged list from list 1
    node mergedTail = mergedHead;

    ptr1=ptr1->next;

    while(ptr1!=NULL && ptr2!=NULL){
        mergedTail->next=ptr2; // merging from list 2, as first was from list 1
        mergedTail=mergedTail->next;
        ptr2=ptr2->next;

        mergedTail->next=ptr1; // merging from list 1
        mergedTail=mergedTail->next;
        ptr1=ptr1->next;
        
    }
    while(ptr1!=NULL){
        mergedTail->next=ptr1;
        mergedTail=mergedTail->next;
        ptr1=ptr1->next;
    }
    while(ptr2!=NULL){
        mergedTail->next=ptr2;
        mergedTail=mergedTail->next;
        ptr2=ptr2->next;
    }

    mergedTail->next=NULL;

    return mergedHead;
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
