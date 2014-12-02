#include<iostream>

using namespace std;

//Move pointers upto m and then reverse m and n

ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *prev = NULL;
        ListNode *tail = head;
        int move = m - 1;
        while (move-- > 0) {
            prev = tail; tail = tail->next;
        }

        int num = n - m;
        ListNode *front = tail;
        while (num-- > 0) {
            ListNode *tmp = tail->next;
            tail->next = tmp->next;
            tmp->next = front;
            front = tmp;
            if (prev) prev->next = front;
        }
        if (prev) {
            return head;
        } else {
            return front;
        }
        //return prev ? head : front;
 }

//Use of pseudo node

ListNode *reverseBetween(ListNode *head, int m, int n) {
    if(m==n)return head;
    n-=m;
    ListNode prehead(0);
    prehead.next=head;
    ListNode* pre=&prehead;
    while(--m)pre=pre->next;        
    ListNode* pstart=pre->next;
    while(n--)
    {
        ListNode *p=pstart->next;
        pstart->next=p->next;
        p->next=pre->next;
        pre->next=p;
    }
    return prehead.next;
}

//  Main Idea is:
//(1) find the m-1_th node first, if m=1
//, we use a dummy node (2) move node m+1, m+2, ... , n to position m sequentially (totally n-m times)

ListNode *reverseBetween(ListNode *head, int m, int n) {
        //1 ≤ m ≤ n ≤ length of list.
        if(head==NULL) return NULL;
        if(head->next==NULL||m==n) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode *pmNd = &dummy, *mNd,  *cur, *nxt;

        for(int cnt=0; pmNd && cnt<m-1; cnt++, pmNd=pmNd->next){} //find m-1_th node, record it as pmNd
         //assert( pmNd && pmNd->next ); //o.w. list too short
        mNd = pmNd->next; //get the position of the m_th node
        cur = mNd->next; //reversing from m+1_th node

        int rv;
        for(rv=n-m;  cur && rv;  rv-- ){ //need to reverse n-m times
            nxt = cur->next;

            mNd->next = cur->next; //take off node cur from it's predecessor (which is always m_th node)
            cur->next = pmNd->next; // insert node cur after the m-1_th node 
            pmNd->next = cur; 

            cur = nxt; //move to next unprocessed node
        }
        //assert(rv==0); //o.w. list too short

        return dummy.next;
}





int main () {
    
}
