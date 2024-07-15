// https://www.geeksforgeeks.org/problems/smallest-number5829/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
        string st="1";
        for(int i=0;i<d-1;i++){
            st+='0';
        }
        bool found= 0;
        while(found==0){
            int sum=0;
            for(int i=0;i<d;i++){
                sum+= (st[i]-'0');
            }
            if(sum==s){
                found= 1;
                break;
            }
            if(sum>s){
                return "-1";
                break;
            }
            int num= stoi(st);
            num++;
            st= to_string(num);
            if(st.size()>d){
                return "-1";
                break;
            }
        }
        return st;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends