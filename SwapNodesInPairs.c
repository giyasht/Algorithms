struct ListNode* swapPairs(struct ListNode* head){
    int len=0;
    struct ListNode * temp= head;
    while(temp!= NULL){
        len++;
        temp=temp->next;
    }
    if(head==NULL){
        return NULL;
    }
    if(len==1){
        return head;
    }
    struct ListNode * ptr=head->next;
    if(len==2){
        ptr->next=head;
        head->next=NULL;
        return ptr;
    }
    struct ListNode *t=head;
    struct ListNode *tt, *ttt;
    if(len>2){
        for(int i=0; i<len; i++){
            if(i%2==0 && i==0){
                tt=t->next;
                t->next= tt->next;
                tt->next=t;
            }
            
            if(i%2==0 && i!=len-1 && i>0){
                tt=t->next;
                ttt->next=t->next;
                t->next= tt->next;
                tt->next=t;
            }
            
            if(i%2!=0 ){
                ttt=t;
                t=t->next; 
            }
        }
    }
    return ptr;
}
