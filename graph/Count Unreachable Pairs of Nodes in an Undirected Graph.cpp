// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/

//                         2316. Count Unreachable Pairs of Nodes in an Undirected Graph

class Solution {
public:
long long solve(int node,vector<vector<int>> &adj,vector<int>&vis){
    vis[node]=1;
    long long ans=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            ans+= solve(it,adj,vis);
        }
    }
    return ans;
}
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n);
        long long sum=0;
        long long a=0;
        for (int i=0;i<n;i++){
            if(!vis[i]){
                long long count= solve(i,adj,vis);
                sum+= (count*count);
                a+=count;
            }
        }
        return ((a*a)-sum)/2;
    }
};