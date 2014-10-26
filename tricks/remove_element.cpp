#include<iostream> 
using namespace std;

int removeElement(int A[], int n, int elem) {
    int first_index = 0;
    for (int i=0;i<n;i++) {
        if (A[i] == elem) {
            if (first_index == 0) {
                first_index = i;
            } 
            while (A[i] == elem && i < n) {
               i = i + 1;
            }
            //swap first_index and i
            if ( i != n && A[i] != elem ) {
                int tmp = A[i];
                A[i] = A[first_index];
                A[first_index] = tmp;
            } else {
               if (first_index == 0)  {
                first_index = i - 1;
               }
            }
            first_index += 1;
        }
    }
    cout << "total # of elements " <<  (n - first_index) << endl;
    return (n - first_index );
}

int removeElementFromArray (int a[],int n,int elem) {
    
    int ele_start = 0;
    for (int i=0;i<n;i++) {
        if (a[i] != elem)  {
            //Problem : lot of movement if there are very few elements with "elem"
            a[ele_start++] = a[i];
        } 
    }
    cout << "Before len = " << n << ",After len = " << ele_start << endl;
    return ele_start;
}


int removeElementFromArray2 (int a[],int n,int elem) {
    
    int ele_start = 0;
    for (int i=0;i<n;i++) {
        if (a[i] == elem )  {
            while (a[n-1] == elem) {
                n = n-1;
            }
            a[i] = a[n-1];
            n = n - 1;
        } 
    }
    cout << "Before len = " << n << ",After len = " << ele_start << endl;
    return ele_start;
}


int removeElementFromArray3 (int a[],int n,int elem) {

    //WO lot of movement    
    int i = 0;
    while (i < n) {
        if (a[i] == elem) {
            a[i] = a[n-1];
            n = n - 1;
        } else {
            i += 1;
        }
    }
    cout << "Before len = " << n << ",After len = " << i<< endl;
    return i;
}






int main () {
    int a[] = {1,3,3,3,4,3,33};
    int ele = 3;
    //removeElement(a, 3, 3);
    removeElementFromArray (a,7,ele);
    int b[] = {1,3,3,3,4,3,33};
    removeElementFromArray3 (b,7,ele);
}
