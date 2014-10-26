#include<iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode (int x)  : val(x),next (NULL) {}
};

//L : l0->l1->l2->.....->ln-1->ln
//l0->ln->l1->ln-1
//In place w/o altering the node values
//1. break the list into half
//2. reverse the second half
//3. merge the linked list alternatively.


void print_list (ListNode* head) {
    while (head != NULL) {
        cout << head->val << ",";
        head = head->next;
    }
    cout << endl;
}

ListNode *reverseList (ListNode *head) {
    if (head == 0) {
        return head;
    }
    ListNode* current = head;
    ListNode* prev = 0;
    ListNode* front = 0;
    while (current != 0) {
        front = current->next;
        current->next = prev;
        prev = current;
        current = front;
    }
   return prev; 
}

ListNode *reorderList (ListNode* head) {
    int len = 0;
    if (head == 0 || head->next == 0) {
        return head;
    }
    ListNode *tmp = head;
    while (tmp != 0) {
        tmp = tmp->next;
        len ++;    
    }
    int half_len = len / 2;
    //cout << "half_len " << half_len  << endl;
    ListNode *h1 = head;
    while (half_len > 0) {
        h1 = h1->next;
        half_len -= 1;
    }
    ListNode *h2 = h1->next;
    h1->next = NULL;
    ListNode* h2_rev = reverseList (h2);

    //print_list (head);
    //print_list (h2_rev);

    half_len = len / 2;
    ListNode* tmp_head = head;
    while (half_len > 0 ) {
        ListNode* tmp_next = tmp_head->next;
        tmp_head->next = h2_rev;
        ListNode* h2_next = h2_rev->next;
        h2_rev->next = tmp_next;
        tmp_head = tmp_next;
        h2_rev = h2_next;
        half_len -= 1;
    }

    //print_list (head);
    return head;
}

ListNode* create_list (int a[] , int n) {
    ListNode *head = NULL;
    for (int i=0;i<n;i++) {
      ListNode *tmp = new ListNode(a[i]);
      if (head == NULL) {
          head = tmp;
      } else  {
          tmp->next = head;
          head = tmp;
      }
    }
    return head;
}

int main () {

    int a[] = { 5,4,3,2,1 };
    int len = sizeof(a)/sizeof(a[0]);
    ListNode* head = create_list (a,len);
    print_list (head);
    ListNode* new_head = reorderList (head);
    //print_list (new_head);
    
}
