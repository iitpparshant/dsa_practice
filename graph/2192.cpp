class Solution {
public:
void solve(vector<vector<int>>&graph , vector<vector<int>>&ans,int node,int e){
    // vis[node]=1;
    for(auto &it:graph[node]){
        if(ans[it].empty()|| ans[it].back()!=e){
        ans[it].push_back(e);
        solve(graph,ans,it,e);
        }
    }
}
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
       vector<vector<int>>graph(n),ans(n);
       for(auto &it:edges){
        graph[it[0]].push_back(it[1]);
       }  
       for(int i=0;i<n;i++){
        // vector<bool> vis(n);
        solve(graph,ans,i,i);
       }
       return ans;
    }
};