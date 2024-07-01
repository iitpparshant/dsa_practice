// https://leetcode.com/problems/next-greater-element-i/description/

//                      496. Next Greater Element I

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        stack<int>s;
        for(auto it:nums2){
            int x= it;
            while(!s.empty() && x>s.top()){
                mp[s.top()]=x;
                s.pop();
            }
            s.push(x);
        }
        while(!s.empty()){
            mp[s.top()]=-1;
            s.pop();
        }
        vector<int>ans;
        for(auto it:nums1){
            ans.push_back(mp[it]);
        }
        return ans;
    }
};