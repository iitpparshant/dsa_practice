//   https://leetcode.com/problems/first-missing-positive/description/

//         41. First Missing Positive

//        first method  
  class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n= nums.size();
        for(int i=0;i<n;i++){
            int x= nums[i];
            //  check 1<=x<=n 
            //  x is at correct position 
            // at index x-1 
            while(x>=1 && x<=n && x !=i+1  && nums[x-1]!=x){
                swap(nums[x-1],nums[i]);
                x= nums[i];
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return n+1;
    }
};


//           second method 

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n= nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                nums[i]=0;
            }
        }
        for(int i=0;i<n;i++){
            int x= abs(nums[i]);
            if(x>=1 && x<=n){
                if(nums[x-1]>0){
                    nums[x-1]*=-1;
                }
                else if(nums[x-1]==0){
                    nums[x-1]= -1*x;
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<nums[i]<<" ";
        // }
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                return i+1;
            }
        }
        return n+1;
    }
};