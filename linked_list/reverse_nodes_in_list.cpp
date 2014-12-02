#include<iostream>
using namespace std;


//find Kth list node (if size of the list is less than K, return the list without reversing it)
//reverse 1 ~ Kth node
//recursively reverseKGroup in remaining list nodes.

ListNode *reverseKGroup(ListNode *head, int k) {
    int counter = k;
    ListNode *nextHead = head;
    while (counter > 0 && nextHead) {
        nextHead = nextHead->next;
        counter--;
    }
    if (counter > 0) {
        return head;
    }
    ListNode *prev = NULL;
    ListNode *current = head;
    while (current != nextHead) {
        ListNode *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head->next = reverseKGroup(nextHead, k);
    return prev;
}

//Use of sentinel node and iterative version
//Reverse it in every k groups. There is a condition that
//If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//So, I need to reverse the final groups twice to make it in order.

ListNode *reverseKGroup(ListNode *head, int k) {
    if (k == 1) { 
        return head; 
    }
    ListNode * dummy = new ListNode(-1), *tnode = head, *pnode, *cnode;
    ListNode * start;
    int count;
    dummy->next = head;
    start = pnode = dummy;
    while (tnode != NULL){
        count = 0;
        while (tnode != NULL && count < k){
            cnode = tnode;
            tnode = tnode->next;
            cnode->next = pnode;
            pnode = cnode;
            count++;
        }
        if (count < k){
            for (int i = 0; i < count; ++i){
                pnode = cnode->next;
                cnode->next = tnode;
                tnode = cnode;
                cnode = pnode;
            }
            break;
        }
        pnode = start->next;
        start->next->next = tnode;
        start->next = cnode;
        start = pnode;
    }
    return dummy->next;
}


int main () {

}
