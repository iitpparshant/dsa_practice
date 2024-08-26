// https://leetcode.com/problems/maximum-distance-in-arrays/description/

//                    624. Maximum Distance in Arrays

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mx=arrays[0][arrays[0].size()-1];
        int mn= arrays[0][0];
        int diff= INT_MIN;
        for(int i=1;i<arrays.size();i++){
            diff= max(diff,arrays[i][arrays[i].size()-1]-mn);
            diff= max(diff,mx-arrays[i][0]);
            mx= max(mx,arrays[i][arrays[i].size()-1]);
            mn= min(mn,arrays[i][0]);
        }
        return  diff;
    }
};