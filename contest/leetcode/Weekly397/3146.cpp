class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int>a(26,0);
        vector<int>b(26,0);
        for(int i=0;i<s.size();i++){
            a[s[i]-'a']=i;
        }
        for(int i=0;i<t.size();i++){
            b[t[i]-'a']=i;
        }
        int count=0;
        for(int i=0;i<26;i++){
            count+= abs(a[i]-b[i]);
        }
        return count;
    }
};