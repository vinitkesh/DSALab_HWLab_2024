// Menu driven programme to do the following :
    // 1. Insert at front/back
    // 2. delete from back/front
    // 3. display the SLL
    // 4. Reverse and display the SLL

#include <stdio.h>
#include<stdlib.h>

struct SLL {
    int val;
    struct SLL * next ;
};

typedef struct SLL * node;

node head=NULL;// globally defined head and tail so that we dont have to pass it all the time
node tail=NULL;

// List of all functions:
node createNode(int x);
node insert_front(int x);
node insert_back(int x);
node delete_front();
node delete_back();
int search();
void displayLL();
void reverseLL();
//////////////////////////////////////////////////////////////////////////////////////
int main()
{
    printf("Welcome to Menu driven programme on SLL:\n Enter your option:\n");

    int c=1;
    int x;
    while(c!=0){
        printf("1. insert at beginning -> enter value\n");
        printf("2. insert at end -> enter value\n");
        printf("3. delete from beginning\n");
        printf("4. delete from end\n");
        printf("5. Display the Linked List\n");
        printf("6. reverse the LL\n");

        scanf("%d",&c);

        switch (c){
            case (1):
                scanf("%d",&x);
                insert_front(x);
                break;
            case 2:
                scanf("%d",&x);
                insert_back(x);
                break;
            case 3:
                delete_front();
            break;
            case 4:
                delete_back();
            break;
            case 5:
                displayLL();
            break;
            case 6:
                reverseLL();
                printf("reversed LL is : \n");
                displayLL();
            break;
            case 0:
            break;
            default:
                break;
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////
node createNode(int x){
    node newnode = (node)malloc(sizeof(struct SLL));
    newnode->val=x;
    newnode->next=NULL;
    return newnode;
}
////////////////////////////
node insert_front(int x){
    if(head==NULL){
        // empty list
        head = createNode(x);
        tail=head;
    } else{
        node newnode = createNode(x);
        newnode->next=head;
        head = newnode;
    }

    return head;
}
/////////////////////////////////
node insert_back(int x){
    if(head==NULL){
        head= createNode(x);
        tail=head;
    } else{
        tail->next = createNode(x);
        tail=tail->next;
    }
    return tail;
}
/////////////////////////////////////////
node delete_back(){
    if(head == NULL){
        return head;
    } else{
        node temp = head;
        node prev = NULL;

        while(temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        if(prev != NULL){
            free(temp);
            prev->next = NULL;
            tail = prev;
        } else {
            // If there's only one element in the list
            free(temp);
            head = tail = NULL;
        }
    }
    return tail;
}
/////////////////////////////////////////
node delete_front(){
    if(head==NULL){
        return head;
    }
    else{
        node ptr1=head;
        node ptr2= head->next;
        free(ptr1);
        head = ptr2;
    }

    return head;
}
////////////////////////////
int search(int x){
    node temp=head;
    while(temp!=NULL){
        if(temp->val==x){
            return 1;
        }
        temp = temp->next;
        
    }
    return 0;
}
////////////////////////////
void displayLL(){
    node temp=head;
    while(temp!=NULL){
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");

    return ;
}
////////////////////////////////
void reverseLL(){
    if (head == NULL || head->next == NULL) {
        // Empty list or only one element, no need to reverse
        return;
    }

    node current = head;
    node prev = NULL;
    node next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    // Update head and tail
    tail = head;
    head = prev;
}
