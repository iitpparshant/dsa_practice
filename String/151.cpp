// https://leetcode.com/problems/reverse-words-in-a-string/description/

//   151. Reverse Words in a String

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.size();
        int i = 0;
        while (i < n) {
            while (i < n && s[i] == ' ') {
                i++;
            }
            string p;
            while (i < n && s[i] != ' ') {
                p += s[i];
                i++;
            }
            if (p.size() > 0) {
                if (ans != "") {
                    ans = p + ' ' + ans;
                } else {
                    ans = p;
                }
            }
        }
        return ans;
    }
};