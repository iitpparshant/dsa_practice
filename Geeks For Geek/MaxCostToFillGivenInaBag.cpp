//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  int dp[201][201];
  int solve(int s,int w,vector<int>&cost){
       if(w==0){
           return 0;
       }
       if(s<0){
           return 1e9;
       }
       if(dp[s][w]!=-1){
           return dp[s][w];
       }
       int nt= solve(s-1,w,cost);
       int t= 1e9;
       if(s+1<=w && cost[s]!=-1){
           t= cost[s]+solve(s,w-(s+1),cost);
       }
       return dp[s][w]= min(nt,t);
  }
    int minimumCost(int n, int w, vector<int> &cost) {
        // code here
        memset(dp,-1,sizeof(dp));
        int ans=solve(n-1,w,cost);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends