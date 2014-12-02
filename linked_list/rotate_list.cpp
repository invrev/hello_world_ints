#include<iostream>
using namespace std;


//My solution has O(n) time complexity and O(1) memory. The basic idea is to connect the list into a circle. First, count the length of list while going through the list to find the end of it. Connect the tail to head. The problem asked to rotate k nodes, however, now the tail is at the end of the list and its difficult to move backward, so move (k - len) nodes along the list instead. "k = k % len" saves the unnecessary moves because rotate a list with length = len by len times doesn't change the list at all.

ListNode *rotateRight(ListNode *head, int k) {


    if (head == NULL || head->next == NULL || k == 0)  {
        return head;
    }
    int len = 1;
    ListNode *tail = head;

    /* find the end of list */
    while (tail->next != NULL) {
        tail = tail->next;
        len++;
    }

    /* form a circle */
    tail->next = head;
    k = k % len;
    for (int i = 0; i < len - k; i++) {
        tail = tail->next;
    }
    head = tail->next;
    tail->next = NULL;
    return head;
}


ListNode *rotateRight(ListNode *head, int k) {

  if (head == NULL || head->next == NULL || k == 0) {
         return head;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* newHead;
    for (int i = 0; i < k; i++) {
        if (fast->next == NULL) {
            fast = head;
        } else {
            fast = fast->next;
        }
    }
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    fast->next = head;
    newHead = slow->next;
    slow->next = NULL;
    return newHead;
}

int main () {

}
