// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/

//                              1130. Minimum Cost Tree From Leaf Values

class Solution {
public:
int dp[41][41];
int solve(int l,int r,vector<vector<int>> &mx){
    if(l==r){
        return 0;
    }
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    int ans= 1<<30;
    for(int i=l;i<r;i++){
        ans= min(ans,mx[l][i]*mx[i+1][r]+ solve(l,i,mx)+ solve(i+1,r,mx));
    }
    return dp[l][r]= ans;
}
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        memset(dp,-1,sizeof(dp));
        vector<vector<int>> mx(n + 1, vector<int>(n + 1, -1));
        for (int i = 0; i < n; i++) {
            mx[i][i] = arr[i];
            for (int j = i+1; j < n; j++) {
                mx[i][j]= max(mx[i][j-1],arr[j]);
            }
        }
        return solve(0,n-1,mx);
    }
};