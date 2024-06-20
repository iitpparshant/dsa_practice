// https://leetcode.com/problems/remove-boxes/description/

//       546. Remove Boxes

class Solution {
public:
vector<vector<int>>g;
int dp[101][101][101];
int solve(int l,int r,int k){
    if(l>r){
        return 0;
    }
    if(dp[l][r][k] != -1) return dp[l][r][k];
    int s=g[l][1];
    int c= g[l][0];
    dp[l][r][k]= solve(l+1,r,0)+ (k+s)*(k+s);
    for(int i=l+1;i<=r;i++){
        if(g[i][0]==c){
            dp[l][r][k]= max(dp[l][r][k],solve(l+1,i-1,0)+solve(i,r,k+s));
        }
    }
    return dp[l][r][k];
}
    int removeBoxes(vector<int>& boxes) {
        memset(dp,-1,sizeof(dp));
        int n= boxes.size();
        int count=1;
        for(int i=1;i<n;i++){
            if(boxes[i]!=boxes[i-1]){
                g.push_back({boxes[i-1],count});
                count=0;
            }
            count++;
        }
        g.push_back({boxes[n-1],count});
        return solve(0,g.size()-1,0);
    }
};