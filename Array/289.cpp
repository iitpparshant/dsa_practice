//  https://leetcode.com/problems/game-of-life/description/

//   ****     289. Game of Life      ******


class Solution {
public:
    bool isValid(int x, int y, int n, int m) {
        if (x >= 0 && y >= 0 && x < n && y < m) {
            return true;
        }
        return false;
    }
    int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
    int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int one = 0;
                for (int k = 0; k < 8; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (isValid(x, y, n, m)) {
                        if (abs(board[x][y]) == 1) {
                            one++;
                        }
                    }
                }
                if (board[i][j] == 1) {
                    if (one < 2 || one > 3) {
                        board[i][j] = -1;
                    }
                } else if(board[i][j]==0) {
                    if (one == 3) {
                        board[i][j] = 2;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 2) {
                    board[i][j] = 1;
                } else if (board[i][j] == -1) {
                    board[i][j] = 0;
                }
            }
        }
    }
};