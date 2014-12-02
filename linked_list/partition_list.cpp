#include<iostream>
using namespace std;

//use of sentinel nodes
ListNode *partition(ListNode *head, int x) {
          ListNode *lh = new ListNode (0), *rh = new ListNode (0);
    ListNode *lt = lh, *rt = rh; 
    ListNode *ret = head; 
    while(head)
    {
        if(head->val < x) {
            lt = lt->next = head;
        }
        else {
            rt = rt->next = head;
        }
        head = head->next;
    }
    lt->next = rh->next;
    rt->next = 0;
    ret = lh->next;
    delete lh;
    delete rh;
    return ret;
}

public ListNode partition(ListNode head, int x) {
        ListNode cur=head;
        ListNode smaller_sentinel=new ListNode(0);
        ListNode smaller_cur=smaller_sentinel;
        ListNode larger_sentinel=new ListNode(0);
        ListNode larger_cur=larger_sentinel;
//Now, go along the list, partitioning into two halves.        
        while(cur!=null){
            if(cur.val<x){
                    smaller_cur.next=cur;
                    smaller_cur=smaller_cur.next;

            }else{
                    larger_cur.next=cur;
                    larger_cur=larger_cur.next;
            }
            cur=cur.next;
        }
//Now, do the concatenation of two havles. Make sure the last node points to null 
        larger_cur.next=null;
        smaller_cur.next=larger_sentinel.next;
        return smaller_sentinel.next;
}

int main () {

}
