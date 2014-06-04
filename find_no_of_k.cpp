#include<iostream>
using namespace std;
//unit place  : acts as the row
//non unit place  : acts as the column
//number is formed with unit and non unit place
// 513 into 5 * 100 + 13. [Power = 100; First = 5; Remainder = 13]
//2 ways go from left to right or go from the right to left


//TODO : can we go from right to left
//One argument to not go from right to left will be numbers like 100,200,300 where LSB is 0
//Recursion 
//Recurrence formula to compute the # of ks 
//count the ks = MSB * F(power - 1) + F(rem)
//count the ks = MSB * count_no_ks_from_l_to_r(power - 1) + count_no_ks_from_l_to_r(rem) + no_of_ks
int count_no_ks_from_l_to_r (int num) {
    if (num == 0) return 0;
    int power = 1; 
    while (10 * power < num) {
        power = power * 10;
        cout << "power = "  << power << " and number = " << num << endl;
    }
    //compute MSB and the remainder
    int msb = num / power;
    int rem = num % power;
    int no_of_ks = 0;
    //count # of 2's 
    if (msb > 2) {
        no_of_ks += power;
    } else if (msb == 2) { 
        no_of_ks += rem;
        no_of_ks += 1;
    }
    //count the ks = MSB * F(power - 1) + F(rem)
    int count_no_of_other_ks = msb * count_no_ks_from_l_to_r(power - 1) + count_no_ks_from_l_to_r (rem) ;
    return  no_of_ks + count_no_of_other_ks ;
}

int main () {
    
    //int no_of_rows = 0;
    //int no_of_cols = 0;
    //cout << "count # of 2s = " << count_no_ks_from_l_to_r (579) << endl;
    //cout << "count # of 2s = " << count_no_ks_from_l_to_r (5790) << endl;
    cout << "count # of 2s = " << count_no_ks_from_l_to_r (200) << endl;
    
    //while (number) {
    //    no_of_rows = number/10;
    //    xtra_cols = number%10;
    //    cout << "no_of_rows = " << no_of_rows << endl;
    //    cout << "xtra_cols = " << xtra_cols << endl;
    //    number = number / 10;
    //}
    //int number = 0;
    //int index = 0;
    //while (number != 300) {
    //    cout << number << " ";
    //    number = number + 1;
    //    if (number % 10 == 0) {
    //        cout << " --------->" << index << endl;
    //        index += 1;
    //    }
    //}
    //cout << endl;
    

}
