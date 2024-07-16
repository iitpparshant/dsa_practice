// https://leetcode.com/problems/edit-distance/description/

//                                           72. Edit Distance

//                                                 memoization

class Solution {
public:
int dp[501][501];
int solve(int i,int j,string s,string t){
    int n=s.size();
    int m= t.size();
    if(i>=n){
        return m-j;
    }
    if(j>=m){
        return n-i;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int a=INT_MAX,b= INT_MAX,c=INT_MAX;
    if(s[i]==t[j]){
       a= solve(i+1,j+1,s,t);
    }
    else{
        a= 1+solve(i+1,j+1,s,t);
    }
        b= 1+solve(i+1,j,s,t);
        c= 1+solve(i,j+1,s,t);
    return dp[i][j]= min(a,min(b,c));
}
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,word1,word2);
    }
};

//                                                tabulation

class Solution {
public:
    int minDistance(string s, string t) {
        int n=s.size();
    int m= t.size();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int i=0;i<=m;i++){
            dp[0][i]=i;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]= dp[i-1][j-1];
                }
                else{
                    dp[i][j]= 1+ min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        return dp[n][m];
    }
};