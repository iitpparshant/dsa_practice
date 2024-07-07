// https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/description/

//             3212. Count Submatrices With Equal Frequency of X and Y

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        int dp[n+1][m+1][2];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                dp[i][j][0]=0;
                dp[i][j][1]=0;
            }
            // cout<<endl;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(grid[i-1][j-1]=='X'){
                    dp[i][j][0]=1+ dp[i-1][j][0]+ dp[i][j-1][0]-dp[i-1][j-1][0];
                    dp[i][j][1]=dp[i-1][j][1]+ dp[i][j-1][1]-dp[i-1][j-1][1];
                }
                else if(grid[i-1][j-1]=='Y'){
                    dp[i][j][1]=1+ dp[i-1][j][1]+ dp[i][j-1][1]-dp[i-1][j-1][1];
                    dp[i][j][0]=dp[i-1][j][0]+ dp[i][j-1][0]-dp[i-1][j-1][0];
                }
                else{
                    dp[i][j][0]=dp[i-1][j][0]+ dp[i][j-1][0]-dp[i-1][j-1][0];
                    dp[i][j][1]=dp[i-1][j][1]+ dp[i][j-1][1]-dp[i-1][j-1][1];
                }
            }
        }
        int count=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                // cout<<dp[i][j][1]<<" "<<dp[i][j][0]<<" ";
                if(dp[i][j][1]==dp[i][j][0] &&dp[i][j][0]!=0){
                    count++;
                }
            }
            // cout<<endl;
        }
        return count;
    }
};