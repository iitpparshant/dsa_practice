// https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/description/

//                                       3202. Find the Maximum Length of Valid Subsequence II

class Solution {
public:
int dp[1001][1001];
int solve(vector<int>&nums,int s,int k,int r){
    int ans=0;
    if(dp[s][r]!=-1){
        return dp[s][r];
    }
    for(int i=s+1;i<nums.size();i++){
        if((nums[s]+nums[i])%k==r){
            ans=1+ solve(nums,i,k,r);
            break;
        }
    }
    return dp[s][r]= ans;
}
    int maximumLength(vector<int>& nums, int k) {
        int n= nums.size();
        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans= max(ans,2+solve(nums,j,k,(nums[i]+nums[j])%k));
            }
        }
        return ans;
    }
};