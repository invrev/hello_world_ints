#include<iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


ListNode* swap (ListNode* current,ListNode* front) {
    current->next = front->next;
    front->next= current;
    return front;
}

ListNode *swapPairs(ListNode *head) {
    ListNode* dummyHead = new ListNode (0);
    dummyHead->next = head;

    for (ListNode *current = dummyHead
            ;current->next != 0 && current->next->next != 0 
            ;current = current->next->next ) {

        current->next = swap (current->next,current->next->next);

    }
    return (dummyHead->next);
}

void printList (ListNode *head) {
    while (head !=0 ) {
        cout << head->val << " " ;
        head = head->next;
    }
    cout << endl;
}

int main () {

    ListNode* head = new ListNode (1);
    head->next  = new ListNode (2);
    head->next->next = new ListNode (3);
    head->next->next->next = new ListNode (4);
    head->next->next->next->next = new ListNode (5);
    printList (head);
    ListNode* head1= swapPairs (head);
    printList (head1);
}
