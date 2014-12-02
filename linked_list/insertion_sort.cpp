#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
};


ListNode *insertionSortList(ListNode *head) {
    if(!head) { 
        return head; 
    }
    if(!head->next) { 
        return head; 
    }
    ListNode *sorted = NULL;
    ListNode *list = head;
    while(list)
    {
        ListNode *curr=list;
        list=list->next;
        //std::cout<<"curr->val="<<curr->val<<std::endl;
        if(sorted == NULL || sorted->val > curr->val) //first lookup
        {
            curr->next = sorted; //this indicates the end of sorted list
            sorted = curr;
        }
        else
        {
            // insert somewhere after the fisrt of sorted
            ListNode *tmp = sorted;
            while(tmp)
            {
                ListNode *s=tmp;
                tmp=tmp->next;
                if( s->next == NULL || s->next->val > curr->val)
                {
                    s->next=curr;
                    curr->next=tmp;break;
                }
            }
        }
    }
    return sorted;
}

int main () {

}
