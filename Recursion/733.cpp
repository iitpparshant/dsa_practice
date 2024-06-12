// https://leetcode.com/problems/flood-fill/description/
//   733. Flood Fill

class Solution {
public:
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    void solve(vector<vector<int>>& image, int r, int c, int color, int co) {
        int n = image.size();
        int m = image[0].size();
        image[r][c] = color;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                if (image[nr][nc] == co) {
                    image[nr][nc] = color;
                    solve(image, nr, nc, color, co);
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int n = image.size();
        int m = image[0].size();
        int c = image[sr][sc];
        if (c == color) {
            return image;
        }
        solve(image, sr, sc, color, c);
        return image;
    }
};