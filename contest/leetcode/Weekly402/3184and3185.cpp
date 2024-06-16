class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        long long ans=0;
        int n= hours.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int x= hours[i]%24;
            mp[x]++;
        }
        // cout<<mp[0];
        ans+= static_cast<long long>(mp[0])*(mp[0]-1)/2;
         ans+= static_cast<long long>(mp[12])*(mp[12]-1)/2;
        for(int i=1;i<12;i++){
             ans+= static_cast<long long>(mp[i])*(mp[24-i]);
        }
        return ans;
    }
};