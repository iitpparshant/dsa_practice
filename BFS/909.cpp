//   https://leetcode.com/problems/snakes-and-ladders/description/
//    **********    909. Snakes and Ladders

class Solution {
public:
    int value(int x, int n, vector<vector<int>>& board) {
        int r = (x - 1) / n;
        int c = (x - 1) % n;
        if (r % 2) {
            c = n - 1 - c;
        }
        r = n - 1 - r;
        return board[r][c];
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<pair<int, int>> q;
        q.push({1, 0});
        vector<int> vis(n * n + 1, 0);
        vis[1] = 1;
        while (!q.empty()) {
            int val = q.front().first;
            int move = q.front().second;
            q.pop();
            if (val == n * n) {
                return move;
            }
            for (int i = val + 1; i <= min(val + 6, n * n); i++) {
                if (vis[i] == 1) {
                    continue;
                }
                vis[i] = 1;
                int p = value(i, n, board);
                if (p == -1) {
                    q.push({i, move + 1});
                } else {
                    if (value(p, n, board) == -1) {
                        vis[p] = 1;
                    }
                    q.push({p, move + 1});
                }
            }
        }
        return -1;
    }
};