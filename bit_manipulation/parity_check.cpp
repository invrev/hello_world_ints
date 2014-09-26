#include<iostream>
using namespace std;
//compute the parity of 64-bit non negative number
//detects the error 1 if the numbers are 0 
//design and implement algo A, of n elements and returns the begin and end index of the longest increasing sequence
//difference between the sandwitches and grills
//given array with the positive,negative and zero in it and now return the array with order -ve,0,+ve keep the aray stable don't change the order of the elements while moving the -ve numbers


//1.Crux compute the # of zeros and # of ones

int array_ref_swap (int a[],int i,int j) {
    int temp_ = a[i];
    a[i] = a[j];
    a[j] = temp_;
}

int do_swap (int a,int b) {
    cout << "at init a = "<< a << " & b = " << b << endl;
    int temp_ = a; 
    a = b;
    b = temp_;
    cout << "after the swap a = "<< a << " & b = " << b << endl;
}

void print_array (int arr_[],int len_) {
    int i = 0;
    for (;i<len_;i++) {
        //cout << "arr_[" << i << "] = " << arr_[i] << "\n";
        cout <<  arr_[i] << "\t";
    }
}


int lin_search (int arr_[],int key,int len) {
    int i = 0;
    for (;i<len; i++) {
        if(arr_[i] == key) 
        return i;
    }

}


int arrange_array_elements(int arr_[],int len_) {
    int init_pivot = -1; 
    int i = 0;
    while (i < len_) {
        if (arr_[i] <= 0 ) { 
            init_pivot += 1;
            int j = i;
            for (;j>init_pivot;j--){
                int t = j - 1;
                array_ref_swap (arr_,t,j);
            }
        }
        i += 1;
    }
    //NOTE : position for the zero is the init_pivot
    cout << "pivot position = " << init_pivot << endl;
    init_pivot += 1;
    int pos_zero = 0;
    pos_zero = lin_search (arr_,0,len_) ;
    int k = 0;
    if (pos_zero < init_pivot) {
       for (k=pos_zero;k<init_pivot;k++) {
            int t1 = k + 1;
            array_ref_swap (arr_,k,t1);
       }
    } else {
       for (k= (init_pivot - 1);k>pos_zero;k--){
            int t1 = k - 1;
            array_ref_swap (arr_,k,t1);
       }
    }

    print_array(arr_,len_);
}



//int main () {
//    //int arr_ [] = {1,2,3,5,0,-1,-2,-3};
//    int arr_ [] = {1,-20,0,-11,2,-3,5,22};
//    int len_ =  8;
//    print_array (arr_,len_);
//    cout << endl;
//    do_swap (10,12);
//    //array_ref_swap (arr_,5,6);
//    print_array (arr_,len_);
//    cout << endl;
//    arrange_array_elements (arr_,len_);
//    cout << endl;
//}


void compute_nos_of_ones(int test_no) {
    int cnt_ = 0;
    int copy_no = test_no;
    while (test_no != 0 ) {
        test_no = test_no & (test_no - 1) ;
        cnt_ += 1;
    }
    cout <<  "total # of 1s for # = "<< copy_no <<" is " << cnt_ << endl ;
}


int main () {
    compute_nos_of_ones (7);
}
