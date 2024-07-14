// https://leetcode.com/problems/minimum-cost-for-cutting-cake-i/description/

class Solution {
public:
    int dp[21][21][21][21];

    int solve(int c, int r, int m, int n, vector<int>& h, vector<int>& v) {
        if (c >= m && r >= n) {
            return 0;
        }
        if (dp[c][r][m][n] != -1) {
            return dp[c][r][m][n];
        }

        int res = INT_MAX;
        for (int i = c; i < m; i++) {
            int ans = h[i] + solve(c, r, i, n, h, v) + solve(i + 1, r, m, n, h, v);
            res = min(res, ans);
        }
        for (int j = r; j < n; j++) {
            int ans = v[j] + solve(c, r, m, j, h, v) + solve(c, j + 1, m, n, h, v);
            res = min(res, ans);
        }

        return dp[c][r][m][n] = res;
    }

    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, m-1, n-1, horizontalCut, verticalCut);
    }
};