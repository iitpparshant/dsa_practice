//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string s) {

        // code here
        int n= s.size();
        long long ans=-1;
        for(int i=0;i<n;i++){
            if(s[i]>='0' && s[i]<='9'){
                 long long num=0;
                 bool flag=false;
                 while(i<n && (s[i]>='0' && s[i]<='9')){
                      if(s[i]=='9'){
                           flag = true;
                      }
                      num= num*10+(s[i]-'0');
                     i++;
                }
              if(!flag){
                ans= max(ans,num);
               }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends