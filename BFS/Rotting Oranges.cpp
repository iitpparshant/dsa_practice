// https://leetcode.com/problems/rotting-oranges/description/

//                                                 994. Rotting Oranges

//                                            using BFS 

class Solution {
public:
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int count=0;
        while(!q.empty()){
            int s= q.size();
            count++;
            while(s--){
                auto node= q.front();
                q.pop();
                int x= node.first;
                int y= node.second;
                for(int i=0;i<4;i++){
                    int nx= x+dx[i];
                    int ny= y+dy[i];
                    if(nx>=0 && nx<n && ny>=0 && ny<m &&grid[nx][ny]==1){
                        q.push({nx,ny});
                        grid[nx][ny]=2;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
                // cout<<grid[i][j]<<" ";
            }
        }
        if(count==0){
            return 0;
        }
        return count-1;
    }
};


//                                                       using DFS

class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    void solve(vector<vector<int>>& grid, int i, int j, int min) {
        int n = grid.size();
        int m = grid[0].size();
        if (i < 0 || i >= n || j < 0 || j>=m || grid[i][j] == 0 ||(1<grid[i][j] && grid[i][j]<min)) {
            return;
        }
        grid[i][j]=min;
        solve(grid,i+1,j,min+1);
        solve(grid,i-1,j,min+1);
        solve(grid,i,j+1,min+1);
        solve(grid,i,j-1,min+1);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    solve(grid,i,j,2);
                }
            }
        }
        int ans=2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
                ans= max(ans,grid[i][j]);
                // cout<<grid[i][j]<<" ";
            }
        }
        return ans-2;
    }
};