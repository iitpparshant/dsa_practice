class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int>s(score.begin(),score.end());
        sort(s.begin(),s.end());
        unordered_map<int,int>mp;
        int n= s.size();
        for(int i=0;i<s.size();i++){
            mp[s[i]]= n-i;
        }
        vector<string>ans;
        for(int i=0;i<n;i++){
            if(score[i]==s[n-1]){
                ans.push_back("Gold Medal");
            }
            else if(score[i]==s[n-2]){
                ans.push_back("Silver Medal");
            }
            else if(score[i]==s[n-3]){
                ans.push_back("Bronze Medal");
            }
            else{
                ans.push_back((to_string)(mp[score[i]]));
            }
        }
        return ans;
    }
};