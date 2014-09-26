#include<iostream>
using namespace std;

/*
 * reverse linked list.
 * NOTE : use of local reference
 */

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};


ListNode* reverseLinkedList (ListNode* head) {
    if (head != 0) {
        ListNode* rest = head->next;
        if (rest == 0) {
            return head;
        }
        //ListNode* new_head = reverseLinkedList (rest);
        ListNode* head_rest = reverseLinkedList (rest);
        //head->next->next = head;
        rest->next = head;
        head->next = 0;
        head = head_rest;
        return head;
    } else {
        return head;
    }
}


ListNode* reverseLinkedList_iterative (ListNode* head) {
    ListNode* currentNode = head;
    ListNode *prevNode = 0;
    while (currentNode!= 0) {
        ListNode *nxtNode =  currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nxtNode;
    }
    //head = currentNode;
    return (prevNode);
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

void reverseLinkedListFromV


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
    int a[] = {1,2,3,4,5};
    int n = sizeof(a)/sizeof(int);
    ListNode* head = create_list (a,n);
    printList(head);
    //head = reverseLinkedList (head);
    head = reverseLinkedList_iterative(head);
    cout << "After reversal " << endl;
    printList(head);
}


