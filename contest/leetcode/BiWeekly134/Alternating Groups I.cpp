//  https://leetcode.com/problems/alternating-groups-i/description/

//                            3206. Alternating Groups I

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int count = 0;
        for (int i = 0; i <= n - 3; i++) {
            if (colors[i] != colors[i + 1] && colors[i + 1] != colors[i + 2]) {
                count++;
            }
        }
        if (colors[0] != colors[n - 1] && colors[n - 1] != colors[n - 2]) {
            count++;
        }
        if (colors[0] != colors[1] && colors[0] != colors[n-1]) {
            count++;
        }
        return count;
    }
};