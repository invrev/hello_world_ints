#include<iostream>
using namespace std;

//Use of bit vectors
void storeBitVec () {
    //can store upto 400*8 numbers
    char bitV [400] = {0};
    
    int input[] = {100,502,505,510,1000};

    //store the input in the bit vector
    int l = sizeof(input)/sizeof(input[0]);

    for (int i=0;i<l;i++) {
        //find the bucket from bitV
        int bucketNo = input[i]/8;
        //Find the offset
        int offset = input[i] % 8;
        
        //Set the number
        bitV[bucketNo] |= (1 << offset);
    }

    //iterate over the buckets /bit vector
    int m = sizeof(bitV)/sizeof(bitV[0]);
    for (int i=0;i<m;i++) {
        char t = bitV[i];
        int BIT_SIZE = sizeof(char) * 8;
        //print the set number
         for (int j=BIT_SIZE;j>=0;j--) {
             //Using and operation find the set bit position 
             if (t & (1<<j)) {
                 cout << (i * BIT_SIZE) + j << endl;
             }
         }
    }

}

//Used to check the parity chop off 1 bit at a time
int checkNumberOfOnes(int x) {
    int count = 0;
    while (x != 0) {
        x = (x & (x-1));
        count++;
    }
    return count;
}

//To check wheather the number is power of 2
bool isPowerofTwo (int x) {
    return ( (x & (x-1)) == 0);
}

int mask () {
    
    int mask = -1;
    int cnt = 0;
    while (mask != 0) {
        mask = mask & (mask - 1);
        cnt++;
    }
    cout << "mask = "  << cnt << endl;

    
    mask = ~0;
    cnt = 0;
    while (mask != 0) {
        mask = mask & (mask - 1);
        cnt++;
    }
    cout << "mask with TLDE = "  << cnt << endl;
}

void clearBit (int x,int i) {
    cout << "B4 clear bit = " << x  << " bit # " << i << endl;
    int mask = ~(1 << i);
    x = (x & mask);
    cout << "After clear bit = " << x  << " bit # " << i << endl;
}

void setBit (int x,int i) {
    cout << "B4 set bit = " << x  << " bit # " << i << endl;
    int mask = (1 << i);
    x = (x | mask);
    cout << "After clear bit = " << x  << " bit # " << i << endl;
}

void whichEndian () {
    int i = 1;
    char *add = (char*)&i;
    if (add[0] == 1) {
        cout << "Big endian" << endl;
    } else {
        cout << "Little endian" << endl;
    }
}

//Used for bit rerversal operation
void createEvenOddMask(bool isEven) {
    //generate mask 1010101010 and 01010101
    int size_ = sizeof(int) * 8;
    int i = 1;
    int mask = 0;
    while (i <= size_) {
        if  ( (size_ % 2) == 0  && isEven) {
            mask |= (1 << i); //1010
        } else if (isEven == false && (size_ % 2) != 0 ) {
            mask |= (1 << i); //01010101
        }
       i++; 
    }
}



void test (int x) {
    if (isPowerofTwo(x) == true) {
        cout << "the # = " << x << " is power of 2" << endl;
    } else {
        cout << "the # = " << x << " is not power of 2" << endl;
    }
    cout <<  "# of 1s for " << x << " = " << checkNumberOfOnes (x) << endl;
    mask ();
    //Use of tilde operation
    // ~(0) == -1
    cout << "# n = "  << x << " complement = " << ~(x) << endl;

    clearBit (9,1);
    clearBit (7,2);
    clearBit (15,3);
}

int main () {
    storeBitVec();
    whichEndian();
    test(4);
    test(8);
    test(9);

    int i = 7;

    i = (i << 2);
    cout << "the after 7 " << i << endl;
    i -= 1;
    cout << "the after 7 " << i << endl;
    

}
