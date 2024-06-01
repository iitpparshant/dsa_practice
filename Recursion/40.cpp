class Solution {
public:
void solve(int k, int n, vector<vector<int>>& ans, vector<int>& temp,
               int s, vector<int>& arr) {
        if (n == 0 && k == 0) {
            ans.push_back(temp);
            return;
        }
        if (n < 0 || k < 0) {
            return;
        }
        for (int i = s; i < arr.size(); i++) {
            if (arr[i] > n) {
                break;
            }
            temp.push_back(arr[i]);
            solve(k - 1, n - arr[i], ans, temp, i + 1, arr);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int>arr= {1,2,3,4,5,6,7,8,9};
        solve(k, n, ans, temp, 0,arr);
        return ans;
    }
};