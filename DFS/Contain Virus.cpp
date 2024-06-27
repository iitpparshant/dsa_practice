// https://leetcode.com/problems/contain-virus/description/

//                        749. Contain Virus

class Solution {
public:
    int solve(vector<vector<int>>& g, int r, int c, set<int>& s, int x) {
        int ans = 0;
        int n = g.size();
        int m = g[0].size();
        if (r < 0 || r >= n || c < 0 || c >= m || g[r][c] != 1) {
            return 0;
        }
        if (r + 1 < n && g[r + 1][c] == 0) {
            s.insert((r + 1) * m + c);
            ans++;
        }
        if (r - 1 >= 0 && g[r - 1][c] == 0) {
            s.insert((r - 1) * m + c);
            ans++;
        }
        if (c + 1 < m && g[r][c + 1] == 0) {
            s.insert(r * m + c + 1);
            ans++;
        }
        if (c - 1 >= 0 && g[r][c - 1] == 0) {
            s.insert(r * m + c - 1);
            ans++;
        }
        g[r][c] = x;
        ans += solve(g, r + 1, c,s,x);
        ans += solve(g, r - 1, c,s,x);
        ans += solve(g, r, c + 1,s,x);
        ans += solve(g, r, c - 1,s,x);
        return ans;
    }
    int containVirus(vector<vector<int>>& isInfected) {
        int n = isInfected.size();
        int m = isInfected[0].size();
            int ans = 0;
        while (true) {
            int c = 2;
            int mx = 0;
            int w=0;
            int r;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (isInfected[i][j] == 1) {
                        set<int> s;
                        int wall = solve(isInfected, i, j, s, c);
                        if (mx < s.size()) {
                            mx = s.size();
                            w = wall;
                            r = c;
                        }
                        c++;
                    }
                }
            }
            if(mx==0){
                break;
            }
            ans += w;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (isInfected[i][j] == r) {
                        isInfected[i][j] = 1e9;
                    } else if (isInfected[i][j] > 1 &&
                               isInfected[i][j] != 1e9) {
                        isInfected[i][j] = 1;
                        if (i + 1 < n && !isInfected[i + 1][j]) {
                            isInfected[i + 1][j] = 1;
                        }
                        if (i - 1 >= 0 && !isInfected[i - 1][j]) {
                            isInfected[i - 1][j] = 1;
                        }
                        if (j + 1 < m && !isInfected[i][j + 1]) {
                            isInfected[i][j + 1] = 1;
                        }
                        if (j - 1 >= 0 && !isInfected[i][j - 1]) {
                            isInfected[i][j - 1] = 1;
                        }
                    }
                }
            }
        }
        return ans;
    }
};