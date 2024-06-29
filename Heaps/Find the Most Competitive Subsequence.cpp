//  https://leetcode.com/problems/find-the-most-competitive-subsequence/description/

//                                  1673. Find the Most Competitive Subsequence


//                                   first method                   *********************

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        for(int i=0;i<n-k;i++){
            pq.push({nums[i],i});
        }
        int c=-1;
        vector<int>ans;
        for(int i=n-k;i<n;i++){
            pq.push({nums[i],i});
            while(pq.top()[1]<c){
                pq.pop();
            }
            ans.push_back(pq.top()[0]);
            c= pq.top()[1];
            pq.pop();
        }
        return ans;
    }
};



//                                      second method                             //


class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int r=n-i-1;
            while(!ans.empty() && ans.back()>nums[i] && ans.size()+r>=k){
                ans.pop_back();
            }
            ans.push_back(nums[i]);
        }
        return {ans.begin(),ans.begin()+k};
    }
};


