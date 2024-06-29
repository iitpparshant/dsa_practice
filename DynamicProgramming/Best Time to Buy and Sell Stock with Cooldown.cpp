//  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

//                          309. Best Time to Buy and Sell Stock with Cooldown

//                                     first method


class Solution {
public:
int solve(int buy,int idx,vector<int>&v,vector<vector<int>> &dp){
    if(idx>=v.size()){
        return 0;
    }
    if(dp[idx][buy]!=-1){
        return dp[idx][buy];
    }
    if(buy==0){
        return dp[idx][buy]= max(-v[idx]+solve(1,idx+1,v,dp),solve(0,idx+1,v,dp));
    }
    return dp[idx][buy]= max(v[idx]+solve(0,idx+2,v,dp),solve(1,idx+1,v,dp));
}
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0,0,prices,dp);
    }
};




//                                              second method 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0));
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
                if(buy==0){
                    dp[idx][buy]= max(-prices[idx]+dp[idx+1][1],dp[idx+1][0]);
                }
                else{
                    dp[idx][buy]= max(prices[idx]+dp[idx+2][0],dp[idx+1][1]);
                }
            }
        }
        return dp[0][0];
    }
};




//                                             third method 


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> cur(2, 0);    // Current maximum profit
        vector<int> front1(2, 0); // Maximum profit one step ahead
        vector<int> front2(2, 0);
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit;

                if (buy == 0) { // We can buy the stock
                    profit = max(0 + front1[0], -prices[ind] + front1[1]);
                }

                if (buy == 1) { // We can sell the stock
                    profit = max(0 + front1[1], prices[ind] + front2[0]);
                }

                cur[buy] = profit;
            }

            // Update the 'front1' and 'front2' arrays with current values
            front2 = front1;
            front1 = cur;
        }
        return cur[0];
    }

};
