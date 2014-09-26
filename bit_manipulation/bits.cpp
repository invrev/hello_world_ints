#include<iostream>
#include<algorithm>
using namespace std;

//NOTE : bit mask,XOR (simillar input leads to 0),Bitwise operation is diff than arithmetic operation
int get_how_to_convert(int a,int b) {
    int diff =  0;
}

int get_alternate_mask (bool is_even) {
    int mask = 0; 
    int start = 0;
    int total_size = sizeof(int) * 8;
    if (is_even == false) {
        start = 1; 
    }
    int tmp = 1;
    for (int i=start;i<total_size;i+= 2) {
        tmp = tmp << i;
        mask |= tmp;
        tmp = 1;
    }
    return mask;
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
}

//Swap the consecutive bits naive approach
//get the alternate bits even_side and odd_side
//Move the even_side << 1 
//Move the odd_side >> 1
//OR the even_side and odd_side and get the result

void swap_consecutive_bits (int a) {
    //cout << "the give result " << a << endl;
    //print_bin (a);
    int temp_mask = get_alternate_mask (true);

    //cout << "even alternate mask " << endl;
    //print_bin (temp_mask) ;
    int even_result = temp_mask & a;
    even_result = even_result << 1;
    //print_bin (even_result);
    temp_mask = get_alternate_mask (false);
    //cout << "odd alternate mask " << endl;
    //print_bin (temp_mask) ;
    int odd_result = temp_mask & a;
    odd_result = odd_result  >> 1;
    //print_bin (odd_result);
    int swapped_result = even_result | odd_result;
    cout << "the swapped result = " << swapped_result  << endl;
    //print_bin (tst_result);
}

//Determine wheather the number is power of 2 or not
void is_power_of_2 (int no) {
    if ( (no & (no - 1)) == 0) {
        cout << "the no = " << no << " is power of 2." << endl;
    } else {
        cout << "the no = " << no << " is not power of 2." << endl;
    }
}

//Count the #of 1's in the given number
void count_number_of_ones (int no) {
    cout << "the # of 1's in "<< no ;
    int i = 0;
    for (; no != 0;i++)  {
        no = (no & (no -1));
    }
    cout << " = " << i << endl;
}

//The property of xor is output 1 if there is bit difference
//NOTE : boolean operations are diff from the arithmetic operations 
void no_of_bits_req_from_a_to_b (int a,int b) {
    int result =  a ^ b;
    int cnt = 0;
    while (result != 0) {
        cnt += 1;
        result = (result  & (result - 1));
    }
    cout << "# of bits req (" << a << "," << b << ") = " << cnt << endl;
}

int get_zero_padded_mask_given_bound (int start,int end) {
    int mask = 0; 
    int tmp = 1;
    while (start <= end) {
        tmp = tmp << start;
        mask |= tmp;
        start += 1;
        tmp = 1;
    }
  return mask;  
    
}

int get_one_padded_mask (int no,int start,int end) {
    unsigned int mask = -1;
    int shift_loc = start;
    while (start <= end) {
        mask = mask & (mask - 1);
        start += 1;
    }
    mask |= no;
    //cout << "wo_shifted _mask = "; print_bin(mask );
    mask = mask << shift_loc;
    //cout << "shifted _mask = "; print_bin(mask );
    int tmp = 1;
    shift_loc -= 1;
    while (shift_loc >= 0) {
        tmp = tmp  << shift_loc;
        mask |= tmp ;
        shift_loc -= 1;
        tmp = 1;
    }
    
    return mask;  
}

//Given m put n in m from start to end
void replace_m_substr_by_n (int m,int n,int start,int end) {
    //cout << "m = "; print_bin (m);
    //cout << "n = "; print_bin (n);
    int mask = get_zero_padded_mask_given_bound (start,end) ;
    //cout << "mask = " << start << "," << end << " " ;  print_bin (mask) ;
    int inter_result = m | mask ;
    //cout << "inter_result = "; print_bin (inter_result) ;
    int new_n = get_one_padded_mask (n,start,end);
    //cout << "new_n = "; print_bin (new_n) ;
    int result = inter_result & new_n;
    cout << "result = "; print_bin (result) ;

}

//Determine which endian
//In case big endian we go from (L-R) while in case of little endian we go (R-L) and store each byte 
//in the memory array start from 0
//eg.0x90ab12cd big-endian (L-R) 90:1000,ab:1001,12:1002,cd:1003
//little-endian (R-L) cd:1000,12:1001,ab:1002,90:1003
//NOTE : 
void which_endian () {
    int i = 1;
    char *mem_loc = (char*) &i;
    if (mem_loc [0] == 1) {
        cout << "Little endian." << endl;
    } else {
        cout << "Big endian." << endl;
    }
}

//given number display its binary format 
void disp_binary (int no) {
  string given_number = "";
   while (no != 0)  {
        if (no & 1) {
            //cout << "1";
            given_number.append("1");
        }else {
            //cout << "0";
            given_number.append("0");
        }
        no = no >> 1;
   }
   given_number.append("0");
   //cout << "0" << endl;
  
   //Need to perform reverse operation because of little endian
   reverse(given_number.begin(),given_number.end());
   cout << given_number << endl;

}



int main () {
    swap_consecutive_bits(3);
    swap_consecutive_bits(5);
    is_power_of_2 (4);
    is_power_of_2 (5);
    is_power_of_2 (15);
    is_power_of_2 (8);
    count_number_of_ones (-5) ;
    count_number_of_ones (1) ;
    count_number_of_ones (0) ;
    no_of_bits_req_from_a_to_b (31,14);
    replace_m_substr_by_n (400,56,2,4);
    which_endian ();
    disp_binary (3);

}
