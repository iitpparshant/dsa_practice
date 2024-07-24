// https://leetcode.com/problems/sort-the-jumbled-numbers/description/

//                                      2191. Sort the Jumbled Numbers

class Solution {
public:
int convert(int x, const vector<int>& mapping) {
        if (x == 0) return mapping[0]; // Edge case for 0
        int z = 0;
        for (int pow10 = 1; x > 0; pow10 *= 10) {
            int q = x / 10;
            int r = x % 10;
            z += mapping[r] * pow10;
            x = q;
        }
        return z;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
         int n = nums.size();
        vector<pair<int, int>> mapNum(n);
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            mapNum[i] = make_pair(convert(x, mapping), i);
        }
        sort(mapNum.begin(), mapNum.end());
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = nums[mapNum[i].second];
        }
        return ans;
    }
};