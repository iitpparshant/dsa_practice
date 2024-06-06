//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
vector<vector<int>> ans;
void solve(vector<int>arr,int n,int k,vector<int>&temp,int sum,int s){
        if(sum==k){
            ans.push_back(temp);
            return;
        }
    for(int i=s;i<n;i++){
        if(i>s && arr[i]==arr[i-1]){
            continue;
        }
        if(sum+arr[i]<=k){
           temp.push_back(arr[i]);
           solve(arr,n,k,temp,sum+arr[i],i+1);
           temp.pop_back();
        }
    }
    
}
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        vector<int>temp;
        sort(arr.begin(),arr.end());
        solve(arr,n,k,temp,0,0);
        // sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends