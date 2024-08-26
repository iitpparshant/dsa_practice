// https://www.geeksforgeeks.org/problems/wildcard-pattern-matching/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int dp[201][201];
    /*You are required to complete this method*/
    bool solve(string s,string t,int i,int j){
        if(i==s.size() && j==t.size()){
            return true;
        }
        if(i==s.size()){
            return false;
        }
        if(j==t.size()){
            return (s[i]=='*')? solve(s,t,i+1,j):false;
        }
        int a=0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==t[j] || s[i]=='?'){
            return dp[i][j]= solve(s,t,i+1,j+1);
        }
        if(s[i]=='*'){
            return dp[i][j]= solve(s, t, i + 1, j) || solve(s, t, i, j + 1);
        }
        return dp[i][j]= false;
    }
    int wildCard(string pattern, string str) {
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(pattern,str,0,0);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends