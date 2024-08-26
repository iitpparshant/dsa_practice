// https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/

// 718. Maximum Length of Repeated Subarray

//   first method

class Solution {
public:
    int dp[1001][1001];
    int res = 0;
    int solve(int x, int y, vector<int>& nums1, vector<int>& nums2) {
        if (x >= nums1.size() || y >= nums2.size()) {
            return 0;
        }
        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        int a = 0;
        if (nums1[x] == nums2[y]) {
            a = 1 + solve(x + 1, y + 1, nums1, nums2);
            res = max(res, a);
        }
        solve(x + 1, y, nums1, nums2);
        solve(x, y + 1, nums1, nums2);
        return dp[x][y] = a;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof(dp));
        solve(0, 0, nums1, nums2);
        return res;
    }
};



//             second method 

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), mx = 0;
        vector<int> curr(m+1, 0);
        for(int i=1;i<=n;i++){
            for(int j=m;j>0;j--){
                if(nums2[j-1]==nums1[i-1]){
                    curr[j] = curr[j-1] + 1;
                    mx = max(curr[j], mx);
                }
                else{
                    curr[j]=0;
                }
            }
        }
        return mx;
    }
};