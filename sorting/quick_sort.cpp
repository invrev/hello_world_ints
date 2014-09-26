#include<iostream>
using namespace std;

int swap (int *a,int *b) {
    if (*a != *b) {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
}

//D
int parition (int arr[],int start,int end) {
    int pivot_element = arr[end];
    int pivot_index = -1;
    int huddle_ptr = start;
    while (start < end) {
        if (arr[start] < pivot_element)  {
            swap (arr[huddle_ptr],arr[start]);
            huddle_ptr += 1;
        } 
        start += 1; 
    }
   swap (arr[huddle_ptr],arr[end]);
   return (huddle_ptr);
}

void quick_sort (int arr[],int start,int end) {
    if (start <= end ) {
        int pivot = parition (arr,start,end);
        cout << "pivot index = " << pivot << endl;
        quick_sort (arr,start,pivot - 1);
        quick_sort (arr,pivot + 1,end);
    }
}


void display_array (int arr[],int len) {
    for (int i=0;i<len;i++) {
        cout << arr[i] << " ";
    }
}

int main () {

   int arr_ [] = {22,45,1,99,56,4,55} ;
   int len = 7;
   quick_sort (arr_,0,6);
   cout << endl;
   display_array (arr_,len) ;
   cout << endl;
}
