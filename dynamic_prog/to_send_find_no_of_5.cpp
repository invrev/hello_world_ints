#include<iostream>
#include<map>
#include<climits>

int count_no_ks(int num,std::map<int,int>& mem_map,int k = 5) {
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
    if (mem_map.find(num) == mem_map.end()) {
        t1 = msb * count_no_ks(power - 1,mem_map);
        t2 = count_no_ks(rem,mem_map);
        mem_map[num] = no_of_ks + t1 + t2;
    } else {
        return mem_map[num];
    }
    return  no_of_ks + t1 + t2 ;
}

int main () {
    
    std::map<int,int> mem_map;
    int t = 0;
    std::cout << "# of 5s from 0 to " << t << " = " << count_no_ks (t,mem_map) << std::endl;
    t = 4;
    std::cout << "# of 5s from 0 to " << t << " = " << count_no_ks (t,mem_map) << std::endl;
    t = 5;
    std::cout << "# of 5s from 0 to " << t << " = " << count_no_ks (t,mem_map) << std::endl;
    t = 10;
    std::cout << "# of 5s from 0 to " << t << " = " << count_no_ks (t,mem_map) << std::endl;
    t = 49;
    std::cout << "# of 5s from 0 to " << t << " = " << count_no_ks (t,mem_map) << std::endl;
    t = 449;
    std::cout << "# of 5s from 0 to " << t << " = " << count_no_ks (t,mem_map) << std::endl;
    t = INT_MAX;
    t /= 2;
    std::cout << "# of 5s from 0 to " << t << " = " << count_no_ks (t,mem_map) << std::endl;
}
