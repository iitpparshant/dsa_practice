// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

//                                 188. Best Time to Buy and Sell Stock IV

//                               first method 

class Solution {
public:
int dp[1005][201];
int solve(int i,int cnt,vector<int>&v,int n,int k){
    if(i==n ||cnt==2*k){
        return 0;
    }
    if(dp[i][cnt]!=-1){
        return dp[i][cnt];
    }
    if(cnt%2==0){
        return dp[i][cnt]= max(-v[i]+solve(i+1,cnt+1,v,n,k),solve(i+1,cnt,v,n,k));
    }
    
     return  dp[i][cnt]= max(v[i]+solve(i+1,cnt+1,v,n,k),solve(i+1,cnt,v,n,k));
    
}
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,prices,prices.size(),k);
    }
};






//                                           second method 

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int cnt = 2 * k - 1; cnt >= 0; cnt--) {
                if (cnt % 2 == 0) {
                    dp[i][cnt] =
                               max(-prices[i] + dp[i+1][cnt+1],
                                   dp[i+1][cnt]);
                }
                else{
                    dp[i][cnt] =
                               max(prices[i] + dp[i+1][cnt+1],
                                   dp[i+1][cnt]);
                }
            }
        }
        return dp[0][0];
    }
};



//                                 third method 

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> ahead(2, vector<int>(k + 1, 0));
        vector<vector<int>> cur(2, vector<int>(k + 1, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= k; cap++) {
                    if (buy == 0) { // We can buy the stock
                        cur[buy][cap] =
                            max(0 + ahead[0][cap], -prices[ind] + ahead[1][cap]);
                    }

                    if (buy == 1) { // We can sell the stock
                        cur[buy][cap] = max(0 + ahead[1][cap],
                                            prices[ind] + ahead[0][cap - 1]);
                    }
                }
            }
            // Update the 'ahead' array with the current values
            ahead = cur;
        }

        return ahead[0][k];
    }
};