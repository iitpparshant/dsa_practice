// https://leetcode.com/problems/largest-divisible-subset/description/

//                                   368. Largest Divisible Subset

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n= arr.size();
        vector<int> dp(n, 1), hash(n, 1);
        int mx = -1;
        int last = -1;
        for (int i = 0; i <= n - 1; i++) {
            hash[i] = i;
            for (int prev_index = 0; prev_index <= i - 1; prev_index++) {

                if ((arr[i]%arr[prev_index]==0) && 1 + dp[prev_index] > dp[i]) {
                    dp[i] = 1 + dp[prev_index];
                    hash[i] = prev_index;
                }
            }
            if (dp[i] > mx) {
                mx = dp[i];
                last = i;
            }
        }
        vector<int> ans;
        ans.push_back(arr[last]);
        while (hash[last] != last) {
            last = hash[last];
            ans.push_back(arr[last]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};