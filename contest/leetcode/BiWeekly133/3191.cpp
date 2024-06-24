//  https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/description/

//        3191. Minimum Operations to Make Binary Array Elements Equal to One I


class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n= nums.size();
        int count=0;
        for(int i=0;i<=n-3;i++){
            if(nums[i]==0){
                nums[i]=1;
                nums[i+1]=1-nums[i+1];
                nums[i+2]=1-nums[i+2];
                count++;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                return -1;
            }
        }
        return count;
    }
};