// https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/description/


//                       3201. Find the Maximum Length of Valid Subsequence I

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int o=0;
        int e=0;
        int n= nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                e++;
            }
            else{
                o++;
            }
        }
        int ans= max(o,e);
        int x=0;
        int y=0;
        int flag=0;
        int flag1=0;
        for(int i=0;i<n;i++){
            if(flag==0){
                if(nums[i]%2==0){
                    x++;
                    flag=1;
                }
            }
            else if(flag==1){
                if(nums[i]%2==1){
                    x++;
                    flag=0;
                }
            }
            if(flag1==0){
                if(nums[i]%2!=0){
                    y++;
                    flag1=1;
                }
            }
            else if(flag1==1){
                if(nums[i]%2==0){
                    y++;
                    flag1=0;
                }
            }
        }
        ans= max(ans,max(x,y));
        return ans;
    }
};