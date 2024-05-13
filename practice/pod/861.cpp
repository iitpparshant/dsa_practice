class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            int x = grid[i][0];
            if (x == 0) {
                for (int j = 0; j < m; j++) {
                    grid[i][j] = !grid[i][j];
                }
            }
        }
        int ans=0;
        int k=1;
        for(int i=m-1;i>=0;i--){
            int count=0;
            for(int j=0;j<n;j++){
                if(grid[j][i]==0){
                    count++;
                }
            }
            count= max(count,n-count);
            ans+= count*k;
            k*=2;
        }
        return ans;
    }
};