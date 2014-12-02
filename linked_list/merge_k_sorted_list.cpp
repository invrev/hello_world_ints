#include<iostream>
#include<vector>
//#include<algorithm>
#include<queue>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct CompareNode {
    bool operator()(ListNode* const & p1, ListNode* const & p2) {
        // return "true" if "p1" is ordered before "p2", for example:
        return p1->val > p2->val;
               //Why not p1->val <p2->val; ??
    }
};



ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode dummy(0);
    ListNode* tail=&dummy;
    
    priority_queue<ListNode*,vector<ListNode*>,CompareNode> queue;

    //Use of auto
    for (vector<ListNode *>::iterator it = lists.begin(); it != lists.end(); ++it){
        if (*it) {
            queue.push(*it);
        }
    }
    while (!queue.empty()){
        tail->next=queue.top();
        queue.pop();
        tail=tail->next;

        if (tail->next){
            queue.push(tail->next);
        }
    }

    return dummy.next;
}

//Using divide and conquer

public ListNode mergeKLists(List<ListNode> lists) {
        int length = lists.size() ;

        if(length == 0)
            return null ;
        if(length == 1){
            return lists.get(0) ;
        }

        int mid = (length - 1)/2 ;
        ListNode l1 = mergeKLists(lists.subList(0,mid + 1)) ;
        ListNode l2 = mergeKLists(lists.subList(mid + 1,length)) ;

        return mergeTowLists(l1,l2) ;

    }

    public ListNode mergeTowLists(ListNode l1 , ListNode l2){
        ListNode result = new ListNode(0) ;
        ListNode list = result ;
        while(l1 != null && l2 != null){
            if(l1.val < l2.val){
                list.next = l1 ;
                l1 = l1.next ;
            }else{
                list.next = l2 ;
                l2 = l2.next ;
            }
            list = list.next ;
        }

        while(l1 != null){
            list.next = l1 ;
            l1 = l1.next ;
            list = list.next ;
        }

        while(l2 != null){
            list.next = l2 ;
            l2 = l2.next ;
            list = list.next ;
        }

        return result.next ;
}



struct NodeCmp {
        bool operator()(ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
};
ListNode *mergeKLists(vector<ListNode *> &lists) {
    vector<ListNode*> vec;
    for (int i = 0; i < lists.size(); i++) {
        if (lists[i]) {
            vec.push_back(lists[i]);
            //lists[i] = lists[i] -> next;
        }
    }
    make_heap(vec.begin(), vec.end(),NodeCmp());
    ListNode *result = new ListNode(0);
    ListNode *cur = result;
    
    while (!vec.empty()) {
        ListNode* min= vec.front();
        //move the element to last
        pop_heap(vec.begin(),vec.end(),NodeCmp());
        vec.pop_back();
        cur->next = min;
        //cur = cur->next;
        cur = min;
        // add next element from list to heap if it's not null
        if(cur->next) {
            vec.push_back(cur->next);
            push_heap(vec.begin(), vec.end(), NodeCmp());
        }
    }
    return result->next;
}





int main () {

}
