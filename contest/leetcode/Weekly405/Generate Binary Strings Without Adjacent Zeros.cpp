// https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros/description/
//                            3211. Generate Binary Strings Without Adjacent Zeros

class Solution {
public:
void solve(int n,string s,vector<string>&ans){
    if(n==0){
        ans.push_back(s);
        return;
    }
    if(s.empty()|| s[s.size()-1]!='0'){
        solve(n-1,s+'0',ans);
    }
    solve(n-1,s+'1',ans);
}
    vector<string> validStrings(int n) {
        vector<string>ans;
        solve(n,"",ans);
        return ans;
    }
};