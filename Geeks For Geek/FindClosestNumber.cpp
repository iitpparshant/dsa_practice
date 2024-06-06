//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        int i=0;
        int j= n-1;
        int diff= INT_MAX;
        int ans=arr[0];
        while(i<=j){
            int m= (i+j)/2;
            int x= arr[m]-k;
            if(abs(k-ans)==abs(x)){
                    ans= max(ans,arr[m]);
                }
                else if(abs(k-ans)>abs(x)){
                    ans= arr[m];
                }
            if(x==0){
                return k;
            }
            if(x>0){
                j=m-1;
                
            }
            else{
                i= m+1;
            }
        }
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
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends