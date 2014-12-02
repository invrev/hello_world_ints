#include<iostream>


//With 2 pointers
ListNode *deleteDuplicates(ListNode *head) {
    if(head == NULL) {
        return NULL;
    }
    ListNode* sen = new ListNode(-1);
    sen->next = head;
    ListNode* ptr1 = sen;
    ListNode* curr = head;
    while(ptr1 != NULL) {
        while(curr != NULL && curr->next != NULL && curr->next->val == curr->val) {
                while(curr->next != NULL && curr->next->val == curr->val) {
                    //for eg {1,1} o/p {}
                    curr = curr->next;
                }
                curr = curr->next;    
        }
        ptr1->next = curr;
        ptr1 = curr;
        if(curr != NULL ) {
            curr = curr->next;
        }
    }
    return sen->next;
}


//Remove duplicates using hashmap and sentinel node
ListNode *deleteDuplicates(ListNode *head) {
    unordered_map<int, int> count;

    for (auto p = head; p; p = p->next)
        count[p->val]++;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    for (auto p = head, q = dummy; p; p = p->next)
        if (count[p->val] > 1) {
            q->next = p->next;
        }
        else {
            q = p;
        }
    return dummy->next;

    //OR 
    //---ListNode dummy(0);
    //---dummy.next = head;

    //----for (auto p = head, q = &dummy; p; p = p->next)
    //    if (count[p->val] > 1) {
    //        q->next = p->next;
    //    }
    //    else {
    //        q = p;
    //    }
    //---return dummy.next;

}

int main () {

}
