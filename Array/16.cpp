//   https://leetcode.com/problems/3sum-closest/description/

//   ****   16. 3Sum Closest          ****

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n= nums.size();
        if(n==3){
            return nums[0]+nums[1]+nums[2];
        }
        int maxsum= nums[n-1]+nums[n-2]+nums[n-3];
        if(maxsum<=target){
            return maxsum;
        }
        int minsum= nums[0]+nums[1]+nums[2];
        if(minsum>=target){
            return minsum;
        }
        int ans= minsum;
        int dist=abs(minsum-target);
        for(int i=0;i<n-2;i++){
            int l=i+1;
            int r= n-1;
            while(l<r){
                int sum= nums[i]+nums[l]+nums[r];
                if(sum==target){
                    return sum;
                }
                if(abs(sum-target)<dist){
                    ans= sum;
                    dist= abs(sum-target);
                }
                if(sum<target){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return ans;
    }
};