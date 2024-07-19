// https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/

//                                          1380. Lucky Numbers in a Matrix

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> ans;
        for (int i = 0; i < matrix.size(); i++) {
            int idx = -1;
            int mn = INT_MAX;
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] < mn) {
                    mn = matrix[i][j];
                    idx = j;
                }
            }
            bool flag = true;
            for (int k = 0; k < matrix.size(); k++) {
                if (matrix[k][idx] > mn) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans.push_back(mn);
            }
        }
        return ans;
    }
};