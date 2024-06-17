//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  bool is(int mid,int n, int m, int k, vector<int> &a){
      int count=1;
      int curr=1;
      int first= a[0];
      for(int i=1;i<n;i++){
          if(curr==k ||a[i]-first>mid){
              curr=0;
              count++;
              first=a[i];
          }
          curr++;
      }
      return count<=m;
  }
    int minimizeWaitingTime(int n, int m, int k, vector<int> &arrival) {
        // code here
        sort(arrival.begin(),arrival.end());
        int ans=INT_MAX;
        int l=0;
        int h=arrival[n-1]-arrival[0];
        while(l<=h){
            int mid= (l+h)/2;
            if(is(mid,n,m,k,arrival)){
                ans=mid;
                h= mid-1;
            }
            else{
                l= mid+1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int m;
        scanf("%d", &m);

        int k;
        scanf("%d", &k);

        vector<int> arrival(n);
        Array::input(arrival, n);

        Solution obj;
        int res = obj.minimizeWaitingTime(n, m, k, arrival);

        cout << res << endl;
    }
}

// } Driver Code Ends