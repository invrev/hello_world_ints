// ============================================================================ 
// UBList.cpp
// ~~~~~~~~~~
// hqn
// - implement the UBList interface
// ============================================================================ 

#include <cstddef> // this header defines NULL
#include <iostream>
#include <stdexcept>
#include <sstream>

#include "UBList.h"

using namespace std; // BAD PRACTICE

UBList::UBList(Node* h, size_t n) : head(h), numNodes(n)
{
}

UBList::UBList(const UBList& theOther)
{
    Node* cur;
    head = NULL;
    numNodes = 0;
    Node* ptr = theOther.head;
    while (ptr != NULL) {
        numNodes++;
        if (head == NULL) {
            cur = head = new Node(ptr->key);
        } else {
            cur->next = new Node(ptr->key);
            cur = cur->next;
        }
        ptr = ptr->next;
    }
}

void UBList::swap(UBList& theOther)
{
    std::swap(numNodes, theOther.numNodes);
    std::swap(head, theOther.head);
}

UBList& UBList::operator=(const UBList& theOther)
{
    UBList temp(theOther); // deep copy
    swap(temp);
    return *this;
}

UBList::~UBList() 
{
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void UBList::insert(int x)
{
    head = new Node(x, head);
    numNodes++;
}

string UBList::toString()
{
    ostringstream oss;
    oss << "[" << numNodes << " NODES] : ";
    Node* ptr = head;
    while (ptr != NULL) {                                                       
        oss << ptr->key << " ";                                                
        ptr = ptr->next;                                                        
    }                                                                           
    return oss.str();
}

bool UBList::isSorted()
{
    for (Node* ptr = head; ptr != NULL && ptr->next != NULL; ptr = ptr->next)
        if (ptr->key > ptr->next->key) 
            return false;
    return true;
}

void UBList::merge(UBList& theOther)
{
    if (!this->isSorted() || !theOther.isSorted())
        throw runtime_error("Give give me sorted lists to merge");

    if (theOther.head == NULL) 
        return;
    if (head == NULL) {
        swap(theOther);
        return;
    }
        
    // both ptr1 and ptr2 are not NULL
    Node* ptr1 = head;
    Node* ptr2 = theOther.head;

    Node* new_tail;
    if (ptr1->key <= ptr2->key) {
        new_tail = head;
        ptr1 = ptr1->next;
    } else {
        new_tail = head = ptr2;
        ptr2 = ptr2->next;
    }

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->key <= ptr2->key) {
            new_tail = new_tail->next = ptr1;
            ptr1 = ptr1->next;
        } else {
            new_tail = new_tail->next = ptr2;
            ptr2 = ptr2->next;
        }
    }

    if (ptr1 != NULL) {
        new_tail->next = ptr1;
    } else if (ptr2 != NULL) {
        new_tail->next = ptr2;
    } else {
        new_tail->next = NULL;
    }

    numNodes += theOther.numNodes;
    theOther.head = NULL;
    theOther.numNodes = 0;
}

void UBList::remove(int x)
{
    Node* prev = NULL;
    Node* cur = head;
    while (cur != NULL) {
        if (cur->key == x) {
            numNodes--;
            if (prev == NULL) { // this means cur == head
                head = head->next;
                delete cur;
                cur = head;
            } else {
                prev->next = cur->next;
                delete cur;
                cur = prev->next;
            }
            continue;
        }
        prev = cur;
        cur = prev->next;
    }
}

void UBList::sort()
{
    if (head == NULL || head->next == NULL)
        return;

    Node* mid = head;
    for (size_t i=1; i < numNodes/2; i++) 
        mid = mid->next;
    Node *b_head = mid->next;
    mid->next = NULL;

    size_t b_nn = numNodes - numNodes/2;
    numNodes = numNodes/2;
    sort();
    UBList b(b_head, b_nn);
    b.sort();
    merge(b);
}
