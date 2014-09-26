#include<iostream>
#include<vector>
using namespace std;
int maxProfit(vector<int> &prices) {
        vector <int> change;
        change.push_back(0);
        int len = prices.size();
        for (int i=1;i<len;i++) {
            change.push_back (prices[i] - prices[i-1]);
        }
        int t_len = change.size();
        int max_profit = 0;
        for (int j=0;j<t_len;j++) {
            int temp_profit = 0;
            temp_profit +=  change[j];
            if (temp_profit > max_profit) {
                max_profit = temp_profit;
            }
            if (temp_profit < 0) {
                temp_profit = 0;
            }
        }
        return max_profit;
    }
