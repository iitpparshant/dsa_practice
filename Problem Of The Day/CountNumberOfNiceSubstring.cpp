//   https://leetcode.com/problems/count-number-of-nice-subarrays/description/
 
//      1248. Count Number of Nice Subarrays

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int>count(n+1,0);
        count[0]=1;
        int t=0;
        int ans=0;
        for(auto it:nums){
            t+= (it&1);
            if(t>=k){
                ans+= count[t-k];
            }
            count[t]++;
        }
        return ans;
    }
};