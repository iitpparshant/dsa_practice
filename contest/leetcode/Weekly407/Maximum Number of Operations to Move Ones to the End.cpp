// https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/description/

//   3228. Maximum Number of Operations to Move Ones to the End

class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int x = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                x++;
                if (i < n - 1 && s[i + 1] == '0') {
                    count += x;
                }
            }
        }

        return count;
    }
};