#include<iostream>
#include<vector>
using namespace std;

//The basic idea is that we can only earn money when we have a low and high price, and the amount we make is high - low. Moreover, you only need to consider local maximum or local minimum. For example, in [ 3, 2, 1, 2, 3, 4 ], only "1" and "4" are valuable.
//
//The program starts from the first price and iterates to the end. In each "while" loop, a local min(low3) and local max(high3) are found. Assume high1, high2, low1, low2 corresponds to the buy and sell points for the 2 transactions previous to the current while loop. There can only be 3 possibilities:
//
//The 2nd transaction buys at the newly found local min(low3) and sells at local max(high3). Then the first transaction can consider buying at low2 or selling high2 in order to produce max profit.
//
//The 2nd transaction still buys at low2, but sells at newly found max( high3). The first transaction doesn't have any new points to consider because the buy point of the second transaction stays the same.
//
//Nothing changed, 1st transaction still buys at low1 and sells at high1; and the 2nd transaction still buys at low2 and sells at high2.
//
//Then which possibility to choose ? just compute the profit of all 3 and choose the max one.


int maxProfit(vector<int>& prices) {
        // f[k, ii] represents the max profit up until prices[ii] (Note: NOT ending with prices[ii]) using at most k transactions. 
        // f[k, ii] = max(f[k, ii-1], prices[ii] - prices[jj] + f[k-1, jj]) { jj in range of [0, ii-1] }
        //          = max(f[k, ii-1], prices[ii] + max(f[k-1, jj] - prices[jj]))
        // f[0, ii] = 0; 0 times transation makes 0 profit
        // f[k, 0] = 0; if there is only one price data point you can't make any money no matter how many times you can trade
        if (prices.size() <= 1) {
            return 0;
        }
        else {
            int K = 2; // number of max transation allowed
            int maxProf = 0;
            vector<vector<int> > f(K+1, vector<int>(prices.size(), 0));
            for (int kk = 1; kk <= K; kk++) {
                int tmpMax = f[kk-1][0] - prices[0];
                for (int ii = 1; ii < prices.size(); ii++) {
                    f[kk][ii] = max(f[kk][ii-1], prices[ii] + tmpMax);
                    tmpMax = max(tmpMax, f[kk-1][ii] - prices[ii]);
                    maxProf = max(f[kk][ii], maxProf);
                }
            }
            return maxProf;
        }
 }




int main () {


}
