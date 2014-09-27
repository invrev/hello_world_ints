#include<iostream>
using namespace std;

//On the simillar line of thought using Kanade algorithm we can find 
//the maximum sum from the positive,negative numbers
void get_longest_increasing_substring(int a[],int len) {
    int max_length_so_far = 0;
    int current_length = 0;
    int i = 1;
    int start = 0;
    int end = 0;
    int current = 0;
    int temp_start = 0;
    for (;i<len;i++) {
        int prev = (i - 1);
        if (a[prev] < a[i]) { 
            current = i;
        } else {
           temp_start = i; 
        }
        current_length = (current - temp_start);
        if (max_length_so_far < current_length) {
            //Preserve the history and update only during transition
            max_length_so_far = current_length ;
            start = temp_start;
            end = current;
        }
    }

    cout << "Max length of increasing subsequence = " << max_length_so_far << endl;
    cout << "start_index = "<< start  << " end_index = " << end << endl;

}

int main () {
    int a [] = {5,1,3,4,5,1,3,2} ;
    get_longest_increasing_substring(a,8);

}
