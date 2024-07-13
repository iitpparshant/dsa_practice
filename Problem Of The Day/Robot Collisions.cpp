//    https://leetcode.com/problems/robot-collisions/description/

//                                                        2751. Robot Collisions

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        stack<pair<int, int>> s;
        int n = positions.size();
         vector<pair<int, int>> posIndex(n);
        for (int i = 0; i < n; ++i) {
            posIndex[i] = {positions[i], i};
        }
        sort(posIndex.begin(),posIndex.end());
        for (int i = 0; i < n; i++) {
            int idx= posIndex[i].second;
            char d= directions[idx];
            int h= healths[idx];
            int p= positions[idx];
            if(d=='R'){
                s.push({idx,h});
            }
            else{
                while(!s.empty() && directions[s.top().first]=='R' && h>0){
                    if(s.top().second>h){
                        h=0;
                        s.top().second--;
                    }
                    else if(s.top().second<h){
                        h--;
                        s.pop();
                    }
                    else{
                        h=0;
                        s.pop();
                    }
                }
                if(h>0){
                    s.push({idx,h});
                }
            }
        }
        vector<int> ans(n,0);
        while (!s.empty()) {
            ans[s.top().first]=s.top().second;
            s.pop();
        }
        vector<int>res;
        for(int i=0;i<n;i++){
            if(ans[i]>0){
                res.push_back(ans[i]);
            }
        }
        return res;
    }
};