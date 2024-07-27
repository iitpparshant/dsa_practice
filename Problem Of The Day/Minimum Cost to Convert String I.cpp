// https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/

//                            2976. Minimum Cost to Convert String I

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        int matrix[26][26];
        int n = 26;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = 1e9;
                if (i == j) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < original.size(); i++) {
            int x = original[i] - 'a';
            int y = changed[i] - 'a';
            matrix[x][y] = min(cost[i], matrix[x][y]);
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] =
                        min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < source.size(); i++) {
            int x = source[i] - 'a';
            int y = target[i] - 'a';
            if (x != y) {
                if (matrix[x][y] >= 1e9) {
                    return -1;
                } else {
                    ans += matrix[x][y];
                }
            }
        }
        return ans;
    }
};