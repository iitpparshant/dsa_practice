// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/

//                       1493. Longest Subarray of 1's After Deleting One Element

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0,j=0,count=0;
        int n= nums.size();
        int ans=0;
        while(i<n){
            if(nums[i]==0){
                count++;
            }
            if(count>1){
                count=1;
                while(j<=i && nums[j]==1){
                    j++;
                }
                j++;
            }
            ans= max(ans,i-j);
            i++;
        }
        return ans;
    }
};