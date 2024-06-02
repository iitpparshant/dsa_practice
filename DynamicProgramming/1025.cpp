// https://leetcode.com/problems/divisor-game/description/
// 1025. Divisor Game


// ********** first method 
class Solution {
public:
bool solve(int n,bool f){
    if(n==1){
        return f;
    }
    for(int i=1;i<=n/2;i++){
        if(n%i==0){
            return solve(n-i,!f);
        }
    }
    return false;
}
    bool divisorGame(int n) {
        return solve(n,0);
    }
};

// ************  second method 
class Solution {
public:
bool solve(int n,bool f,vector<bool>&dp){
    if(n==1){
        return f;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    for(int i=1;i<=n/2;i++){
        if(n%i==0){
            return dp[n]= solve(n-i,!f,dp);
        }
    }
    return dp[n]=0;
}
    bool divisorGame(int n) {
        vector<bool>dp(n,0);
        return solve(n,0,dp);
    }
};

// ***********  third method 
class Solution {
public:
    bool divisorGame(int n) {
        return !(n&1);
    }
};