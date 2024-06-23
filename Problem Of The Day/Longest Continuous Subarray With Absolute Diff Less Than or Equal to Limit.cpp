//   https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/

//            1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

 class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        deque<int> mx;
        deque<int> mn;
        while (j < n) {
            int x = nums[j];
            while (!mx.empty() && x > mx.back()) {
                mx.pop_back();
            }
            mx.push_back(x);
            while (!mn.empty() && x < mn.back()) {
                mn.pop_back();
            }
            mn.push_back(x);
            if (mx.front() - mn.front() > limit) {
                if (nums[i] == mx.front()) {
                    mx.pop_front();
                }
                if (nums[i] == mn.front()) {
                    mn.pop_front();
                }
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};