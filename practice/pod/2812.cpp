class Solution {
public:
vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n= grid.size();
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            auto [r,c]= q.front();
            q.pop();
            for(auto &it:dir){
                int nr= r+it[0];
                int nc= c+it[1];
                if(nr>=0 && nr<n && nc>=0 && nc<n && dist[nr][nc]==INT_MAX){
                    dist[nr][nc]= dist[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({dist[0][0],{0,0}});
        vector<vector<int>>safe(n,vector<int>(n,-1));
        safe[0][0]= dist[0][0];
        while(!pq.empty()){
            auto [d,pos]= pq.top();
            pq.pop();
            int r= pos.first;
            int c= pos.second;
            if(r==n-1 && c==n-1){
                return d;
            }
            for(auto &it:dir){
                int nr= r+it[0];
                int nc= c+it[1];
                if(nr>=0 && nr<n && nc>=0 && nc<n){
                    int nsafe= min(d,dist[nr][nc]);
                    if(nsafe> safe[nr][nc]){
                        safe[nr][nc]= nsafe;
                        pq.push({nsafe,{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};