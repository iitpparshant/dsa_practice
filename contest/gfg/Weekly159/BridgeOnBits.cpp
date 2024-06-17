//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int makeBridgeOne(int n, vector<long long> &arr) {
        // code here
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            long long x=arr[i];
            for(int j=0;j<60;j++){
                if((1LL<<j)&x){
                    mp[j]++;
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<60;i++){
            if(mp.find(i)!=mp.end()){
            //   ans= min(ans,mp[i]);
               ans= min(ans,n-mp[i]);
            }
        }
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
        vector<long long> arr(n);
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &arr[i]);
        }

        Solution obj;
        int res = obj.makeBridgeOne(n, arr);

        cout << res << endl;
    }
}

// } Driver Code Ends