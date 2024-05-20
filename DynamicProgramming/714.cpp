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