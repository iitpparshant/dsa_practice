//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int mod=1e9+7;
  long power(long a,long b){
        long ans=1;
        
        while(b>0){
            
            if(b%2==1)  ans*=a;
            b>>=1;
            a*=a;
            a%=mod;
            ans%=mod;
            
        }
        return ans;
    }
    int numberOfConsecutiveOnes(int n) {
        // code here
        if(n==2)    return 1;
        if(n==3)    return 3;
        long dp[n+1];
        dp[2] = 1;
        dp[3] = 3;
        for(int i=4;i<=n;i++){
            dp[i] = (dp[i-1] + power(2,i-2)%mod + dp[i-2])%mod;
        }
        return dp[n];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends