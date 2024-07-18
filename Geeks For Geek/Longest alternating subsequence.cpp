// https://www.geeksforgeeks.org/problems/longest-alternating-subsequence5951/1

//                                                       Longest alternating subsequence

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int solve(vector<int>& arr, bool x, int i, vector<vector<int>> &dp) {
        if (i >= arr.size()) {
            return 1; // No more elements to include
        }
        if (dp[i][x] != -1) {
            return dp[i][x];
        }
        int a = 0;
        if (i + 1 < arr.size()) {
            if ((x == 1 && arr[i] > arr[i + 1]) || (x == 0 && arr[i] < arr[i + 1])) {
                a = 1 + solve(arr, !x, i + 1, dp);
            }
        }
        int b = solve(arr, x, i + 1, dp);
        return dp[i][x] = max(a, b);
    }
    int alternatingMaxLength(vector<int>& arr) {
        // Code here
        int n= arr.size();
        vector<vector<int>> dp(n,vector<int>(2, -1));
        return max(solve(arr,  1, 0, dp),solve(arr,  0, 0, dp));
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }
        Solution obj;
        int ans = obj.alternatingMaxLength(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends