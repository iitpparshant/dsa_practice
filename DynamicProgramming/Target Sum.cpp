// https://leetcode.com/problems/target-sum/description/

//                                                     494. Target Sum

class Solution {
public:
    int isSubsetSum(vector<int> &arr, int sum) {
        // code here
        int n = arr.size();
        int t[n + 1][sum + 1];
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < sum + 1; j++) {
                if (i == 0)
                    t[i][j] = 0;
                if (j == 0)
                    t[i][j] = 1;
            }
        }
        for (int i = 1; i < n + 1; i++) {
            for (int j = 0; j < sum + 1; j++) {
                if (arr[i - 1] <= j) {
                    t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
                } else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }
        return t[n][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (auto it : nums) {
            sum += it;
        }
        int t = (sum + target) / 2;
        // cout<<t;
        if (target > sum || ((sum + target) % 2 != 0) || t < 0) {
            return 0;
        }
        // vector<vector<int>> dp(n, vector<int>(t + 1, -1));
        return isSubsetSum(nums, t);
    }
};