//    https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

//                   123. Best Time to Buy and Sell Stock III


//                        first method 

class Solution {
public:
vector<vector<vector<int>>> dp;
int solve(int idx,vector<int>&p,bool flag,int count){
    if(idx==p.size()||count==2){
        return 0;
    }
    string temp= to_string(idx)+"#"+to_string(flag)+"#"+to_string(count);
    if (dp[idx][flag][count] != -1) {
            return dp[idx][flag][count];
        }
    int ntake= solve(idx+1,p,flag,count);
    int take;
    if(flag){
        take= -p[idx]+solve(idx+1,p,0,count);
    }
    else{
        take= p[idx]+solve(idx+1,p,1,count+1);
    }
    return dp[idx][flag][count]= max(take,ntake);
}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0,prices,1,0);
    }
};



//                       second method 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i=n-1;i>=0;i--){
            for(int b=0;b<=1;b++){
                for(int l=1;l<=2;l++){
                    int profit= 0;
                    if(b){
                        int B= -prices[i]+ dp[i+1][0][l];
                        int skip=dp[i+1][1][l];
                        profit= max(B,skip);
                    }
                    else{
                        int S= prices[i]+ dp[i+1][1][l-1];
                        int skip=dp[i+1][0][l];
                        profit= max(S,skip);
                    }
                    dp[i][b][l]= profit;
                }
            }
        }
        return dp[0][1][2];
    }
};




//                          third method 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>prev(5,0);
        vector<int>curr(5,0);
        for(int i=n-1;i>=0;i--){
            for(int t=3;t>=0;t--){
                if(t%2==0){
                    curr[t]= max(-prices[i]+prev[t+1],prev[t]);
                }
                else{
                    curr[t]= max(prices[i]+prev[t+1],prev[t]);
                }
            }
            prev= curr;
        }
    return prev[0];
    }
};