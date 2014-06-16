#include<iostream>
using namespace std;

void swap(int arr[],int i,int j) {
    int temp = arr [i];
    arr[i] = arr[j];
    arr[j] = temp;
}


void seperate_out_one_and_zero (int arr[],int len) {
    int i = 0; 
    int start = -1;
    int end = -1;
    while (i < len)  {
       if (arr[i] == 0 && start == -1)  {
           start = i;
           //end = i;
       } 
       //else if (arr[i] == 0) {
       //   end += 1; 
       //}
       else if (arr[i] == 1) {
           //found 1
           if (start != -1) {
               swap (arr,i,start);
               start += 1; 
           }
       }
       i =  i + 1;
    }
}

void print_arr (int arr[],int len) {
    for (int i=0;i<len;i++) {
        cout << arr[i] << "," ;
    }
    cout << endl;
}

int main () {

    //int arr[] = {1,0,0,1,0,1,0,0,1,1,1};
    //int arr[] = {1,0,1,1,1,1,1,0,1,1,1};
    int arr[] = {0,0,1,1,1,1,1,0,1,1,1};
    seperate_out_one_and_zero (arr,11);
    print_arr (arr,11);

}
