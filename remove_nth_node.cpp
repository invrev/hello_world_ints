#include<iostream>
using namespace std;

/*
 * Remove nth node from the last in the linked list.
 * NOTE : use of local reference
 */

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthNodeFromList (struct ListNode* head,int n) {
    
    ListNode *first_ptr = head;
    while (first_ptr != 0 && n > 0) {
        first_ptr = first_ptr->next;
        n = n - 1;
    }
    //Local reference
    ListNode **second_ptr = &head;
    while (first_ptr != 0) {
        first_ptr  = first_ptr->next;
        //*second_ptr = (*second_ptr)->next;
        //update local reference pointer
        second_ptr = &(*second_ptr)->next; //correct way to update reference
    }
    //second_ptr is @ node to delete
    if ((*second_ptr)->next != 0) {
        (*second_ptr)->val =  (*second_ptr)->next->val;
        (*second_ptr)->next = (*second_ptr)->next->next;
    } else {
        *second_ptr = 0;
        //second_ptr = NULL;
        //delete *second_ptr;
    }
    return (head);
}


ListNode* create_list (int a[],int n) {
    ListNode* head = 0; 
    for (int i=0;i<n;i++) {
        ListNode* tmp = new ListNode(a[i]) ;
        if (head == 0) {
            head = tmp;
        } else {
            tmp->next = head;
            head = tmp;
        }
    }
    return(head);
}

void printList (ListNode* head) {
    while (head != 0) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main () {
    //int a[] = {1};
    //int a[] = {2,1};
    int a[] = {2,1,3,4,5};
    int n = sizeof(a)/sizeof(int);
    ListNode* head = create_list (a,n);
    printList(head);
    head = removeNthNodeFromList(head,2);
    cout << "After removal " << endl;
    printList(head);
}


