// https://leetcode.com/problems/wiggle-subsequence/description/

//                                      376. Wiggle Subsequence

//                                  first method O(n*n)

class Solution {
public:
int dp[1001][1001][2];
    int solve(vector<int>& nums, int idx, int prev, int flag) {
        if (idx >= nums.size()) {
            return 0;
        }
        if(dp[idx][prev+1][flag]!=-1){
            return dp[idx][prev+1][flag];
        }
        int a = solve(nums, idx + 1, prev, flag);
        int b = 0;
        if ((prev == -1 || (flag == 1 && nums[prev] > nums[idx]) ||
             (flag == 0 && nums[prev] < nums[idx]))) {
            b = 1 + solve(nums, idx + 1, idx, 1 - flag);
        }
        return dp[idx][prev+1][flag] =max(a, b);
    }
    int wiggleMaxLength(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return max(solve(nums, 0, -1, 1), solve(nums, 0, -1, 0));
    }
};

//                                              second method O(n)

class Solution {
public:
    int dp[1001][2];
    int solve(vector<int>& nums, int idx, int flag) {
        if (idx == nums.size()) {
            return 0;
        }
        if (dp[idx][flag] != -1) {
            return dp[idx][flag];
        }
        int a = solve(nums, idx + 1, flag);
        int b = 0;
        if (flag == 1) {
            if (idx == 0 || nums[idx] > nums[idx - 1]) {
                b = 1 + solve(nums, idx + 1, 0);
            }
        } else {
            if (idx == 0 || nums[idx] < nums[idx - 1]) {
                b = 1 + solve(nums, idx + 1, 1);
            }
        } 
        return dp[idx][flag] = max(a, b);
    }
    int wiggleMaxLength(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(nums, 0, 1);
        memset(dp, -1, sizeof(dp));
        ans = max(ans, solve(nums, 0, 0));
        return ans;
    }
};


//                                              optimize approach

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size = nums.size(), peak = 1, valley = 1;
        for (int i = 1; i < size; ++i) {
            if (nums[i] > nums[i - 1])
                peak = valley + 1;
            else if (nums[i] < nums[i - 1])
                valley = peak + 1;
        }
        return max(peak, valley);
    }
};