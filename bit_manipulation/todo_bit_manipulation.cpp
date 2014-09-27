#include<iostream>
#include<string>
#include <algorithm>

using namespace std;
//shift operation
//How number is represented in c (positive/negative (2's complement))
// 1 all 0's 1
// -1 all 1's
//Note there is unsigned and signed number exits
//Bydefault it is signed

/*
   Bit Manipulation
   signed vs unsigned type representation
    
   Only one 1 at the LSB 
   unsigned int i = 1
   All 1's
   unsigned int i = -1 

   
*/

static void check_dandc (int num1,int num2) {

}

static void print_bin(int n) {
	int s = sizeof(int) * 8;
        //To print big endian store in string and then reverse
        string bin_rep = "";

	while (s) {
		if (n & 1) {
                    //cout <<"1";
                    bin_rep += "1";
                }
		else {
                    //cout <<"0";
                    bin_rep += "0";
                }
		n >>= 1;
		s--;
	}
	cout << bin_rep << endl;
        //reverse(bin_rep.begin(), bin_rep.end());
        //cout << bin_rep << endl ;
}

static void detect_opp_sign() {
	int x= 34 , y = -23;               // input values to compare signs
	print_bin(x);
	print_bin(y);
	if ((x ^ y) < 0) { // true iff x and y have opposite signs
		cout <<"opposite sign \n";
	} else {
		cout <<"not a opposite sign \n";
	}
}
//static void do_rev () {
//	unsigned int v = 219;     // input bits to be reversed
//	print_bin(v);
//	unsigned int r = v; // r will be reversed bits of v; first get LSB of v
//	int s = sizeof(v) * CHAR_BIT - 1; // extra shift needed at end
////
////	for (v >>= 1; v; v >>= 1)
////	{
////	  r <<= 1;
////	  r |= v & 1;
////	  s--;
////	}
//	while(v) {
//		v >>= 1;		//TODO:Use this method for rotation (n rotation) n times or O.M. use left_shift | right_shift(K-n)
//						//K = total bits and n = no of rotation.
//		r <<= 1;
//		r |= v & 1;	//get only one bit of v every time/
//		s--;
//	}
//
//	r <<= s; // shift when v's highest bits are zero
//	printf("%d \n",r);
//	print_bin(r);
//}
//static void do_and() {
//	int a = 13;
//	printf ("max_int = %d size of int = %d\n",INT_MIN,sizeof(int));
//	int b = 23;
//	unsigned int t = 65535;
////	printf("unsigned int = %d and signed int = %d\n",~t,~a);
//	int c = a & b;
//	printf("And = %d \n",c);
//	c = a | b;
//	printf("Oring = %d \n",c);
//	c = a << 1;
//	printf("a Left shift by 1 = %d \n",c);
//	c = a >> 1;
//	printf("a = %d Right shift by 1 = %d \n",a,c);
//}
//
//int store = 0;
//void more_simple_assign(int number) {
//
//	int shifted_number = 1 << number;
//	store |= shifted_number;
//
//}
//
//
//static void verify_number(int number) {
//
//	printf("\n");
//	int tester = store;
//	tester = tester >> number;
//	tester = tester & 1;
//	if(tester == 1) {
//		printf("found \n");
//	} else {
//		printf("not found \n");
//	}
//
//}
//
//void assign_number(int number) {
//
//
//
//	int a = 0x1F;
////	int a =  31;
////	printf("%d \n",a);
//	int b = a << number;
//	int twos_cmplmt = -b;
//	int t = twos_cmplmt & b;
//	t = t >> number;
//	t = t & 0x01;
////	t = t & 1;
//	if( t == 1) {
//		printf(" equal ");
//	} else {
//		printf("not equal");
//	}
//
//
//	//OR more simple
////	int store = 0;
////	a = 0x0F;
//////	int mask = number & a;
////	int temp = 1 << mask;
////	store |= temp;
//}

//How number is represented in c (positive/negative (2's complement))

//Tricks

int check_endian_ness() {
    int four_byte_store = 1;
    cout << "checking endianness" << endl;
    //Intialize the pointer and then assign the value
    char *byte_store = 0;
    byte_store = (char*)& four_byte_store;
    if (*byte_store == 0) {
        cout << "big endian" << endl;
        return 0;
    }
    else {
        cout << "little endian" << endl;
        return 1;
    }
}

//Mask : acts as the 
int get_mask (int dist_movement) {
    unsigned int j = 1;
    j = j << dist_movement;
    //cout << "getting the mask " << endl;
    //print_bin(j);
    return (j);
}


int get_half_swapped_bits (int number,int no_of_bits,int mask_length,string dir) {
    int half_no_of_bits = no_of_bits / 2;
    int distance_to_travel = no_of_bits  - 1;
    int temp  = 0;
    int mask = 0;
    int half = 0;
    int temp_val = number;
    while (half_no_of_bits != 0) {
        mask = get_mask (mask_length);
        if (dir == "left_half") {
            temp = temp_val << distance_to_travel ;
            mask_length -= 1;
        } else if (dir == "right_half") {
            temp = temp_val >> distance_to_travel ;
            mask_length += 1;
        }
        temp &= mask;
        half |= temp;
        half_no_of_bits -= 1;
        distance_to_travel -= 2;
        temp_val = number;
    }
    return half;
}

void swap_given_number_wrapper (int number,int no_of_bits) {
    //NOTE : mask is depend on the endianness
    int left_half = get_half_swapped_bits (number,no_of_bits,no_of_bits - 1,"left_half");
    int right_half = get_half_swapped_bits (number,no_of_bits,0,"right_half");
    int ans = left_half  | right_half ;
    cout << "with wrapper ans = " ;
    print_bin (ans);

}

void swap_the_given_number (int i,int no_of_bits) {
    int left_half = 0;
    int right_half = 0;
    int temp  = 0;
    int temp_val = i;
    unsigned int mask = 0;
    print_bin (i);
    int half_no_of_bits = no_of_bits / 2;
    int distance_to_travel = no_of_bits  - 1;
    int no_of_bits_swapped = no_of_bits  - 1;
    while (half_no_of_bits != 0) {
           temp = temp_val << distance_to_travel ;
           mask = get_mask (no_of_bits_swapped);
           temp &= mask;
           left_half |= temp;
           half_no_of_bits -= 1;
           distance_to_travel -= 2;
           no_of_bits_swapped -= 1;
           temp_val = i;
    }
    half_no_of_bits = no_of_bits / 2;
    distance_to_travel = no_of_bits - 1;
    no_of_bits_swapped = 0 ; 
    while (half_no_of_bits != 0) {
           temp = temp_val >> distance_to_travel ;
           mask = get_mask (no_of_bits_swapped);
           //cout << "temp result " << endl;  
           //print_bin(temp);
           temp &= mask;
           right_half |= temp;
           half_no_of_bits -= 1;
           distance_to_travel -= 2;
           no_of_bits_swapped += 1;
           temp_val = i;
    }
    int swapped_number = left_half | right_half ;
    cout << "without wrapper ans = " ;
    print_bin (swapped_number);
}


int main(int argc,char **argv) {
    
    //cout << "int size = "<< sizeof(int) << endl;
    //cout << "int size = "<< sizeof(char) << endl;
    //unsigned int i = -1;
    //i = i >> 30;
    //cout << "the value of i = " << i << endl;
    //int si = 9;
    //unsigned int usi = 9;
    //cout << "n & (n-1) = "  << (si & (si-1)) << endl;
    //cout << "si & -1 = "  << (si & (-1)) << endl;
    //cout << "si | -1 = "  << (si | (-1)) << endl;
    //cout << "unsigned i | -1 = "  << (usi | (-1)) << endl;
    //check_endian_ness();
    //do_and();
    //do_rev();
    //detect_opp_sign();
    //assign_number(12);
    //int i;
    //int t[] = {10,23,24,28,32};
    //for (i=0;i<5;i++) {
    //    more_simple_assign(t[i]);
    //}
    //verify_number(10);
    //verify_number(11);
    //verify_number(28);
    swap_the_given_number (400032456,32);
    swap_given_number_wrapper (400032456,32);
}

