// https://leetcode.com/problems/count-the-number-of-inversions/description/

//         3193. Count the Number of Inversions

class Solution {
public:
      vector<int>req;
      int solve(int idx,int ireq,vector<vector<int>>&dp){
        if(idx<=0){
            if(ireq==0){
                return 1;
            }
            return 0;
        }
        if(req[idx]!=-1){
            if(req[idx]!=ireq){
                return 0;
            }
        }
        if(dp[idx][ireq]!=-1){
            return dp[idx][ireq];
        }
        int ans=0;
        for(int i=0;i<=min(ireq,idx);i++){
            ans+= solve(idx-1,ireq-i,dp);
            ans%=1000000007;
        }
        return dp[idx][ireq]=ans;
      }
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        req.resize(n,-1);
        sort(requirements.begin(),requirements.end());
        for(auto it:requirements){
            req[it[0]]= it[1];
        }
        vector<vector<int>>dp(n,vector<int>(401,-1));
        int ans= solve(n-1,req[n-1],dp);
        return ans;
    }
};