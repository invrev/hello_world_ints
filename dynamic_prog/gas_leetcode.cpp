class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int t_cost_len = cost.size();
        vector<int> gas_deficit(t_cost_len);
        int t_gas_deficit = 0;
        int tmp_index = -1;
        int max_deficit_so_far = 0;
        int max_ending_deficit = 0;
        int start_index = 0;
        int temp_index = 0; 
        //Get the implicit information from gas and cost vector
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
};
