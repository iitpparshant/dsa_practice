class Solution {
public:
vector<int>solve(vector<vector<int>>&g,int node){
    queue<pair<int,int>>q;
    q.push({node,0});
    int n= g.size();
    vector<int>dist(n,INT_MAX);
    dist[node]=0;
    while(!q.empty()){
        auto curr= q.front();
        q.pop();
        int d= curr.second;
        int newnode= curr.first;
        for(auto it:g[newnode]){
            if(d+1<dist[it]){
                dist[it]= d+1;
                q.push({it,d+1});
            }
        }
    }
    return dist;
}
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n= edges.size();
        vector<vector<int>>g(n);
        for(int i=0;i<n;i++){
            if(edges[i]!=-1){
                g[i].push_back(edges[i]);
            }
        }
        vector<int>a= solve(g,node1);
        vector<int>b= solve(g,node2);
        int diff=INT_MAX;
        int ans=-1;
        for(int i=0;i<n;i++){
            if(a[i] != INT_MAX && b[i] != INT_MAX &&(diff>max(a[i],b[i]))){
                diff= max(a[i],b[i]);
                ans=i;
            }
            // cout<<a[i]<<"**"<<b[i]<<" ";
        }
        return ans;
    }
};