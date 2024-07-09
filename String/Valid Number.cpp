//  https://leetcode.com/problems/valid-number/description/

//                                              65. Valid Number

class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        bool hasNum = false;
        bool hasDot = false;
        bool hasE = false;
        bool numAfterE = true; // We assume true to handle cases without 'e' more easily

        for (int i = 0; i < n; ++i) {
            char c = s[i];

            if (c >= '0' && c <= '9') {
                hasNum = true;
                numAfterE = true;
            } else if (c == '.') {
                if (hasDot || hasE) return false;
                hasDot = true;
            } else if (c == 'e' || c == 'E') {
                if (hasE || !hasNum) return false;
                hasE = true;
                numAfterE = false; // Need a number after 'e'
            } else if (c == '+' || c == '-') {
                if (i != 0 && (s[i-1] != 'e' && s[i-1] != 'E')) return false;
                hasNum = false; // Reset num check for next valid sequence
            } else {
                return false;
            }
        }

        return hasNum && numAfterE;
    }
};
