//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Your code here
        long long res=0;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            res+= (i*1ll*a[i]);
        }
        long long ans=0;
        ans= max(ans,res);
        for(int i=0;i<n;i++){
            res= res- (sum-a[i])+(a[i]*1ll*(n-1));
            ans= max(ans,res);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends