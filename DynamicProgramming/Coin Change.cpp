// https://leetcode.com/problems/coin-change/description/

//                                     322. Coin Change

//                                          recursion + memo

class Solution {
public:
    int dp[13][10001];
    int solve(vector<int>& coins, int amount, int i) {
        if (amount == 0) {
            return 0;
        }
        if (i < 0 || amount < 0) {
            return INT_MAX;
        }
        if (dp[i][amount] != -1) {
            return dp[i][amount];
        }
        int t = INT_MAX;
        if (amount >= coins[i]) {
            int res= solve(coins, amount - coins[i], i);
            if(res!=INT_MAX){
                t= res+1;
            }
        }
        int nt = solve(coins, amount, i - 1);
        return dp[i][amount] = min(t, nt);
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(coins, amount, coins.size() - 1);
        if (ans == INT_MAX) {
            ans = -1;
        }
        return ans;
    }
};


//                                                   terbulation

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int N= coins.size();
        long long int t[N+1][amount+1];
        //  int mod=1000000007;
        for(int i=0;i<=N;i++){
            t[i][0]=0;
        }
        for(int j=1;j<=amount;j++){
            t[0][j]=INT_MAX;
        }
        for(int i=1;i<N+1;i++){
            for(int j=0;j<amount+1;j++){
                if(coins[i-1]<=j){
                    t[i][j]=min(1+t[i][j-coins[i-1]],t[i-1][j]);
                }
                else{
                    t[i][j]=t[i-1][j]; 
                }
            }
        }
        if(t[N][amount]==INT_MAX){
            t[N][amount]=-1;
        }
        return t[N][amount];
    }
};