class Solution {
public:
    long long solve(vector<int>& nums, int k, int s, bool isEven,
              vector<vector<long long>>& temp) {
        int n = nums.size();
        if (s == n) {
            if (isEven) {
                return 0;
            }
            return INfT_MIN;
        }
        if (temp[s][isEven] != -1) {
            return temp[s][isEven];
        }
        long long notake = nums[s] + solve(nums, k, s + 1, isEven, temp);
        long long take = (nums[s] ^ k) + solve(nums, k, s + 1, !isEven, temp);
        long long p = max(notake, take);
        return temp[s][isEven] = p;
    }
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        vector<vector<long long>> temp(nums.size(), vector<long long>(2, -1));
        return solve(nums, k, 0, 1, temp);
    }
};