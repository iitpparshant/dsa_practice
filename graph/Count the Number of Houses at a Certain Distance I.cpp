// https://leetcode.com/problems/count-the-number-of-houses-at-a-certain-distance-i/description/

//                                  3015. Count the Number of Houses at a Certain Distance I




//                             first method  DFS

class Solution {
public:
    void solve(vector<int> adj[], int k, int node, vector<int>& vis) {
        for (auto it : adj[node]) {
            if (vis[it] == -1 || vis[it] > k) {
                vis[it] = k + 1;
                solve(adj, k + 1, it, vis);
            }
        }
    }
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int> adj[n + 1];
        for (int i = 1; i < n; i++) {
            adj[i].push_back(i + 1);
            adj[i + 1].push_back(i);
        }
        adj[x].push_back(y);
        adj[y].push_back(x);
        vector<int> ans(n, 0);
        for (int i = 1; i <= n; i++) {
            vector<int> vis(n + 1, -1);
            vis[i] = 0;
            solve(adj, 0, i, vis);
            for (int j = 1; j <= n; j++) {
                if (vis[j] >0 && vis[j] <= n) {
                    ans[vis[j] - 1]++;
                }
                // cout<<ans[i-1]<<" ";
            }
            // cout<<"##";
        }
        return ans;
    }
};


//                                           second method BFS


class Solution {
public:
    void bfs(int src, unordered_map<int, list<int>>& adjList, vector<int>& ans){
        unordered_map<int, bool>visited;
        queue<int>q;
        visited[src] = 1;
        q.push(src);
        
        int level = 0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                int front = q.front();
                q.pop();
                for(auto& neighbour: adjList[front]){
                    if(!visited[neighbour]){
                        q.push(neighbour);
                        visited[neighbour] = 1;
                    }
                }
            }
            //updating each level of the answer with the size of that queue level
            ans[level] += (q.size());
            level++;
        }

    }
    vector<int> countOfPairs(int n, int x, int y) {
        unordered_map<int, list<int>>adj;
        for (int i = 1; i < n; i++) {
            adj[i].push_back(i + 1);
            adj[i + 1].push_back(i);
        }
        adj[x].push_back(y);
        adj[y].push_back(x);
        vector<int> ans(n, 0);
        for(int i=1;i<=n;i++){
            bfs(i,adj,ans);
        }
        return ans;
    }
};