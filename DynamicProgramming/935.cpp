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

//   *****    METHOD 2  ***********

class Solution {
public:
int m=1000000007;
int solve(int n,int i,int count,vector<vector<int>>&map,vector<vector<int>>&dp){
    if(count==n){
        return 1;
    }
    if(dp[i][count]!=-1){
        return dp[i][count];
    }
    int sum=0;
    for(auto it:map[i]){
        int temp= solve(n,it,count+1,map,dp)%m;
        sum= (sum%m+temp)%m;
    }
    return dp[i][count]= sum;
}
    int knightDialer(int n) {
        vector<vector<int>>map={{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
        int ans=0;
        vector<vector<int>>dp(10,vector<int>(n+1,-1));
        for(int i=0;i<10;i++){
            int temp = solve(n,i,1,map,dp);
            ans= (ans%m+ temp)%m;
        }
        return ans;
    }
};