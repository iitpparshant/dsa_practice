// https://leetcode.com/problems/knight-dialer/description/

//   ******   935. Knight Dialerv     ******

//  ***    METHOD 1  ***
class Solution {
public:
    int dx[8] = {2, 2, -2, -2, 1, -1, 1, -1};
    int dy[8] = {1, -1, 1, -1, 2, 2, -2, -2};
    int x = 0;
    int y = 0;
    int dp[5001][3][4];
    int ans=0;
    bool valid(int x, int y) {
        if (x == 1 && y == 0)
            return true;
        if (x < 0 || x > 2)
            return false;
        if (y < 1 || y > 3)
            return false;
        return true;
    }
    void nextPos() {
        while (x++) {
            if (x > 2) {
                x = 0;
                y++;
            }
            if (valid(x, y)) {
                return;
            }
            if (y > 4) {
                return;
            }
        }
    }
    int solve(int x,int y ,int n){
        if(n==1){
            return dp[n][x][y]=1;
        }
        int temp=0;
        if(dp[n][x][y]!=-1){
            return dp[n][x][y];
        }
        for(int i=0;i<8;i++){
            if(valid(x+dx[i],y+dy[i])){
                temp= (temp+ solve(x+dx[i],y+dy[i],n-1))%1000000007;
            }
        }
        return dp[n][x][y]= temp;
    }
    int knightDialer(int n) {
        int ans = 0;
         memset(dp, -1, sizeof(dp));
        for (int i = 0; i < 10; i++) {
            nextPos();
            // cout << x << y << " ";
            ans= (ans+solve(x,y,n))%1000000007;
        }
        return ans;
    }
};