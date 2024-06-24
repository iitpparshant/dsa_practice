//  https://leetcode.com/problems/minimum-average-of-smallest-and-largest-elements/description/

//      3194. Minimum Average of Smallest and Largest Elements

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        double ans = 100.0;
        for (int i = 0; i < n; i++) {
            double x = (nums[i] + nums[n - i - 1]) / 2.0;
            ans = min(ans, x);
        }
        return ans;
    }
};