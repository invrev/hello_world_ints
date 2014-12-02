#include<iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

//Recursive merge
ListNode* merge(ListNode *a,ListNode *b) {
    ListNode * temp;
    if(a == NULL) {
        return b;
    }
    if(b == NULL) { // short (!b)
        return a;
    }
    if(a->val <= b->val) {   
        temp = a;
        temp->next = merge(a->next,b);
    }
    else {   
        temp = b;
        temp->next = merge(a,b->next);
    }
    return temp;
}

void divide(ListNode *head , ListNode **a,ListNode **b) {
    ListNode *fast,*slow,*prev;
    //init 
    slow=fast=head;
    while(fast && fast->next) {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
    }
    *a=head;
    *b=slow;
    prev->next=NULL;
}

//Recursive sortList
ListNode *sortList(ListNode *head) {
    if(!head) {
        return NULL;
    }
    if(head->next == NULL ) {  //!head->next
        return head;
    }
    ListNode *a,*b;
    divide(head,&a,&b);
    a = sortList(a);
    b = sortList(b);
    return merge(a,b);
}

int main () {

}
