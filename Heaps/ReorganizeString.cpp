//   https://leetcode.com/problems/reorganize-string/description/

//    767. Reorganize String

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for (auto it : s) {
            mp[it]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto it : mp) {
            pq.push({it.second, it.first});
        }
        string ans = "";
        while (!pq.empty()) {
            pair<int, char> p = pq.top();
            pq.pop();
            ans.push_back(p.second);
            if (pq.empty()) {
                if (p.first - 1 > 0) {
                    pq.push({p.first - 1, p.second});
                }
                break;
            }
            pair<int, char> p2 = pq.top();
            pq.pop();
            ans.push_back(p2.second);
            if (p.first - 1 > 0) {
                pq.push({p.first - 1, p.second});
            }
            if (p2.first - 1 > 0) {
                pq.push({p2.first - 1, p2.second});
            }
        }
        if (!pq.empty()) {
            return "";
        }
        return ans;
    }
};