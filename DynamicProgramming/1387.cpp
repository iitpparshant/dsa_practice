class Solution {
public:
unordered_map<int,int>dp;
int solve(int x){
    if(x==1){
        return 0;
    }
    if(dp.find(x)!=dp.end()){
        return dp[x];
    }
    if(x%2==0){
        return dp[x]=1+solve(x/2);
    }
    else{
        return dp[x]=1+solve(3*x+1);
    }
}
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>>ans;
        for(int i=lo;i<=hi;i++){
            ans.push_back({solve(i),i});
        }
        sort(ans.begin(),ans.end());
        return ans[k-1].second;
    }
};