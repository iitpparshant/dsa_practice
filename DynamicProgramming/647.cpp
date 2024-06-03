//   https://leetcode.com/problems/palindromic-substrings/description/

//  ********   647. Palindromic Substrings  *******


// Method 1  ******
class Solution {
public:
    int solve(string s, int l, int r) {
        int count = 0;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
            count++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int e = solve(s, i, i + 1);
            int o = solve(s, i, i);
            ans += e + o;
        }
        return ans;
    }
};

//*****************           Method 2  ***********

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = true;
            ans++;
        }
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                ans++;
            }
        }
        for (int i = 3; i <= n; i++) {
            for (int j = 0; j < n - i + 1; j++) {
                if (s[j] == s[j + i - 1] && dp[j + 1][j + i - 2]) {
                    dp[j][j + i - 1] = true;
                    ans++;
                }
            }
        }
        return ans;
    }
};


//*****************           Method 3  ***********

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < n - i + 1; j++) {
                if (s[j] == s[j + i - 1] && (i <= 2 || dp[j + 1][j + i - 2])) {
                    dp[j][j + i - 1] = true;
                    ans++;
                }
            }
        }
        return ans;
    }
};