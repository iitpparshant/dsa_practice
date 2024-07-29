// https://leetcode.com/problems/count-number-of-teams/description/

//                                                1395. Count Number of Teams

class Solution {
public:
int dp[1001][4][3];
int solve(vector<int>& arr,int idx,int take,int state){
    int n= arr.size();
    if(take==3){
        return 1;
    }
    int ele= arr[idx];
    int ans=0;
    if(dp[idx][take][state]!=-1){
        return dp[idx][take][state];
    }
    for(int i=idx+1;i<n;i++){
        if(state==0){
            if(ele<arr[i]){
                ans+= solve(arr,i,take+1,1);
            }
            else if(ele>arr[i]){
                ans+= solve(arr,i,take+1,2);
            }
        }
        else if(state==1){
            if(ele<arr[i]){
                ans+= solve(arr,i,take+1,1);
            }
        }
        else if(state==2){
            if(ele>arr[i]){
                ans+= solve(arr,i,take+1,2);
            }
        }
    }
    return dp[idx][take][state]= ans;
}
    int numTeams(vector<int>& rating) {
        memset(dp,-1,sizeof(dp));
        int n= rating.size();
        int ans=0;
        for(int i=0;i<=n-3;i++){
            int take=1;
            ans+= solve(rating,i,take,0);
        }
        return ans;
    }
};