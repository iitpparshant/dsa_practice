//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

//  *******       PICK THEOREM     *******   

// Apply Pick's Theorem:
//   Pick's Theorem states: Area=I+B/2−1,
//       Where:
//           1. Area is the area of the polygon.
//           2. I is the number of lattice points strictly inside the polygon.
//           3. B is the number of lattice points on the boundary of the polygon
              

class Solution {
  public:
  long long int gcd(long long int a,long long int b) {
    while (b != 0) {
        long long int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
  long long area(long long p[],long long q[],long long r[]){
      return abs(p[0]*(q[1]-r[1]) + q[0]*(r[1]-p[1]) + r[0]*(p[1]-q[1]))/2 ;
  }
  long long boundary(long long p[],long long q[], long long r[]){
      return gcd(abs(p[0]-q[0]),abs(p[1]-q[1])) + gcd(abs(p[0]-r[0]),abs(p[1]-r[1])) + gcd(abs(r[0]-q[0]),abs(r[1]-q[1])) ;
  }

    long long int InternalCount(long long int p[], long long int q[],
                                long long int r[]) {
        // code here
        long long count = area(p,q,r) - boundary(p,q,r)/2 + 1;
        return count ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int p[2], q[2], r[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1];
        Solution ob;
        long long int ans = ob.InternalCount(p, q, r);
        cout << ans << "\n";
    }
}
// } Driver Code Ends