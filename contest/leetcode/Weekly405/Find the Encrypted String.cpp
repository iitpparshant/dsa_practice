//  https://leetcode.com/problems/find-the-encrypted-string/description/
//                                    3210. Find the Encrypted String

class Solution {
public:
    string getEncryptedString(string s, int k) {
        string ans="";
        int n=s.size();
        k=k%n;
        for(int i=k;i<n;i++){
            ans+=s[i];
        }
        for(int i=0;i<k;i++){
            ans+=s[i];
        }
        return ans;
    }
};