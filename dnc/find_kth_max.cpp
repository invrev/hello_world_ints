#include<iostream>
#include<vector>
using namespace std;


void do_swap(int &a,int &b) {
    //int temp = *a;
    //*a = *b;
    //*b = temp;
    int temp = a;
    a = b;
    b = temp;
}

int partition (vector<int> &vec,int start,int end) {
   int less_than_pivot_index = -1;
   int index_ = 0;
   int pivot_element = vec[end];
   for (index_ = 0; index_ < (end -1) ;index_++) {
       if (vec[index_] < pivot_element ) {
            less_than_pivot_index += 1;
            do_swap (vec[index_],vec[less_than_pivot_index]);
       } 
   }
  do_swap(vec[less_than_pivot_index + 1],vec[end]);
  cout << "less_than_pivot_index = " << less_than_pivot_index  << endl;
  return less_than_pivot_index + 1;
}

void find_kth_maximum (vector<int> &vec,int k,int start,int end) {
    int p = 0; 
    if (k > end) {
        //No element will be found
        cout << "No element found";
    }else {
        p = partition(vec,start,end);
        cout << "position = " << p << endl;
        if (p < k) {
            find_kth_maximum (vec,k,p,end);
        }
        else if (p > k) {
            find_kth_maximum(vec,k,start,p-1);
        } else {
            cout << "The kth element = "<< vec[k] << endl;
        }
    }

}

int main () {
    //int [] input_arr = {4,1,19,2,25,-2}; // In java OK but in c/c++ not ok
    int input_arr[] = {4,1,19,2,25,-2}; //-2,1,2,4,19,25
    vector<int> vec (input_arr,input_arr + sizeof(input_arr)/sizeof(int));
    int end = vec.size();
    //int k_th_element = find_kth_maximum (vec,3,0,end);
    find_kth_maximum (vec,3,0,end-1);
    //cout << "The kth element = "<< k_th_element << endl;
}
