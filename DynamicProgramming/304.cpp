//   https://leetcode.com/problems/range-sum-query-2d-immutable/

//   304. Range Sum Query 2D - Immutable

class NumMatrix {
public:
vector<vector<int>>pre;
int m,n;
    NumMatrix(vector<vector<int>>& matrix) {
        n= matrix.size();
        m= matrix[0].size();
        pre.resize(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                pre[i][j]= matrix[i-1][j-1]+pre[i-1][j]+pre[i][j-1]- pre[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return pre[row2+1][col2+1]- pre[row1][col2+1]-pre[row2+1][col1]+ pre[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */