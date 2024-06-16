//  https://leetcode.com/problems/k-diff-pairs-in-an-array/description/
//   532. K-diff Pairs in an Array

//   method -1   Maps 

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count=0;
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto it:mp){
            if(k==0){
                if(it.second>1){
                    count++;
                }
            }
            else if(mp.find(it.first+k)!=mp.end()){
                count++;
            }
        }
        return count;
    }
};

//  Method -2 Two-Pointer

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count=0;
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto it:mp){
            if(k==0){
                if(it.second>1){
                    count++;
                }
            }
            else if(mp.find(it.first+k)!=mp.end()){
                count++;
            }
        }
        return count;
    }
};

//  method -3  Binary Search

class Solution {
public:
int solve(vector<int>v,int s,int ele){
    int e= v.size()-1;
    while(s<=e){
        int m= (s+e)/2;
        if(v[m]==ele){
            return m;
        }
        else if(v[m]>ele){
            e=m-1;
        }
        else{
            s=m+1;
        }
    }
    return -1;
}
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count=0;
        set<pair<int,int>>s;
        for(int i=0;i<nums.size();i++){
            if(solve(nums,i+1,nums[i]+k)!=-1){
                s.insert({nums[i],nums[i]+k});
            }
        }
        return s.size();
    }
};
