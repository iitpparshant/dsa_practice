//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        s= "0"+s;
        int n= s.size()-1;
        while(n>=0){
            if(s[n]=='0'){
                s[n]='1';
                break;
            }
            else{
                s[n]='0';
                n--;
            }
        }
        int i=0;
        while(s[i]=='0'){
            i++;
        }
        return s.substr(i,s.size());
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends