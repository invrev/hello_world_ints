#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
    //1.No interleaving 
    //2.With interleaving
    ListNode *h_prev1 = 0;
    ListNode *h_prev2 = 0;
    ListNode *start_ptr = 0;
    if (head1 == 0) {
        return head2;
    }else if (head2 == 0) {
        return head1;
    }
    while (head1 != 0 && head2 != 0) {
        if (head1->val <= head2->val ) {
            if (start_ptr == 0) {
                start_ptr = head1;
            }
            if (h_prev2 != 0 && (h_prev2->val <= head1->val) ) {
                h_prev2->next = head1; 
                h_prev2 = 0;
            }
            h_prev1 = head1;
            head1 =  head1->next;
        } else {
            if (start_ptr == 0) {
                start_ptr = head2;
            }
            if (h_prev1 != 0 && (h_prev1->val <= head2->val) ) {
                h_prev1->next = head2; 
                h_prev1 = 0;
            }
            h_prev2 = head2;
            head2 =  head2->next;
        }
    }
    //Last node
    if (head1 == 0 && head2 != 0) {
        h_prev1->next =  head2;

    } else if ( head1 != 0 && head2 == 0) {
        h_prev2->next = head1; 
    }
    return start_ptr;
}

int main () {
   ListNode* h1 = 0;
   ListNode* h2 = 0;
   ListNode* merge_head = mergeTwoLists (h1,h2);

}
