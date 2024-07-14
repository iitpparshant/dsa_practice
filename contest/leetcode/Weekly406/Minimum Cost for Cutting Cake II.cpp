// https://leetcode.com/problems/minimum-cost-for-cutting-cake-ii/

class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.rbegin(), horizontalCut.rend());
        sort(verticalCut.rbegin(), verticalCut.rend());
        int h = 0;
        int v = 0;
        int hp = 1;
        int vp = 1;
        long long ans = 0;
        while (h < horizontalCut.size() && v < verticalCut.size()) {
            if (horizontalCut[h] > verticalCut[v]) {
                ans += horizontalCut[h] * vp;
                h++;
                hp++;
            } else {
                ans += verticalCut[v] * hp;
                v++;
                vp++;
            }
        }
        while (h < horizontalCut.size()) {
            ans += horizontalCut[h] * vp;
            h++;
        }
        while (v < verticalCut.size()) {
            ans += verticalCut[v] * hp;
            v++;
        }
        return ans;
    }
};