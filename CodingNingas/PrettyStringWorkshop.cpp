#include <bits/stdc++.h> 
vector<int> findCost(int n, string s, int m, vector<vector<int>> &queries)
{
    // Write your code here.
    vector<string>possComb={"abc","acb", "bca","bac","cba","cab"};
    vector<vector<int>>dp(6,vector<int>(n+1,0));
    for(int i=0;i<6;i++){
        int count=0;
        for(int j=1;j<n+1;j++){
            if(s[j-1]!=possComb[i][j%3]){
                count++;
            }
            dp[i][j]= count;
        }
    }
    vector<int>ans;
    for(int i=0;i<m;i++){
        int l= queries[i][0];
        int r= queries[i][1];
        int mn= INT_MAX;
        for(int j=0;j<6;j++){
            int cost = dp[j][r]-  dp[j][l-1];
            mn= min(mn,cost);
        }
        ans.push_back(mn);
    }
    return ans;
}