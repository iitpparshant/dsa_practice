//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
//   long long dp[26][4][3];
//   int dx[5] = {0, 0, 1, 0, -1};
//   int dy[5] = {0, 1, 0, -1, 0};
//   bool isValid(int i,int j){
//       if(i>=0 && j>=0 && i<4 && j<3){
//           if(i==3 && j==0){
//               return false;
//           }
//           else if(i==3 && j==2){
//               return false;
//           }
//           return true;
//       }
//       return false;
//   }
//   long long solve(int i,int j,int n){
//       if(n<=0){
//           return 0;
//       }if(n==1){
//           return dp[n][i][j]=1;
//       }
//       if(dp[n][i][j]!=-1){
//           return dp[n][i][j];
//       }
//       long long res=0;
//       for(int k=0;k<5;k++){
//           int x= i+dx[k];
//           int y= j+dy[k];
//           if(isValid(x,y)){
//               res+= solve(x,y,n-1);
//           }
//       }
//       return dp[n][i][j]= res;
//   }
    long long getCount(int n) {
        // Your code goes here
        
        //    *****    First method *******
         
        // memset(dp, -1, sizeof(dp));
        // long long ans=0;
        // for(int i=0;i<4;i++){
        //     for(int j=0;j<3;j++){
        //         if(isValid(i,j)){
        //             // cout<<i<<j<<" ";
        //             ans+= solve(i,j,n);
        //         }
        //     }
        // }
           
           
        //    *** second method ******
        
        if(n==1){
            return 10;
        }
        vector<vector<int>>adj={
            {0,8},{1,2,4},{2,1,3,5},{3,2,6},{4,1,5,7},
            {5,2,4,6,8},{6,3,5,9},{7,4,8},{8,5,7,9,0},{9,6,8}
        };
        vector<vector<long long>> dp(n + 1, vector<long long>(10, 0));
        for(int i=0;i<10;i++){
            dp[1][i]=1;
        }
        for(int i=2;i<=n;i++){
            for(int j=0;j<10;j++){
                dp[i][j]=0;
                for(auto it:adj[j]){
                    dp[i][j]+=dp[i-1][it];
                }
            }
        }
        long long ans=0;
        for(int i=0;i<10;i++){
            ans+= dp[n][i];
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends