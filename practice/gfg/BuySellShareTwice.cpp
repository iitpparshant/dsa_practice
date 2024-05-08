//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        //User function Template for C++
        int solve(vector<int>&price,int i,int flag,int q,vector<vector<vector<int>>>&dp){
            if(q<=0){
                return 0;
            }
            if(i>=price.size()){
                return 0;
            }
            if(dp[i][flag][q]!=-1){
                return dp[i][flag][q];
            }
            if(flag){
                int a= solve(price,i+1,1,q,dp);
                int b= -price[i]+solve(price,i+1,0,q,dp);
                return dp[i][flag][q]= max(a,b);
            }
            else{
                int a= solve(price,i+1,0,q,dp);
                int b= price[i]+solve(price,i+1,1,q-1,dp);
                return dp[i][flag][q]= max(a,b);
            }
        }   
        
        int maxProfit(vector<int>&price){
            //Write your code here..
            int n= price.size();
            vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
            return solve(price,0,1,2,dp);
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends