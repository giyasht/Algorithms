// 234. Palindrome Linked List
#include<bits/stdc++.h>
using namespace std;

class ListNode {
    public:
        int data;
        ListNode* next;

    public:
        ListNode(int data){
            this->data = data;
            this->next = NULL;
        }
};

void insertAtTail(ListNode* &tail, int data) {
    ListNode* temp = new ListNode(data);
    tail->next = temp;
    tail = tail->next;
}

void print(ListNode* &head) {
    ListNode* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool isPalindrome(ListNode* head) {

    ListNode* temp = head;
    
    stack<int> s;

    while(temp != NULL) {
        s.push(temp->data);
        temp = temp->next;
    }
    
    temp = head;

    while(!s.empty() && temp != NULL) {
        if(temp->data == s.top()) {
            s.pop();
            temp = temp->next;
        }
        else {
            return false;
        }
    }

    if(s.empty())
        return true;
    else 
        return false;
}

int main() {

    ListNode* node1 = new ListNode(1);
    
    ListNode* head1 = node1;
    ListNode* tail1 = node1;

    insertAtTail(tail1, 2);
    insertAtTail(tail1, 4);
    insertAtTail(tail1, 2);
    insertAtTail(tail1, 1);

    print(head1);

    cout << isPalindrome(head1) << endl;
    return 0;
}