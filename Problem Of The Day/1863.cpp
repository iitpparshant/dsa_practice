class Solution {
public:

int solve(vector<int>&nums,int xr,int i){
    if(i==nums.size()){
        return xr;
    }
    int x= solve(nums,xr^nums[i],i+1);
    int y= solve(nums,xr,i+1);
    return (x+y);
}
    int subsetXORSum(vector<int>& nums) {
        return solve(nums,0,0);
    }
};