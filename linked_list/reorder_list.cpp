#include<iostream>
using namespace std;

void reorderList(ListNode *head) {
  if (head == NULL || head->next == NULL)  {
    return;
  }
    ListNode* slow = head;
    ListNode* fast = head;
    // Find the middle node using the '2-pointer' technique
    while (fast->next!=NULL)
    {
        slow = slow -> next;
        fast = fast -> next;
        if (fast->next!=NULL) fast = fast -> next;
    }

    // Reverse the second half
    ListNode* prev = slow;
    ListNode* cur = slow -> next;
    ListNode* next; 
    while (cur != NULL)
    {
        next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next;
    }
    slow -> next = NULL; // The middle node should point to null

    // Reorder the list
    // prev and cur are approaching the middle node 
    // from the two ends of the linked list
    cur = prev;
    prev = head;
    while (prev!=cur)
    {
        next = prev->next;
        prev -> next = cur;
        prev = cur;
        cur = next;
    }
}

int main () {

}
