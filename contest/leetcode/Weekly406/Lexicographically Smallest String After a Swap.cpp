// https://leetcode.com/problems/lexicographically-smallest-string-after-a-swap/description/

class Solution {
public:
    string getSmallestString(string s) {
        for(int i=0;i<s.size()-1;i++){
            if(s[i]>s[i+1]  && ((s[i]-'0')%2==(s[i+1]-'0')%2)){
                swap(s[i],s[i+1]);
                break;
            }
        }
        return s;
    }
};