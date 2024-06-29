//  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

//                                        714. Best Time to Buy and Sell Stock with Transaction Fee

//                                   first method 


class Solution {
public:
int solve(vector<int>& prices, int fee,bool buy,int i,vector<vector<int>>&dp){
    if(i==prices.size()){
        return 0;
    }
    if(dp[buy][i]!=-1){
        return dp[buy][i];
    }
    if(buy==0){
        return dp[buy][i]= max(-prices[i]+solve(prices,fee,1,i+1,dp),solve(prices,fee,0,i+1,dp));
    }
    else{
        return dp[buy][i]= max(solve(prices,fee,0,i+1,dp)+prices[i]-fee,solve(prices,fee,1,i+1,dp));
    }
}
    int maxProfit(vector<int>& prices, int fee) {
        int n= prices.size();
        vector<vector<int>>dp(2,vector<int>(n,-1));
        return solve(prices,fee,0,0,dp);
    }
};



//                                             second method 

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
         int n= prices.size();
        vector<vector<long>> dp(n + 1, vector<long>(2, -1));

        dp[n][0] = dp[n][1] = 0;

        long profit;

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy == 0) {
                    profit =
                        max(0 + dp[ind + 1][0], -prices[ind]-fee + dp[ind + 1][1]);
                }

                if (buy == 1) {
                    profit =
                        max(0 + dp[ind + 1][1], prices[ind] + dp[ind + 1][0]);
                }

                dp[ind][buy] = profit;
            }
        }
        return dp[0][0];
    }
};