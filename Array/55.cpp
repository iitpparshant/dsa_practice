// https://leetcode.com/problems/jump-game/description/

//   55. Jump Game

//   Method 1


class Solution {
public:
int dp[10001];
bool solve(vector<int>&nums,int s){
    int n= nums.size();
    if(s==n-1){
        return dp[s]=1;
    }
    if(dp[s]!=-1){
        return dp[s];
    }
    for(int i=1;i<=nums[s];i++){
        if(s+i<n){
            if(solve(nums,s+i)){
                return dp[s+i]= 1;
            }
        }
    }
    return dp[s]= 0;
}
    bool canJump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0);
    }
};

//   Method 2

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n= nums.size();
        int e= n-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>=(e-i)){
                e=i;
            }
        }
        return e==0;
    }
};

