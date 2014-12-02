#include<iostream>
using namespace std;


//Please refer sort list 
ListNode* find_mid(ListNode *head) {
    ListNode *p1, *p2, *p=NULL;
    
    p1 = p2 = head;

    while (p1!=NULL && p2!=NULL && p2->next!=NULL) {
        p = p1;
        p1 = p1->next;
        p2 = p2->next->next;
    }
    if (p != NULL) {
        p->next = NULL;
    }
    return p1;
}

TreeNode *sortedListToBST(ListNode *head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        return new TreeNode(head->val);
    }
    ListNode *pMid = find_mid(head);
    TreeNode *pTreeNode = new TreeNode(pMid->val);
    pTreeNode->left = sortedListToBST(head); //n
    pTreeNode->right = sortedListToBST(pMid->next); //n - n/2 -1

    return pTreeNode;
}



TreeNode *helper(ListNode *head, ListNode *tail) {
        if (head == NULL) { 
            return NULL; 
        }
        ListNode *n1 = head;
        ListNode *n2 = head;
        while (n2 != tail && n2->next != tail) {
            n1 = n1->next;
            n2 = n2->next->next;
        }
        TreeNode * tn = new TreeNode(n1->val);
        if (head == n1) {
            tn->left = helper(NULL,n1);
        } else {
            tn->left = helper(head,n1);
        }
        //tn->left = helper((head == n1) ? NULL : head, n1);
        if (tail == n1->next) {
            tn->right = helper(NULL,tail);
        } else {
            tn->right = helper(n1->next, tail);
        }
        //tn->right = helper((n1->next == tail) ? NULL : n1->next, tail);
        return tn;
    }

TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL) { 
            return NULL; 
        }
        return helper(head, NULL);
}


int main () {

}
