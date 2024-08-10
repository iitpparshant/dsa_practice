// https://leetcode.com/problems/most-profitable-path-in-a-tree/description/

//                                       2467. Most Profitable Path in a Tree

class Solution {
public:
 bool vis[100002];
 vector<int>adj[100002];
 int par[100002];
 int level [100002];
 long long mx=-1e9;
 vector<int>amt;
 void dfs(int s,int p){
    par[s]=p;
    vis[s]=true;
    for(auto it:adj[s]){
        if(!vis[it]){
            level[it]= level[s]+1;
            dfs(it,s);
        }
    }
 }
 void solve(int node,int l,long long sum){
    vis[node]= true;
    if(l<level[node]){
        sum+=amt[node];
    }
    else if(l==level[node]){
         sum+=(amt[node]/2);
    }
    if(node!=0 && adj[node].size()==1){
        mx= max(mx,sum);
    }
    for(auto it:adj[node]){
        if(!vis[it]){
            solve(it,l+1,sum);
        }
    }
 }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n= edges.size();
        amt= amount;
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<=n;i++){
            level[i]= 1e9;
        }
        memset(vis,false,sizeof(vis));
        level[bob]=0;
        dfs(bob,-1);
        int node=0;
        map<int,bool>mp;
        while(par[node]!=-1){
            mp[node]= true;
            node= par[node];
        }
        mp[bob]= true;
        for(int i=0;i<n+1;i++){
            if(!mp[i]){
                level[i]= 1e9;
            }
        }
        memset(vis,false,sizeof(vis));
        int l=0;
        long long sum=0;
        solve(0,l,sum);
        return mx;
    }
};