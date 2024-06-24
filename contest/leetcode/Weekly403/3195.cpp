//  https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/description/


//         3195. Find the Minimum Area to Cover All Ones I


class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        int x1=m;
        int x2=0;
        int y1=n;
        int y2=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    y1= min(y1,j);
                    y2= max(y2,j);
                    x1= min(x1,i);
                    x2= max(x2,i);
                }
            }
        }
        return (x2-x1+1)*(y2-y1+1);
    }
};