//  https://leetcode.com/problems/maximize-total-cost-of-alternating-subarrays/description/

//    3196. Maximize Total Cost of Alternating Subarrays

class Solution {
public:
long long solve(vector<int>&nums,vector<vector<long long>>&dp,int idx, int flag){
     int n= nums.size();
     if(idx>=n){
        return 0;
     }
     if(dp[idx][flag]!=-1){
        return dp[idx][flag];
     }
       long long sum=-1e15;
     long long nsum= -1e15;
     if(flag==1){
        nsum= (-nums[idx]+ solve(nums,dp,idx+1,0));
     }
    sum=nums[idx]+ solve(nums,dp,idx+1,1);
     return dp[idx][flag]= max(sum,nsum);
}
    long long maximumTotalCost(vector<int>& nums) {
        int n= nums.size();
        vector<vector<long long>>dp(n+1,vector<long long>(3,-1));
        return nums[0]+solve(nums,dp,1,1);
    }
};