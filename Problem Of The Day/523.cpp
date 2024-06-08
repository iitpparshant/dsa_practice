//   https://leetcode.com/problems/continuous-subarray-sum/description/
//  *******      523. Continuous Subarray Sum        *****

// METHOD 1   

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] && nums[i] == 0) {
                return true;
            }
            sum += nums[i];
            if (sum % k == 0) {
                return true;
            }
            int s = 0;
            int temp = sum;
            while ((i - s) > 1 && temp >= k) {
                temp -= nums[s];
                s++;
                if (temp % k == 0) {
                    return true;
                }
            }
        }
        return false;
    }
};

//   METHOD 2

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int r = k == 0 ? sum : sum % k;
            if (mp.count(r)) {
                if (i - mp[r] > 1) {
                    return true;
                }
            } else {
                mp[r] = i;
            }
        }
        return false;
    }
};