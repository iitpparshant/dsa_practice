// https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-ii/description/

//           3192. Minimum Operations to Make Binary Array Elements Equal to One II

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n= nums.size();
        int count=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(count%2==0){
                if(nums[i]%2==0){
                    count++;
                }
            }
            else{
                if(nums[i]%2!=0){
                    count++;
                }
            }
        }
        return count;
    }
};