// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/description/

//                        2134. Minimum Swaps to Group All 1's Together II

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int countOnes = accumulate(begin(nums), end(nums), 0);
        int i=0;
        int j=0;
        int count=0;
        int ans=0;
        while(j<2*n){
            if(nums[j%n]==1){
                count++;
            }
            if(j-i+1>countOnes){
                count-= nums[i%n];
                i++;
            }
            ans= max(ans,count);
            j++;
        }
        return countOnes-ans;
    }
};