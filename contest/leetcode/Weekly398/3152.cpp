class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        vector<int> v;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i]%2==nums[i+1]%2) {
                v.push_back(i);
            }
        }
        // cout << v.size() << "wkd";
        // for (int i = 0; i < v.size(); i++) {
        //     cout << v[i];
        // }
        vector<bool> ans;
        for (auto& it : queries) {
            int s = it[0];
            int e = it[1];
            int x = lower_bound(v.begin(), v.end(), s) - v.begin();
            if (s!=e && x < v.size() && v[x] <e) {
                ans.push_back(0);
                // cout << v[x] << " ";
            } else {
                ans.push_back(1);
            }
        }
        return ans;
    }
};