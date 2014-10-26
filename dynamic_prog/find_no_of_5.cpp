#include<iostream>
#include<map>
#include<climits>
using namespace std;

int count_no_ks_from_l_to_r (int num) {
    if (num == 0) return 0;
    int power = 1; 
    while (10 * power < num) {
        power = power * 10;
    }
    int msb = num / power;
    int rem = num % power;
    //cout << "msb = "  << msb << " rem = " << rem << endl;
    int no_of_ks = 0;
    if (msb > 5) {
        no_of_ks += power;
        //cout << "add power " << power << endl;
    } else if (msb == 5) { 
        no_of_ks += rem;
        no_of_ks += 1;
        //cout << "add rem " << rem<< endl;
    }

    //cout << "("  << (power-1) << "," << rem << ","  << num << ")" << " = " << no_of_ks  << endl;
    int t1 = msb * count_no_ks_from_l_to_r(power - 1);
    int t2 = count_no_ks_from_l_to_r (rem);
    //int count_no_of_other_ks = msb * count_no_ks_from_l_to_r(power - 1) + count_no_ks_from_l_to_r (rem) ;
    return  no_of_ks + t1 + t2 ;
}


int count_no_ks_from_l_to_r1 (int num,map<int,int>& mem_map,int k = 5) {
    if (num < k ) return 0;
    int power = 1; 
    while (10 * power < num) {
        power = power * 10;
    }
    int msb = num / power;
    int rem = num % power;
    int no_of_ks = 0;
    if (msb > k) {
        no_of_ks += power;
    } else if (msb == k) { 
        no_of_ks += rem;
        no_of_ks += 1;
    }
    int t1;
    int t2;
    cout << "("  << (power-1) << "," << rem << ","  << num << ")" << " = " << no_of_ks  << endl;
    if (mem_map.find(num) == mem_map.end()) {
        t1 = msb * count_no_ks_from_l_to_r1 (power - 1,mem_map);
        t2 = count_no_ks_from_l_to_r1 (rem,mem_map);
        mem_map[num] = no_of_ks + t1 + t2;
    } else {
        return mem_map[num];
    }
    return  no_of_ks + t1 + t2 ;
}


int count_no_ks_from_l_to_r2 (int num) {
    int numToRight=0, count=0, i=1;
    int pow10=1; // speed up power calculation
    while(num/10){
        int digit = num  % 10;
        if (digit == 1){
            count += digit*i*pow10;
        } else if (digit == 5){
            count += digit*i*pow10 + numToRight+1;
        } else {
            count += digit*i*pow10 + numToRight+pow10;
        }
        numToRight += digit*pow10;
        num /=10;
        pow10 *=10;
        i++;
    }
    return count;
}

int main () {
    
    //cout << "count # of 5s = " << count_no_ks_from_l_to_r (500) << endl;

    //cout << "count # of 5s = " << count_no_ks_from_l_to_r (t) << endl;

    cout << "count # of 5s = " << count_no_ks_from_l_to_r (0) << endl;
    cout << "count # of 5s = " << count_no_ks_from_l_to_r (4) << endl;
    cout << "count # of 5s = " << count_no_ks_from_l_to_r (5) << endl;
    cout << "count # of 5s = " << count_no_ks_from_l_to_r (10) << endl;
    cout << "count # of 5s = " << count_no_ks_from_l_to_r (49) << endl;
    cout << "count # of 5s = " << count_no_ks_from_l_to_r (449) << endl;
    int t = INT_MAX;
    t /= 2;
    cout << "count # of 5s = " << count_no_ks_from_l_to_r (t) << endl;


    map<int,int> mem_map;
    //cout << "count # of 5s = " << count_no_ks_from_l_to_r1 (t,mem_map) << endl;
    //cout << "count # of 5s = " << count_no_ks_from_l_to_r1 (5,mem_map) << endl;
    //cout << "count # of 5s = " << count_no_ks_from_l_to_r1 (4,mem_map) << endl;
    //cout << "count # of 5s = " << count_no_ks_from_l_to_r1 (500,mem_map) << endl;


}
