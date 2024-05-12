class Solution {
public:
int dp[1001][1001];
    int maxScore(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        int ans= INT_MIN;
        dp[n-1][m-1]= grid[n-1][m-1];
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1){
                    continue;
                }
                else if(i==n-1){
                    int res= dp[i][j+1]-grid[i][j];
                    ans= max(ans,res);
                    dp[i][j]= max(grid[i][j],dp[i][j+1]);
                }
                else if(j==m-1){
                    int res= dp[i+1][j]-grid[i][j];
                    ans= max(ans,res);
                    dp[i][j]= max(grid[i][j],dp[i+1][j]);
                }
                else{
                    int res= max(dp[i+1][j],dp[i][j+1])- grid[i][j];
                    ans= max(ans,res);
                    dp[i][j]= max(grid[i][j],max(dp[i+1][j],dp[i][j+1]));
                }
            }
        }
        return ans;
    }
};