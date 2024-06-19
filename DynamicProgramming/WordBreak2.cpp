//   https://leetcode.com/problems/word-break-ii/description/

//        140. Word Break II

class Solution {
public:
void solve(unordered_set<string>word,vector<string>&ans,int idx,string s,string curr){
    if(idx==s.size()){
        ans.push_back(curr);
        return ;
    }
    for(int i=idx+1;i<=s.size();i++){
        string t= s.substr(idx,i-idx);
        // cout<<t<<" ";
        if(word.find(t)!=word.end()){
            string prev= curr.empty()?t:(curr+" "+t);
            solve(word,ans,i,s,prev);
        }
    }
}
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>word(wordDict.begin(),wordDict.end());
        vector<string>ans;
        string curr;
        solve(word,ans,0,s,curr);
        return ans;
    }
};