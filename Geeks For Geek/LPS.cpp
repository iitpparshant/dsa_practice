//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        // code here
        if(S.size()<=1){
            return S;
        }
        string lps= "";
        for(int i=1;i<S.size();i++){
            int l=i;
            int h= i;
            while(S[l]==S[h]){
                l--;
                h++;
                if(l==-1|| h==S.size()){
                    break;
                }
            }
            string temp= S.substr(l+1,h-l-1);
            if(temp.size()>lps.size()){
                lps=temp;
            }
            l=i-1;
            h= i;
            while(S[l]==S[h]){
                l--;
                h++;
                if(l==-1|| h==S.size()){
                    break;
                }
            }
            temp= S.substr(l+1,h-l-1);
            if(temp.size()>lps.size()){
                lps=temp;
            }
        }
        if(lps.length()==1){
            return S.substr(0,1);
        }
        return lps;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends