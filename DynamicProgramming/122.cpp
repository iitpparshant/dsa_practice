// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

//  **** Method 1 *******

class Solution {
public:
int solve(vector<int>& prices, bool buy,int i,vector<vector<int>>&dp){
    if(i==prices.size()){
        return 0;
    }
    if(dp[buy][i]!=-1){
        return dp[buy][i];
    }
    if(buy==0){
        return dp[buy][i]= max(-prices[i]+solve(prices,1,i+1,dp),solve(prices,0,i+1,dp));
    }
    else{
        return dp[buy][i]= max(solve(prices,0,i+1,dp)+prices[i],solve(prices,1,i+1,dp));
    }
}
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>>dp(2,vector<int>(n,-1));
        return solve(prices,0,0,dp);
    }
};



//  **** Methode 2 *****  

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        int j = 1;
        while(j<prices.size()){
            if(prices[j] > prices[j-1]){
                sum += prices[j] - prices[j-1];
            }
            j++;
        }
        return sum;
    }
};