// https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/

//                                              673. Number of Longest Increasing Subsequence

class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
        int mx = 0;
        for (int i = 0; i <= n - 1; i++) {
            for (int prev_index = 0; prev_index <= i - 1; prev_index++) {
                if (arr[prev_index] < arr[i] && 1 + dp[prev_index] > dp[i]) {
                    dp[i] = 1 + dp[prev_index];
                    cnt[i] = cnt[prev_index];
                } else if (arr[prev_index] < arr[i] &&
                           1 + dp[prev_index] == dp[i]) {
                    cnt[i] += cnt[prev_index];
                }
            }
            mx = max(mx, dp[i]);
        }

        int ans = 0;

        for (int i = 0; i <= n - 1; i++) {
            if (dp[i] == mx) {
                ans += cnt[i];
            }
        }

        return ans;
    }
};