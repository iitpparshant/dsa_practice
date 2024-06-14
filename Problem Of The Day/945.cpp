// https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/
// 945. Minimum Increment to Make Array Unique

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int x= nums[0];
        int count=0;
        for(int i=1;i<nums.size();i++){
            if(x>=nums[i]){
                int y= x-nums[i]+1;
                nums[i]+=y;
                count+=y;
            }
            // cout<<nums[i]<<" ";
            x= nums[i];
        }
        return count;
    }
};