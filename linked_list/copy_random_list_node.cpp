#include<iostream>
using namespace std;


struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };


RandomListNode *copyRandomList(RandomListNode *head) {
    if(head == NULL) { 
        return NULL;
    }
    RandomListNode *p = head;
    do {
        RandomListNode *q = p->next;
        p->next = new RandomListNode(p->label);
        p->next->next = q;
        p = q;
    } while(p != NULL);

    //while (p != NULL ) {
    //    RandomListNode *q = p->next;
    //    p->next = new RandomListNode(p->label);
    //    p->next->next = q;
    //    p = q;
    //}
    
    p = head;
    
    //while ( p!= NULL) {
    //    if (p->random == NULL) {
    //        p->next->random = NULL;
    //    } else {
    //        p->next->random = p->random->next;
    //    }
    //  p = p->next->next;
    //}
    do {
        p->next->random = (p->random == NULL) ? NULL : p->random->next;
        p = p->next->next;
    } while(p != NULL);
    
    p = head;
   
    RandomListNode *r = head->next;
    for(RandomListNode *q = r;;) {
        p->next = q->next;
        p = p->next;
        if(p == NULL) break;
        q->next = p->next;
        q = q->next;
    }
    return r;
}


//Use of defnsive coding
RandomListNode *copyRandomList(RandomListNode *head) {

    //copy the next to new node
      for (RandomListNode *pNode = head; pNode != NULL; pNode = pNode->next->next) {
            RandomListNode *newNode = new RandomListNode(pNode->label);
            newNode->next = pNode->next;
            pNode->next = newNode;
        }
      for (RandomListNode *pNode = head; pNode != NULL; pNode = pNode->next->next) {
            if (pNode->random != NULL)
                pNode->next->random = pNode->random->next;
      }
      RandomListNode *dumb = new RandomListNode(0);
      RandomListNode *last = dumb;
      for (RandomListNode *pNode = head; pNode != NULL; pNode = pNode->next) {
            last->next = pNode->next;
            last = last->next;
            pNode->next = pNode->next->next;
            last->next = NULL;
      }
    return dumb->next;
 }
//Using the hash map 
//First I go through the list and make new one with same data. At the same time I'm mapping previous and new pointers to node. After that I just run through the list again and just assign the random pointers from hash to the new list.

RandomListNode *copyRandomList(RandomListNode *head) {
    if (head == NULL) return NULL;
    RandomListNode * hh = new RandomListNode(head->label);
    RandomListNode * ret = hh;
    RandomListNode * cur = head;
    unordered_map<RandomListNode*, RandomListNode*> pmap;
    pmap[head] = hh;
    while(cur->next) {
        cur = cur->next;
        hh->next = new RandomListNode(cur->label);
        hh = hh->next;
        pmap[cur] = hh;
    }
    cur = head;
    while(cur) {
        if(pmap.count(cur)) {
            hh = pmap[cur];
            if (cur->random && pmap.count(cur->random)) {
                hh->random = pmap[cur->random];
            }
        }
        cur = cur->next;
    }
    return ret;
}









