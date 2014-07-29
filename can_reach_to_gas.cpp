#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int can_reach_to_start_point (vector<int>& cost,vector<int>& gas) {
    int t_cost_len = cost.size();
    vector<int> gas_deficit(t_cost_len);
    vector<int> possible_max_index;
    int t_gas_deficit = 0;
    int max_index = -1;
    int max_deficit = -999;
    for (int i=0;i<t_cost_len;i++) {
        gas_deficit[i] =  gas[i] - cost[i] ;
        t_gas_deficit += gas_deficit[i];
        if (max_deficit <= gas_deficit[i]) {
            max_deficit = gas_deficit[i];
            possible_max_index.push_back(i);
        }
    }

    if (t_gas_deficit >= 0) {
       int possible_max_size = possible_max_index.size();
       for (int i=0;i<possible_max_size;i++) {
            int start_index = possible_max_index[i];
            int sum = 0; 
            for (int j=start_index ;j<start_index+t_cost_len;j++) {
                int current_index = j;
                if (current_index >= t_cost_len) {
                    current_index = current_index % t_cost_len;
                }
                sum +=gas_deficit[current_index];
                if (sum < 0) {
                    break;
                }
            }
            if (sum == 0) {
                return start_index ;
            }
       }
    }
    return -1;
}


//With using Kadne algorithm deriving the implcit info
int can_reach_to_start_point_v2 (vector<int>& cost,vector<int>& gas) {
    int t_cost_len = cost.size();
    vector<int> gas_deficit(t_cost_len);
    int t_gas_deficit = 0;
    int tmp_index = -1;
    int max_deficit_so_far = 0;
    int max_ending_deficit = 0;
    int start_index = 0;
    int temp_index = 0; 
    gas_deficit[0] =  gas[0] - cost[0] ;
    t_gas_deficit =  gas_deficit[0];
    max_ending_deficit = gas_deficit[0];
    for (int i=1;i<t_cost_len;i++) {
        gas_deficit[i] =  gas[i] - cost[i] ;
        t_gas_deficit += gas_deficit[i];
        if (max_ending_deficit < 0)  {
            max_ending_deficit = gas_deficit[i];
            temp_index = i;
        } else {
            max_ending_deficit += gas_deficit[i];
        }
        
        if (max_ending_deficit >=  max_deficit_so_far) {
            start_index = temp_index ;
        }
    }
    if (t_gas_deficit >=0 ) {
        return start_index;
    }
    return -1;
}

int main () {
    
    int gas_arr[] = {4};
    vector<int> gas(gas_arr,gas_arr + sizeof(gas_arr)/sizeof(int) );
    int cost_arr[] = {5};
    vector<int> cost(cost_arr,cost_arr + sizeof(cost_arr) / sizeof(int));
    int result = can_reach_to_start_point (cost,gas);

}
