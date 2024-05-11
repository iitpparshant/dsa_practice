//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  void solve(int n,vector<int>&temp,vector<int>&ans){
      if(n==0){
          int res=0;
          for(int i=0;i<temp.size();i++){
              res= res*10+temp[i];
          }
          ans.push_back(res);
          return;
      }
      for(int i=1;i<=9;i++){
          if(temp.size()==0 || i> temp[temp.size()-1]){
              temp.push_back(i);
              solve(n-1,temp,ans);
              temp.pop_back();
          }
      }
  }
    vector<int> increasingNumbers(int n) {
        // Write Your Code here
        vector<int>ans;
        vector<int>temp;
       if(n==1)
       {
           for(int i=0;i<=9;i++){
          ans.push_back(i);
       }
       }
       else{
           solve(n,temp,ans);
           
       }
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> ans = ob.increasingNumbers(N);
        for (auto num : ans) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends