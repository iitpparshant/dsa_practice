//  https://leetcode.com/problems/max-value-of-equation/description/

//                           1499. Max Value of Equation


class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        int ans = INT_MIN;
        priority_queue<vector<int>>pq;
        pq.push({points[0][1]-points[0][0],points[0][0]});
        for(int i=1;i<n;i++){
            int sum= points[i][0]+ points[i][1];
            while(!pq.empty() && points[i][0]-pq.top()[1]>k){
                pq.pop();
            }
            if(!pq.empty()){
                ans= max(ans,sum+pq.top()[0]);
            }
            pq.push({points[i][1]-points[i][0],points[i][0]});
        }
        return ans;
    }
};