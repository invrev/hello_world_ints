#include<iostream>
#include<stdlib.h>
using namespace std;

//Merge sort : 
//  1.Trivial Divide 
//  2.Non trivial Merge
//A thing to note in this kind of D&C where we did not depend on the middle element 
//unlike binary search,Quick sort where we use the mid element
typedef struct ll_list {
    int data;
    struct ll_list *next;
}node;

node * create_node (int data) {
   node *sl_node = (node*) malloc (sizeof (node));
   sl_node -> data = data;
   sl_node -> next = 0;
   return (sl_node) ;
}

//Note : we are not adding but appending the node though both are same but semantically different
void append_node (node  **head,int data,node **tail) {
    node *tmp_node;
    tmp_node = create_node (data);
    if (*tail != 0) {
       (*tail) -> next = tmp_node; 
       *tail = tmp_node;
    } else {
        *head =  tmp_node;
        *tail = tmp_node;
    }
}

void traverse_list (node *head) {
    while (head != 0) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

//wrong merge sort 
static int global_cmp_cnt = 0;

void merge (int arr[],int start,int mid,int end) {
        //cout << "start = " << start << " mid = " << mid << " end = " << end << endl;
        node *left_node = 0;
        node *left_tail = 0;
        node *right_node = 0;
        node *right_tail = 0;
        for (int i = start;i < mid;i++) {
            append_node(&left_node ,arr[i],&left_tail);
        }
        for (int i = mid;i < end;i++) {
            append_node(&right_node,arr[i],&right_tail);
        }
       //cout << "first_node_half = " ;
       //traverse_list (left_node);
       //cout << "second_node_half = " ;
       //traverse_list (right_node);
       int index = start;
       for (int i=index;i<end;i++) {
           if ( (left_node != 0) && (right_node != 0) ) {
                if (left_node->data <= right_node->data)  {
                    arr[i] = left_node->data;
                    left_node = left_node->next;
                    global_cmp_cnt += 1;
                } else {
                    arr[i] = right_node->data;
                    right_node = right_node->next;
                    global_cmp_cnt += 1;
                }
           } else {
                //cout << "STILLL REMAIN>>>>>>>>>>>>>>"  << endl;
                while (left_node != 0) {
                    arr[i] = left_node -> data;
                    left_node = left_node -> next;
                }
                while (right_node != 0) {
                    arr[i] = right_node -> data;
                    right_node = right_node -> next;
                }
           }

       }
       //cout << "start = " << start << " mid = " << mid << " end = " << end   << " index = "<< index << endl;
       //copy the right_node part
       //cout << "After merge step the result = " ;
       //for (int i=start;i<end;i++) {
       //    cout << " " << arr[i] << " " ;
       //}
       //cout << endl ;
}

void merge_sort (int arr[],int start,int end,int len) {
    
    int diff = (end - start);
    if ( diff == 1) {
        //cout << "Hit the base case " << endl;
        return ;
    }

    //Divide the array
    if ( start  < end) {
        int mid = (start + end) / 2;
        //A thing to note in this kind of D&C where we did not depend on the middle element 
        //unlike binary search,Quick sort where we use the mid element
        //int* left = merge_sort (arr,start,mid,left_len);
        node *left = 0;
        node *right = 0;
        merge_sort (arr,start,mid,len);
        merge_sort (arr,mid,end,len);
        merge(arr,start,mid,end); //cout << endl;
    }

}

int main () {
    //int arr[] = {3,4,5,1,2,0,7} ;
    //int arr[] = {1,2,3,4} ;
    //int len = 4;
    //int arr[] = {-17} ;
    //int len = 1;

    int arr[] = {-200,200,0,0,0,-200,200,0,0,0 };
    int len = 10;
    merge_sort (arr,0,len,len);

    cout  << "The cmp count = " << global_cmp_cnt << endl;
}
