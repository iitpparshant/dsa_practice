class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string,int>mp;
        int count=0;
        for(int i=0;i<word.size();i+=k){
            mp[word.substr(i,k)]++;
            count= max(count,mp[word.substr(i,k)]);
        }
        return word.size()/k-count;
    }
};