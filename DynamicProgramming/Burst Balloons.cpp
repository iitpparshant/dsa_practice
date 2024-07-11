//   https://leetcode.com/problems/burst-balloons/description/

//                               312. Burst Balloons

//                                     res+memo

class Solution {
public:
int solve(vector<int>&nums,int i,int j,vector<vector<int>> &dp){
    if(i>j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int n= nums.size();
    int mx= INT_MIN;
    for(int k=i;k<=j;k++){
        // cout<<nums[i-1]*nums[k]*nums[j+1]<<"****";
        int ans= solve(nums,i,k-1,dp)+ nums[i-1]*nums[k]*nums[j+1]+ solve(nums,k+1,j,dp);
        mx= max(mx,ans);
    }
    return dp[i][j]= mx;
}
    int maxCoins(vector<int>& nums) {
        int n= nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        return solve(nums,1,n,dp);
    }
};


//                                                       terbulation

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int i = n; i >= 1; i--) {
            for (int j = 1; j <= n; j++) {
                int mx = INT_MIN;
                if (i > j) {
                    continue;
                }
                for (int k = i; k <= j; k++) {
                    int ans = dp[i][k - 1] +
                              nums[i - 1] * nums[k] * nums[j + 1] +
                              dp[k + 1][j];
                    mx = max(mx, ans);
                }
                dp[i][j] = mx;
            }
        }
        return dp[1][n];
    }
};