#include<iostream>
using namespace std;
//single number I,II

//Idea :  compute the # of 1's for all positions of the given numbers O(32*n)
//Generalized solution for finding #'s with repeated 2,3,..n times.
int singleNumber(int A[], int n) {
    int count[32] = {0};
    int result = 0;
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < n; j++) {
            if ((A[j] >> i) & 1) {
                count[i]++;
            }
        }
        result |= ((count[i] % 3) << i);
    }
    cout << "the number repeated twice  = "  << result  << endl;
    return result;
}


//O(n)
int singleNumber1(int A[], int n) {
    int ones = 0, twos = 0, threes = 0;

    for (int i = 0; i < n; i++) {
        twos |= ones & A[i];
        ones ^= A[i];
        threes = ones & twos;
        ones &= ~threes;
        twos &= ~threes;
    }

    cout << "the number repeated twice  = "  << ones << endl;
    return ones;
}


int singleNumber2(int A[], int n) {
    
    //index of no_of_ones array represent bit position
    int size_of_bit_vec = (sizeof(int) * 8);
    int bit_vec_for_no_of_ones[(sizeof(int) * 8)] = {0};
    //Note the base case 0,0,1,1,1 i.e. # of zeros = 2 is already handled here 
    int result = 0;
    for (int i=0;i<size_of_bit_vec;i++) {
        //get the each bit from the int
        for (int j=0;j<n;j++) {
           if ( (A[j] >> i) & 1)  {
                bit_vec_for_no_of_ones[i] += 1;
           }
        }
    }
    for (int i=0;i< size_of_bit_vec;i++)  {
        result |= ((bit_vec_for_no_of_ones[i] %3) << i);
    }
    //cout << "the number repeated twice  = "  << result/2 << endl;
    return result/2 ;
}




int main () {
    //only 3 appeared twice
    int input_arr[]  = {1,1,103,5,5,5,4,4,100,10,10,10,1,103,103,100,4};
    int n = 17;
    //singleNumber1 (input_arr,17);
    //singleNumber (input_arr,17);
    singleNumber2 (input_arr,17);
    //int is represented by 32 bits
    //int no_of_ones[32] = {0};
    ////Note the base case 0,0,1,1,1 i.e. # of zeros = 2 is already handled here 
    //int result = 0;
    //for (int i=0;i<32;i++) {
    //    //get the each bit from the int
    //    for (int j=0;j<n;j++) {
    //       if ( (input_arr[j] >> i) & 1)  {
    //            no_of_ones[i] += 1;
    //       }
    //    }
    //    //result |= ((no_of_ones[i] %3) << i);
    //}

    //for (int i=0;i< 32;i++)  {
    //    result |= ((no_of_ones[i] %3) << i);
    //}
    //cout << "the number repeated twice  = "  << result/2  << endl;

}
