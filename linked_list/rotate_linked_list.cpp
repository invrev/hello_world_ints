#include<iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode (int x)  : val(x),next (NULL) {}
};

//TODO : Handle the case K = 0 or k > length of the list
//https://oj.leetcode.com/discuss/4570/are-there-any-better-answers
ListNode *rotateList (ListNode* head,int k ) {
    if (head == 0 || head->next == 0 || k == 0) {
        return head ;
    }
    ListNode* h1 = head;
    ListNode* h2 = head;
    while (k > 0) {
        h1 = h1->next;
        k -= 1;
    }
    while (h1->next != NULL) {
        h1 = h1->next;
        h2 = h2->next;
    }

    ListNode* next_half = h2->next ;
    h2->next = NULL;
    ListNode* new_head = next_half;
    while (next_half->next != NULL) {
        next_half = next_half->next;
    }
    next_half->next = head;
    return new_head;
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

void print_list (ListNode* head) {
    while (head != NULL) {
        cout << head->val << ",";
        head = head->next;
    }
    cout << endl;
}

int main () {

    int a[] = { 5,4,3,2,1 };
    int len = sizeof(a)/sizeof(a[0]);
    ListNode* head = create_list (a,len);
    print_list (head);
    ListNode* new_head = rotateList (head,2);
    print_list (new_head);
    
}
