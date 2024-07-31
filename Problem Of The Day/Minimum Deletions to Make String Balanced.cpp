// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/

//                            1653. Minimum Deletions to Make String Balanced

class Solution {
public:
    int dp[100001];
    int solve(string& s, int idx, int& cnt) {
        int n = s.size();
        if (idx >= n) {
            return 0;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        int a = solve(s, idx + 1, cnt);
        if (s[idx] == 'a') {
            cnt++;
        } else {
            a = min(a + 1, cnt);
        }
        return dp[idx] = a;
    }
    int minimumDeletions(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        int cnt = 0;
        int ans= solve(s, 0, cnt);
        // for(int i=0;i<n;i++){
        //     cout<<dp[i]<<" ";
        // }
        return ans;
    }
};