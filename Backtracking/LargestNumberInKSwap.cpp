//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    void solve(string s,int k,int j,string &temp){
        temp= max(temp,s);
        if(k==0){
            return ;
        }
        if(j>=s.size()){
            return;
        }
        int n= s.size();
        for(int i=j;i<n;i++){
            if(s[i]>s[j]){
                swap(s[j],s[i]);
                solve(s,k-1,j+1,temp);
                swap(s[j],s[i]);
            }
        }
        solve(s,k,j+1,temp);
        
    }
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       // code here.
       string temp="";
       solve(str,k,0,temp);
       return temp;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends