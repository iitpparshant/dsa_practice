//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        set<int>s1;
        set<int>s2;
        int sum1=0;
        int sum2=0;
        for(int i=0;i<n;i++){
            sum1+=a[i];
            s1.insert(a[i]);
        }
        for(int i=0;i<m;i++){
            sum2+=b[i];
        }
        if((sum2-sum1)%2!=0){
            return -1;
        }
        for(int i=0;i<m;i++){
            if(s1.find((sum1-sum2)/2+b[i])!=s1.end()){
                return 1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends