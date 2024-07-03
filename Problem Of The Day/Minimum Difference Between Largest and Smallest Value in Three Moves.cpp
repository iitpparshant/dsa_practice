// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/

//                      1509. Minimum Difference Between Largest and Smallest Value in Three Moves

class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n <= 4) {
            return 0;
        }
        int ans = INT_MAX;
        for (int i = 0; i <= 3; i++) {
            ans = min(ans, nums[n + i - 1 - 3] - nums[i]);
        }
        return ans;
    }
};