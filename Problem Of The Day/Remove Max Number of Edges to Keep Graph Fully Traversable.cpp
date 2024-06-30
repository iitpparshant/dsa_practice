// https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/description/


//                                  1579. Remove Max Number of Edges to Keep Graph Fully Traversable



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

    bool unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v){
            return false;
        }
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
        return true;
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
bool static comp(vector<int>& a, vector<int>& b) { return a[0] > b[0]; }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(),edges.end(),comp);
        DisjointSet Alice(n+1);
        DisjointSet Bob(n+1);
        int ma=1;
        int mb=1;
        int r=0;
        for(auto it:edges){
            if(it[0]==3){
                bool a= Alice.unionByRank(it[1],it[2]);
                bool b= Bob.unionByRank(it[1],it[2]);
                if(a==true){
                    ma++;
                }
                if(b==true){
                    mb++;
                }
                if(a==false && b==false){
                    r++;
                }
            }
            else if(it[0]==1){
                bool a= Alice.unionByRank(it[1],it[2]);
                if(a==true){
                    ma++;
                }
                else{
                    r++;
                }
            }
            else if(it[0]==2){
                bool b= Bob.unionByRank(it[1],it[2]);
                if(b==true){
                    mb++;
                }
                else{
                    r++;
                }
            }
        }
        if(ma!=n ||mb!=n){
            return -1;
        }
        return r;
    }
};