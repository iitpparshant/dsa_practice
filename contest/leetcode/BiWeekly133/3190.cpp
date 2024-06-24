//   https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/description/

//  3190. Find Minimum Operations to Make All Elements Divisible by Three

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count=0;
        for(auto it:nums){
            int x= it%3;
            count+= min(x,3-x);
        }
        return count;
    }
};