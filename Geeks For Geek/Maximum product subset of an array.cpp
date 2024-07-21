// https://www.geeksforgeeks.org/problems/maximum-product-subset-of-an-array/1

//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        if(arr.size()==1){
            return arr[0];
        }
        long long ans=1;
        int zero=0,nzero=0,mx= INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=0){
                ans= (ans*arr[i])%1000000007;
                nzero=1;
            }
            else{
                zero=1;
            }
            if(arr[i]<0 && arr[i]>mx){
                mx= arr[i];
            }
        }
        if(nzero!=1){
            return 0;
        }
        if(arr.size()==2 && zero==1 && ans<0){
            return 0;
        }
        if(ans<0){
            ans/=mx;
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends