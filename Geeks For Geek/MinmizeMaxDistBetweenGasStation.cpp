//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool check(vector<int>& s,double mid, int k) {
        int cnt = 0;
        int n = s.size();
        for (int i = 1; i < n; ++i) {
            cnt += ceil((s[i] - s[i - 1]) / mid) - 1;
        }
        return cnt <= k;
    }
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        double st = 0.0;
        double en= static_cast<double>(stations.back() - stations.front());
        double ans = en;
        while (en - st > 1e-6) {
            double mid = st + (en - st) / 2.0;
            if (check(stations, mid, k)) {
                ans = mid;
                en = mid;
            } else {
                st = mid;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends