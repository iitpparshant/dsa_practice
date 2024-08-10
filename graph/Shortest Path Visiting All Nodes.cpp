// https://leetcode.com/problems/shortest-path-visiting-all-nodes/description/

//                            847. Shortest Path Visiting All Nodes

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n= graph.size();
        if(n==1 || n==0){
            return 0;
        }
        queue<pair<int,int>>q;
        set<pair<int,int>>vis;
        for(int i=0;i<n;i++){
            int x= (1<<i);
            q.push({i,x});
            vis.insert({1,x});
        }
        int total= (1<<n)-1;
        int count=0;
        while(!q.empty()){
            int size= q.size();
            count++;
            while(size--){
                auto curr= q.front();
                q.pop();
                int node= curr.first;
                int d= curr.second;
                for(auto it:graph[node]){
                    int nd= (d|(1<<it));
                    if(nd==total){
                        return count;
                    }
                    if(vis.find({it,nd})==vis.end()){
                        q.push({it,nd});
                        vis.insert({it,nd});
                    }
                }
            }
        }
        return -1;
    }
};