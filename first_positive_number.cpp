#include<iostream>
using namespace std;
#define BIT_MAP_LEN 15
#define BYTE_LEN 8

//Can not provide good interface while accessing the data
//typedef struct bt_result {
//    int storage[10] = {0,0,0,0,0,0,0,0,0};
//}bt_result;

//Works only upto 32 +ve numbers
int firstMissingPositive(int A[], int n) {
    int storage = 0;
    //bt_result *b_storage;
    
    unsigned char bit_map_struct[BIT_MAP_LEN] = {0};
    int pri_index = 0;
    int sec_shift_index = 0;
    int min_number = A[0];
    if (min_number < 0) {
        min_number = 9999;
    } else {
        //storage =  (1 << min_number);
        pri_index = min_number / 8;
        sec_shift_index  = min_number % 8;
        bit_map_struct[pri_index] = 1 << sec_shift_index;
    }
    for (int i=1;i<n;i++)  {
        int index = A[i];
        if (min_number > index && (index >= 0)) {
            min_number = index;
        }
        if (index >= 0) {
            //storage |= no_;
            //int no_ = 1 << (index % 32) ;
            //bit_map_struct[ (1 << index) ] = 1;
            pri_index = index / 8;
            sec_shift_index  = index % 8;
            bit_map_struct[pri_index] |= 1 << sec_shift_index;
        }
    }
    //cout << "the value at min numner = " << bit_map_struct[min_number];
    //for (int i=0 ; i<BIT_MAP_LEN; i++) {   
    //    for(int j=0; j<BYTE_LEN; j++) {
    //        if(bit_map_struct[i] & (1 << (j))) {
    //            int cd_idx = (i+j);
    //            cout << "bit set at the position = " << cd_idx << endl;
    //        }
    //    }
    //}


    //int result = storage >> (min_number);
    //cout << "result = " << result << endl;
    int pri_indx = min_number / 8;
    int sec_shift_indx = min_number % 8;
    while (bit_map_struct[pri_indx] & (1 << sec_shift_indx) ) {
            sec_shift_indx += 1;
            min_number += 1; 
            if (sec_shift_indx == 8 ) {
                sec_shift_indx = 0;
                pri_indx += 1;
            }
    }
    //while (result != 0) {
    //    if ( (result & 1) == 0) {
    //        return min_number;
    //    }
    //    result = result & (result - 1);
    //    result = result >> 1;
    //    min_number += 1;
    //}
    return (min_number);
}

int main () {
    //int A[] = {0,2,1};
    //int A[] = {3,4,-1,1};
    //int missing_no = firstMissingPositive(A,4);
    //int missing_no = firstMissingPositive(A,3);
    int A[] = {99,94,96,11,92,5,91,89,57,85,66,63,84,81,79,61,74,78,77,30,64,13,58,18,70,69,51,12,32,34,9,43,39,8,1,38,49,27,21,45,47,44,53,52,48,19,50,59,3,40,31,82,23,56,37,41,16,28,22,33,65,42,54,20,29,25,10,26,4,60,67,83,62,71,24,35,72,55,75,0,2,46,15,80,6,36,14,73,76,86,88,7,17,87,68,90,95,93,97,98};
    int missing_no = firstMissingPositive(A,100);
    cout << "the first + missing no " << missing_no << endl;
}


