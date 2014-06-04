#include<iostream>
#include<stdlib.h>
using namespace std;
//NOTE : 
//1.malloc always return void pointer to allocated heap slab
//2.We have to explictly point to the memory location.
//3.0 = NULL
//h_prev has great importance in case of ll as we cannot go backwards

struct linked_lst {
    int data;
    struct linked_lst *next;
};

typedef struct linked_lst ll;

void create_node(ll **head, int data) {
    ll *ll_node = (ll *) malloc(sizeof(ll));
    ll_node->data = data;
    ll_node->next = 0;
    if (*head == 0) {
        *head = ll_node;
    }else{
      ll_node->next = *head;
      *head = ll_node;
    }

}

void insert_node_ll() {

}

void delete_node_ll() {
}

void traverse_ll (ll *head) {
    cout << "traversing the element" << endl;
    while (head != 0)  {
        cout << head->data << " "; 
        head = head->next;
    }
    cout << endl;
}

void merge_sorted_ll (ll *head1,ll *head2) {
        //1.No interleaving 2.With interleaving
        cout << "Merging the list " << endl;
        ll *tmp_h1 = head1;
        ll *tmp_h2 = head2;
        ll *h_prev1 = 0;
        ll *h_prev2 = 0;
        ll *start_ptr = 0;
        while (head1 != 0 && head2 != 0) {
            if (head1->data <= head2->data ) {
                if (start_ptr == 0) {
                    start_ptr = head1;
                }
                if (h_prev2 != 0 && (h_prev2->data <= head1->data) ) {
                    h_prev2->next = head1; 
                    h_prev2 = 0;
                }
                h_prev1 = head1;
                head1 =  head1->next;
            } else {
                if (start_ptr == 0) {
                    start_ptr = head1;
                }
                if (h_prev1 != 0 && (h_prev1->data <= head2->data) ) {
                    h_prev1->next = head2; 
                    h_prev1 = 0;
                }
                h_prev2 = head2;
                head2 =  head2->next;
            }
        }
        //Last node
        if (head1 == 0 && head2 != 0) {
            h_prev1->next =  head2;

        } else if ( head1 != 0 && head2 == 0) {
            h_prev2 ->next = head1; 
        }
        //Traverse
        traverse_ll (start_ptr);
        cout << "Merge completed." << endl;
}

void reverse_ll (ll *head) {
    ll *h_prev = 0;
    ll *h_next = 0;
    while (head != 0) {
        //1.Get head->next 
        //2.update/get head->next 
        //3.restore the h_prev 
        //4.restore the head 
        h_next = head->next;
        head->next = h_prev; 
        h_prev = head;
        head = h_next; 
    }

    while (h_prev != 0)  {
        cout << h_prev->data  << " ";
        h_prev = h_prev->next; 
    }
    cout << endl;

}


int get_list_count (ll *head1) {
    int lst_count = 0;
    while(head1 != 0) {
        lst_count += 1;
        head1 = head1->next;
    }
    return lst_count;
}

void test_overlapping_list (ll *head1,ll *head2) {
        int l1 = 0;
        int l2 = 0;
        l1 = get_list_count (head1);
        l2 = get_list_count (head2);
        int diff = l1 - l2;
        cout << "diff = " << diff << endl;
        if (diff > 0) {
            while (diff != 0) {
                head1 = head1->next; 
                diff -= 1;
            }
        } else {
            while (diff != 0) {
                head2 = head2->next; 
                diff += 1;
            }
        }

    while (head1 != head2) {
        cout << "head1 = " << head1->data  << "head2 = " << head2->data << endl;
        head1 =  head1->next;
        head2 =  head2->next;
    }
   
   cout << "overlapping node = " << head1 << " and the value = " << head1->data << endl; 

}

void test_for_cyclicity(ll *head) {

    ll *hare = head->next->next;
    ll *tortoise = head->next;

    while ( (hare != 0 || tortoise != 0)  && hare != tortoise) {
        hare = hare->next->next;    
        tortoise = tortoise->next;
    }
    //
    if ( (hare != 0 || tortoise != 0) ) {
        ll *tmp = head;
        cout << "The connection found " << hare  << " and the data is " << hare->data  << endl;
        while (hare != tmp) {
           hare = hare->next; 
           tmp = tmp->next; 
        }
        
        cout << "the start node in the cycle = "  << hare << " and the data = " << hare->data << endl;
        int len = 1;
        hare = hare -> next;
        while (tmp != hare) {
            hare = hare->next; 
            len += 1;
        }
        
       cout << "the length of the cycle  = "  << len << endl;
    
    }

}

//pointer modification code
ll * create_cycle (ll *head5) {
   ll *tmp = head5;
   ll* some_node = head5->next->next->next;
   while (tmp->next != 0) {
        tmp = tmp->next; 
   }
  tmp->next = some_node;
  //return (tmp);
  return (head5);
}


int main () {
    ll *head = 0;
    int arr [] = {1,2,3,4,5};
    for (int i=0;i<2;i++) {
        create_node (&head,arr[i]);
    }

    ll *head1 = 0;
    ll *head2 = 0;
   

    /* Merge list
    //int arr1[] = {1,2,3,4};
    //int arr2[] = {10,20,30,40};
    //int arr1[] = {1,10,15,30};
    //int arr2[] = {2,3,4,11};
    int arr1[] = {1,10,15,30};
    int arr2[] = {2,33,44,55};
    for (int i=3;i>=0;i--){
        create_node(&head1,arr1[i]);
    }
    for (int j=3;j>=0;j--){
        create_node(&head2,arr2[j]);
    }
    traverse_ll (head1);
    traverse_ll (head2);
    merge_sorted_ll (head1,head2);
    */

    /* Test overlapping of the list
    ll *head3 = 0;
    ll *head4 = 0;
    for (int i=3;i>=0;i--){
        create_node(&head3,arr1[i]);
    }
    for (int j=3;j>=0;j--){
        create_node(&head4,arr2[j]);
    }

    traverse_ll (head3);
    traverse_ll (head4);

    ll **tmp_head = 0;
    ll *h_3 = head3;
    tmp_head = &head3;
    while ( (*tmp_head)->next != 0) {
        *tmp_head = (*tmp_head)->next; 
    }
    (*tmp_head)->next = head4;
    //traverse_ll (head3);
    traverse_ll (h_3);
    test_overlapping_list (h_3,head4) ;
    */

    ll *head5 = 0;
    //create the cycle 
    int arr5 [] = {10,2,34,35,36,89,90,91};
    for (int j=0;j <= 8;j++){
        create_node(&head5,arr5[j]);
    }
    ll *cycle_head = create_cycle (head5) ; 
    //test wheather cycle exists or not
    test_for_cyclicity (cycle_head);
    //create_node (&head,12);
    //create_node (&head,14);
    //traverse_ll(head);
    //reverse_ll (head) ;
}


