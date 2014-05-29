#include<iostream>
using namespace std;

void do_swap  (char *a,char *b) {
    char *tmp = a;
    a = b;
    b = tmp;
}

//Recursive solution
void in_place_rec_movement (char arr[],int start,int end) {

        while (start < end)  {
           //do_swap (arr[start],arr[end]);
           char tmp = arr[start];
           arr[start] = arr[end];
           arr[end] = tmp;
           start++;
           end--;
        }

}

//Iterative solution
void in_place_movement (char arr[],int n,int k) {
        //NOTE : can select any element from 0 to n as start_pivot
        //int start_pivot = 3;
        int start_pivot = 0;
        int next_point = (start_pivot + k) % n;
        int prev_point = start_pivot; 
        char prev_value = arr[prev_point];
        char next_value;
        while (start_pivot != next_point)  {
            //store the next value
            next_value = arr[next_point];
            //replace the next value 
            arr[next_point] = prev_value;
            //restore the next value
            prev_value = next_value;
            //Update the prev_point and next_point
            prev_point = next_point;
            next_point = (next_point + k) % n;
        }
    //Last element copy  
    arr[next_point] = prev_value;

    for (int i=0;i<n;i++) {
        cout << arr[i]  << " ";
    }
    cout << endl;
}

int main () {

    char arr_[] = {'a','b','c','d','e','f','g'};
    int len = 7;
    int k = 3;
    //in_place_movement (arr_,len,k);

    in_place_rec_movement (arr_,0,len-1);
    in_place_rec_movement (arr_,0,k-1);
    in_place_rec_movement (arr_,k,len-1);


    for (int i=0;i<len;i++) {
        cout << arr_[i]  << " ";
    }
    cout << endl;

}
