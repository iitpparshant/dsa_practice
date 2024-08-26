// https://leetcode.com/problems/maximum-value-sum-by-placing-three-rooks-i/description/

// 3256. Maximum Value Sum by Placing Three Rooks I

class Solution {
public:
long long dp[105][105][105];
    long long solve(int s, int fst, int sec,
                    vector<vector<pair<long long, long long>>>& arr) {
        if (s == arr.size()) {
            return -1e11;
        }
        long long ans = LONG_LONG_MIN;
        if(dp[s][fst+1][sec+1]!=-1){
            return dp[s][fst+1][sec+1];
        }
        if (fst == -1) {
            ans = max(ans, solve(s + 1, fst, sec, arr));
            ans = max(ans, arr[s][0].first +
                               solve(s + 1, arr[s][0].second, sec, arr));
            ans = max(ans, arr[s][1].first +
                               solve(s + 1, arr[s][1].second, sec, arr));
            ans = max(ans, arr[s][2].first +
                               solve(s + 1, arr[s][2].second, sec, arr));
        } else if (sec == -1) {
            ans = max(ans, solve(s + 1, fst, sec, arr));
            if (arr[s][0].second != fst) {
                ans = max(ans, arr[s][0].first +
                                   solve(s + 1, fst, arr[s][0].second, arr));
            }
            if (arr[s][1].second != fst) {
                ans = max(ans, arr[s][1].first +
                                   solve(s + 1, fst, arr[s][1].second, arr));
            }
            if (arr[s][2].second != fst) {
                ans = max(ans, arr[s][2].first +
                                   solve(s + 1, fst, arr[s][2].second, arr));
            }
        } else {
            ans = max(ans, solve(s + 1, fst, sec, arr));
            if ((arr[s][0].second != fst) && (arr[s][0].second != sec)) {
                ans = max(ans, arr[s][0].first);
            }
            if ((arr[s][1].second != fst) && (arr[s][1].second != sec)) {
                ans = max(ans, arr[s][1].first);
            }
            if ((arr[s][2].second != fst) && (arr[s][2].second != sec)) {
                ans = max(ans, arr[s][2].first);
            }
        }
        return dp[s][fst+1][sec+1]= ans;
    }
    long long maximumValueSum(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<pair<long long, long long>>> ans;
        for (int i = 0; i < n; i++) {
            vector<pair<long long, long long>> temp;
            for (int j = 0; j < m; j++) {
                temp.push_back({board[i][j], j});
            }
            sort(temp.begin(), temp.end(),
                 greater<pair<long long, long long>>());
            ans.push_back(temp);
        }
        memset(dp,-1,sizeof(dp));
        return solve(0, -1, -1, ans);
    }
};