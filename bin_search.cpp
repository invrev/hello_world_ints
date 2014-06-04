#include<iostream>
using namespace std;

/*
   Binary search 

   Things to note 
   @ mid location
   start <= mid <= end
   Also
   mid < (start + end)
   as mid = (start + end) / 2;
   So to avoid overflow
   mid = (end-start) + start / 2;
   
*/
int bin_search_rec_bound (int a[],int key,int start,int end) {
    int mid;    
    bool is_found = false;
    if(start <= end) {
        //TO avoid overflow error
        //mid = (start + end) / 2; 
        mid = start + ((end-start) / 2); 
        if (a[mid] == key) {
            is_found = true;
            return mid;
        }
        if (a[mid] < key) {
            return (bin_search_rec_bound(a,key,mid+1,end)) ;
        }
        else if (a[mid] > key) {
            return (bin_search_rec_bound(a,key,start,mid-1));
        }
    } else {
        return start;
    }

}


void bin_search_rec (int a[],int key,int start,int end) {
    int mid;    
    bool is_found = false;
    if(start <= end) {
        //TO avoid overflow error
        //mid = (start + end) / 2; 
        mid = start + ((end-start) / 2); 
        if (a[mid] == key) {
            is_found = true;
            cout << "key found at location "  << mid << endl;
            //return true;
        }
        else if (a[mid] < key) {
            bin_search_rec(a,key,mid+1,end) ;
        }
        else if (a[mid] > key) {
            bin_search_rec(a,key,start,mid-1);
        }
    } else {
        cout << "key not found" << endl;   
    }

}

void bin_search_iterative(int a[],int key,int start,int end) {
    int mid = (start+end)/2;
    //check mid bounds
    while (a[mid] != key && mid >= start && mid < end ) {
        if (a [mid] > key ) {
            mid =  ( start + (mid - 1) )/2;
        } else {
            mid =  ( (mid+1) + end )/2;
        }
    }

    if ( a[mid] == key) {
        cout << "Found element = "<< key <<" at the position = " << mid << endl;
    } else {
        cout << "element = " << key  << " did not find." << endl;
    }
}



int main () {
    int a[] = {1,1,2,3,4,4,4,5,6,23,23,23,89,89};
    int key = 3;  
    //cout << "searching key = " << key << endl;
    //bin_search_rec(a,key,0,5);
    //
    //cout << "searching key = 8" << endl;
    //bin_search_rec(a,8,0,8);
    //
    //cout << "searching key = 1" << endl;
    //bin_search_rec(a,1,0,1);

    //cout << "searching key = 6" << endl;
    //bin_search_rec(a,6,0,6);


    cout << "bin_search_rec_bound () key = 1 location = " << bin_search_rec_bound(a,1,0,9)  << endl;
    cout << "bin_search_rec_bound () for key = 23 location = " << bin_search_rec_bound(a,23,0,14)  << endl;
    cout << "bin_search_iterative() for key = 89" << endl;
    bin_search_iterative(a,89,0,14); 

    return 0;
}
