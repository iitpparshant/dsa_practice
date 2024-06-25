//   https://leetcode.com/problems/delete-and-earn/description/

//                           740. Delete and Earn

//                         first method

class Solution {
public:
int dp[20001];
int solve(vector<int>&arr,int idx){
    int ans=0;
    int n= arr.size();
    if(idx==n){
        return 0;
    }
    if(dp[idx]!=-1){
        return dp[idx];
    }
    int curr= arr[idx];
    int currS= arr[idx];
    int i= idx+1;
    while(i<n && arr[i]==curr){
        currS+= arr[i];
        i++;
    }
    int x=i;
    while(i<n && arr[i]==curr+1){
        i++;
    }
    return dp[idx]= max(currS+solve(arr,i),solve(arr,x));
}
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        memset(dp,-1,sizeof(dp));
        return solve(nums,0);
    }
};



//                             second method  

class Solution {
public:
    int dp[11000];
    int solve(vector<int>& v, int n) {
        if (n >= 10001) {
            return 0;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        int s1 = n * v[n] + solve(v, n + 2);
        int s2 = solve(v, n + 1);
        return dp[n] = max(s1, s2);
    }
    int deleteAndEarn(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        vector<int> v(1e4 + 1, 0);
        for (auto it : nums) {
            v[it]++;
        }
        return solve(v, 1);
    }
};