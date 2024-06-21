//   https://leetcode.com/problems/k-closest-points-to-origin/description/

//   973. K Closest Points to Origin

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>pq;
        for(auto it: points){
            int x= it[0];
            int y= it[1];
            int z= pow(x,2)+pow(y,2);
            pq.push({z,{x,y}});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            pair<int,pair<int,int>>p= pq.top();
            pq.pop();
            ans.push_back({p.second.first,p.second.second});
        }
        return ans;
    }
};