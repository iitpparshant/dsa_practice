// https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/description/

//             995. Minimum Number of K Consecutive Bit Flips

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n= nums.size();
        int flag=0;
        vector<int>flip(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(i>=k){
                flag^=flip[i-k];
            }
            if(flag==nums[i]){
                if(i+k>n){
                    return -1;
                }
                flag^=1;
                flip[i]=1;
                count++;
            }
        }
        return count;
    }
};