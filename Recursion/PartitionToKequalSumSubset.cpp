//   https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/

//    698. Partition to K Equal Sum Subsets

class Solution {
public:
    bool solve(vector<int>& nums, int target, int curr, int idx, int k,
               vector<bool>& vis) {
        int n = nums.size();
        if (k == 0) {
            return true;
        }
        if (curr > target) {
            return false;
        }
        if (curr == target) {
            return solve(nums, target, 0, 0, k - 1, vis);
        }
        for (int i = idx; i < n; i++) {
            if (vis[i]) {
                continue;
            }
            vis[i] = true;
            if (solve(nums, target, curr + nums[i], i + 1, k, vis)) {
                return true;
            }
            vis[i] = false;
            if (curr == 0) {
                break;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (auto it : nums) {
            sum += it;
        }
        if (sum % k != 0) {
            return false;
        }
        int target = sum / k;
        int n = nums.size();
        vector<bool> vis(n, false);
        return solve(nums, target, 0, 0, k, vis);
    }
};