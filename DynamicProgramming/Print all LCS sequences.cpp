//           https://www.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<string> all_longest_common_subsequences(string s, string t) {
        // Code here
        int n= s.size();
        int m= t.size();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j= 1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]= dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        set<string>st;
        queue<pair<pair<int,int>,string>>q;
        unordered_map<string, bool> mp;
        q.push({{n,m},""});
        vector<string>ans;
        while(!q.empty()){
            int x= q.front().first.first;
            int y= q.front().first.second;
            string temp= q.front().second;
            q.pop();
            if(x==0 || y==0){
                st.insert(temp);
                continue;
            }
            string key= to_string(x)+','+to_string(y)+','+temp;
            if(mp.count(key)){
                continue;
            }
            mp[key]=true;
            
                if(s[x-1]==t[y-1]){
                    q.push({{x-1,y-1},s[x-1]+temp});
                }
                else{
                    if(dp[x-1][y]>=dp[x][y-1]){
                        q.push({{x-1,y},temp});
                    }
                    if(dp[x-1][y]<=dp[x][y-1]){
                        q.push({{x,y-1},temp});
                    }
                }
            
        }
        return vector<string>(st.begin(),st.end());
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        vector<string> ans = ob.all_longest_common_subsequences(s, t);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends