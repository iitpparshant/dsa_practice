//   https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/

//    2492. Minimum Score of a Path Between Two Cities

//    Method   1 

class Solution {
public:
void solve(int s,vector<vector<vector<int>>>&graph,vector<bool>&vis,int &ans){
    if(vis[s]){
        return ;
    }
    vis[s]=true;
    for(auto it:graph[s]){
        ans= min(ans,it[1]);
        solve(it[0],graph,vis,ans);
    }
}
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<vector<int>>>graph(n+1);
        for(auto it:roads){
            graph[it[0]].push_back({it[1],it[2]});
            graph[it[1]].push_back({it[0],it[2]});
        }
        vector<bool>vis(n+1,false);
        int ans= INT_MAX;
        solve(1,graph,vis,ans);
        return ans;
    }
};



//    Method 2

class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DisjointSet ds(n);
        for(auto it:roads){
            ds.unionByRank(it[0],it[1]);
        }
        int ans= INT_MAX;
        for(auto it:roads){
            if(ds.findUPar(n)==ds.findUPar(it[0])){
                ans= min(ans,it[2]);
            }
        }
        return ans;
    }
};