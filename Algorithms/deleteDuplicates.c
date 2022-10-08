#include<stdlib.h>
#include<stdio.h>

typedef struct ListNode{
    int val;
    struct ListNode *next;
} ListNode;

struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode * temp= head, * t = head;
    int len=0;
    if(temp==NULL){
        return NULL;
    }
    while(temp->next!=NULL){
        temp=temp->next;
        len++;
    }
    for(int i=0; i<len; i++){
        if(t->val== (t->next)->val){
            t->next= (t->next)->next;
        }
        else{
            t=t->next;
        }
    }
    return head;
}
ListNode *create_list(int size, int val){
    ListNode *temp;
    ListNode *p = malloc(sizeof(ListNode));
    ListNode *head= p;
    p->val= val;
    p->next=NULL;
    head=p;
    int data_;
    for (int i = 2; i <= size; i++)
    {
        temp=malloc(sizeof(ListNode));
        printf("Enter val to be inserted in node %d  ", i);
        scanf("%d", &data_);
        temp->val= data_;
        temp->next=NULL;
        p->next= temp;
        p=temp;
    }  
    return head; 

}
void display_list( ListNode* head){
    ListNode *temp;
    temp =head;
    while(temp!= NULL){
        printf("%d  ", temp->val);
        temp=temp->next;
    }
    printf("\n");
    
}
int main(){
    printf("Enter the size of 1st linked list  ");
    int size_1;
    int data1,data2;
    ListNode *head1;
    scanf("%d", &size_1);
    printf("Enter val to be inserted in node 1 of 1st ");
    scanf("%d", &data1);
    head1= create_list( size_1, data1);
    display_list( head1);
    ListNode * out= deleteDuplicates(head1);
    display_list(out);
}
