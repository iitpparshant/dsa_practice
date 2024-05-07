class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>>adj[n];
        for(auto it:edges){
            int u= it[0];
            int v= it[1];
            int w= it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        int ans=-1;
        int mincount=n;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            vector<int>dist(n,INT_MAX);
            dist[i]=0;
            pq.push({0,i});
            while(!pq.empty()){
                int d= pq.top().first;
                int node= pq.top().second;
                pq.pop();
                for(auto it:adj[node]){
                    int n= it.first;
                    int dis= it.second;
                    if(dis+d<dist[n]){
                        dist[n]= dis+d;
                        pq.push({dist[n],n});
                    }
                }
            }
            int count=0;
            for(int j=0;j<n;j++){
                if(dist[j]<=distanceThreshold){
                    count++;
                }
            }
            if(count<= mincount){
                mincount= count;
                ans= i;
            }
        }
        return ans;
    }
};