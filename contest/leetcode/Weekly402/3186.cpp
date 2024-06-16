// https://leetcode.com/problems/maximum-total-damage-with-spell-casting/
//   3186. Maximum Total Damage With Spell Casting

class Solution {
public:
    long long solve(vector<int>& power, int idx, map<int, int>& mp,
              vector<long long>& dp) {
        if (idx >= power.size()) {
            return 0;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        int nextidx = idx + 1;
        long long nottake = solve(power, nextidx, mp, dp);
        long long take=0;
        while (nextidx < power.size() && power[nextidx] - power[idx] <= 2) {
            nextidx++;
        }
        take=  ((1LL) * mp[power[idx]] * power[idx]) +
                          solve(power, nextidx, mp, dp);
        return dp[idx] = max(nottake, take);
    }
    long long maximumTotalDamage(vector<int>& power) {
        map<int, int> mp;
        vector<int> unique;
        for (auto it : power) {
            mp[it]++;
        }
        for (auto it : mp) {
            unique.push_back(it.first);
        }
        vector<long long> dp(mp.size(), -1);
        return solve(unique, 0, mp, dp);
    }
};