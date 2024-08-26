// https://leetcode.com/problems/2-keys-keyboard/description/

// 650. 2 Keys Keyboard

class Solution {
public:
int dp[1001][1001];
int solve(int n,int c,int p){
    if(c==n){
        return 0;
    }
    if(c>n){
        return n+1;
    }
    if(dp[c][p]!=-1){
        return dp[c][p];
    }
    int candp= 2+solve(n,2*c,c);
    int onlyp= 1+ solve(n,c+p,p);
    return dp[c][p]= min(candp,onlyp);
}
    int minSteps(int n) {
        if(n==1){
            return 0;
        }
        memset(dp,-1,sizeof(dp));
        return 1+solve(n,1,1);
    }
};