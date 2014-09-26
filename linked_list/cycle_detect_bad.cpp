#include<iostream>

//Too bad

struct ListNode {
    int val;
    struct ListNode *next; 
}

ListNode *detectCycle(ListNode *head) {
       if (head == 0 || head->next == 0) {
            return 0;
        } else {
            ListNode *hare = head;
            ListNode *tortoise = head;
            ListNode *tmpNode = head;
            int flag = 1;
            while (tortoise != 0 && 
                    hare != 0) {
                 //move tortoise to next level
                tortoise = tortoise->next;
                if (hare->next != 0 && hare->next->next != 0) { 
                    hare = hare->next->next;
                }else {
                    return 0;
                }
                if (tortoise == hare) {
                    flag = 0;
                    break;   
                }
            }
            if (flag == 0 ) {
                while (tmpNode != tortoise) {
                    tmpNode = tmpNode->next;
                    tortoise = tortoise->next;
                }
                return tmpNode;
            } else {
                return 0;
            }
        }
}

int main () {

}

