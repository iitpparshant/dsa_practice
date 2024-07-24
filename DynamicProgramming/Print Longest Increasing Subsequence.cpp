// https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=printing-longest-increasing-subsequence

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        vector<int> dp(n,1),hash(n,1);
    int mx=-1;
    int last=-1;
    for(int i=0; i<=n-1; i++){
        hash[i]=i;
        for(int prev_index = 0; prev_index <=i-1; prev_index ++){
            
            if(arr[prev_index]<arr[i] && 1 + dp[prev_index]>dp[i]){
                dp[i] = 1 + dp[prev_index];
                hash[i]= prev_index;
            }
        }
        if(dp[i]>mx){
            mx=dp[i];
            last=i;
        }
    }
    vector<int>ans;
    ans.push_back(arr[last]);
    while(hash[last]!=last){
        last= hash[last];
        ans.push_back(arr[last]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends