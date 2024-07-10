// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/submissions/

//                              1547. Minimum Cost to Cut a Stick

//                                memo+rec

class Solution {
public:
int solve(vector<int>&cuts,int i,int j,vector<vector<int>> &dp){
    if(i>j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mn= INT_MAX;
    for(int k=i;k<=j;k++){
       int ans=cuts[j+1]-cuts[i-1]+ solve(cuts,i,k-1,dp)+solve(cuts,k+1,j,dp);
       mn= min(ans,mn);
    }
    return dp[i][j]= mn;
}
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(),cuts.end());
        int c=cuts.size()-2;
        vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
        return solve(cuts,1,c,dp);
    }
};

//                                              terbulation

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));
        for (int i = c; i >= 1; i--) {
            for (int j = 1; j <= c; j++) {
                if (i > j) {
                    continue;
                }
                int mn = INT_MAX;
                for (int k = i; k <= j; k++) {
                    int ans =
                        cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];
                    mn = min(mn, ans);
                }
                dp[i][j] = mn;
            }
        }
        return dp[1][c];
    }
};
