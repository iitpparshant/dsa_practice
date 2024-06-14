//  https://leetcode.com/problems/longest-arithmetic-subsequence/description/

//   1027. Longest Arithmetic Subsequence

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n= nums.size();
        int dp[1003][1003] = {0};
        if(n<=2){
            return n;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int diff= nums[i]-nums[j]+500;
                int count=1;
                if(dp[i][diff]>0){
                    count= dp[i][diff];
                }
                dp[j][diff]= 1+count;
                ans= max(ans,dp[j][diff]);
            }
        }
        return ans;
    }
};