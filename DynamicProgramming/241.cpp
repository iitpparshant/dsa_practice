//   https://leetcode.com/problems/different-ways-to-add-parentheses/

// Different Ways to Add Parentheses

// *******  first Method  *******
class Solution {
public:
    vector<int> solve(string s, int idx, int n) {
        vector<int> ans;
        for (int i = idx; i < n; i++) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
                vector<int> l = solve(s, idx, i);
                vector<int> r = solve(s, i + 1, n);
                for (int it : l) {
                    for (int it1 : r) {
                        if (s[i] == '+') {
                            ans.push_back(it + it1);
                        } else if (s[i] == '-') {
                            ans.push_back(it - it1);
                        } else if (s[i] == '*') {
                            ans.push_back(it * it1);
                        }
                    }
                }
            }
        }
        if (ans.empty()) {
            ans.push_back(stoi(s.substr(idx, n - idx)));
        }
        return ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression, 0, expression.size());
    }
};

//  *** second Method ****


class Solution {
public:
    vector<int> solve(string s, int idx, int n,unordered_map<string,vector<int>>&dp) {
        vector<int> ans;
        for (int i = idx; i < n; i++) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
                vector<int> l;
                if(dp.find(s.substr(idx,i-idx))!=dp.end()){
                    l= dp[s.substr(idx,i-idx)];
                }
                else{
                    l= solve(s, idx, i,dp);
                }
                vector<int> r ;
                if(dp.find(s.substr(i+1,n-i-1))!=dp.end()){
                    r= dp[s.substr(i+1,n-i-1)];
                }
                else{
                    r = solve(s, i + 1, n,dp);
                }
                for (int it : l) {
                    for (int it1 : r) {
                        if (s[i] == '+') {
                            ans.push_back(it + it1);
                        } else if (s[i] == '-') {
                            ans.push_back(it - it1);
                        } else if (s[i] == '*') {
                            ans.push_back(it * it1);
                        }
                    }
                }
            }
        }
        if (ans.empty()) {
            ans.push_back(stoi(s.substr(idx, n - idx)));
        }
        dp[s]=ans;
        return ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        unordered_map<string, vector<int>> dp;
        return solve(expression, 0, expression.size(),dp);
    }
};