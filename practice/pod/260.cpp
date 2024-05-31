//     first method ******


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int  n= nums.size();
        sort(nums.begin(),nums.end());
        vector<int>ans;
        if(nums[0]!=nums[1]){
            ans.push_back(nums[0]);
        }
        if(nums[n-1]!=nums[n-2]){
            ans.push_back(nums[n-1]);
        }
        for(int i=1;i<=n-2;i++){
            if((nums[i]!=nums[i-1]) && (nums[i]!=nums[i+1])){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
}; 



//  ***   second method *********


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long long temp = 0;
        for (int i = 0; i < n; i++) {
            temp ^= nums[i];
        }
        int r = (temp & (temp - 1)) ^ temp;
        int f = 0;
        int s = 0;
        for (int i = 0; i < n; i++) {
            if (r &nums[i]) {
                f ^= nums[i];
            } else {
                s ^= nums[i];
            }
        }
        return {f,s};
    }
};