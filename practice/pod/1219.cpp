class Solution {
public:
int dx[4]={-1,1,0,0};
int dy[4]= {0,0,-1,1};
int solve(vector<vector<int>>&grid,int x,int y,int n,int m){
    if(x<0 || x>=n ||y<0 ||y>=m || grid[x][y]==0){
        return 0;
    }
    int curr= grid[x][y];
    grid[x][y]=0;
    int mx= curr;
    for(int i=0;i<4;i++){
        int nx= x+dx[i];
        int ny= y+dy[i];
        mx= max(mx,curr+ solve(grid,nx,ny,n,m));
    }
    grid[x][y]= curr;
    return mx;
}
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans= INT_MIN;
        int n=grid.size();
        int m= grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    ans= max(ans,solve(grid,i,j,n,m));
                }
            }
        }
        return ans;
    }
};