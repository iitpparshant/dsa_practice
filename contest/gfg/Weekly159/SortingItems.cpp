//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            cin >> A[i];
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
    vector<string> sortItems(int n, vector<string> &items) {
        // code here
        vector<string>mp[10];
        for(auto it:items){
            mp[it.size()-1].push_back(it);
        }
        vector<string>ans;
        for(auto it:mp){
            vector<string>v;
            for(auto j:it){
                v.push_back(j);
            }
            sort(v.begin(),v.end());
            for(auto i:v){
                ans.push_back(i);
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

        vector<string> items(n);
        Array::input(items, n);

        Solution obj;
        vector<string> res = obj.sortItems(n, items);

        Array::print(res);
    }
}

// } Driver Code Ends