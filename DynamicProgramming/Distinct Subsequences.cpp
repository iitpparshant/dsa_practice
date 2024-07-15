// https://leetcode.com/problems/distinct-subsequences/description/

//                                   115. Distinct Subsequences

//                                       memomize sol.

class Solution {
public:
int mod= 1e9+7;
int dp[1001][1001];
int solve(int i,int j,string s,string t){
    if(j<0){
        return 1;
    }
    if(i<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int res=0;
    if(s[i]==t[j]){
        res= (solve(i-1,j-1,s,t)+ solve(i-1,j,s,t))%mod;
    }
    else{
       res= solve(i-1,j,s,t)%mod;
    }
    return dp[i][j]= res;
}
    int numDistinct(string s, string t) {
        int n= s.size();
        int m= t.size();
        memset(dp,-1,sizeof(dp));
        return solve(n-1,m-1,s,t);
    }
};

//                                               tabulation sol.

class Solution {
public:
int mod= 1e9+7;
    int numDistinct(string s, string t) {
        int n= s.size();
        int m= t.size();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i =0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=m;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]= (dp[i-1][j-1]+dp[i-1][j])%mod;
                }
                else{
                    dp[i][j]= dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};