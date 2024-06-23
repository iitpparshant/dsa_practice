//  https://leetcode.com/problems/furthest-building-you-can-reach/description/

//                 1642. Furthest Building You Can Reach

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = heights.size();
        for (int i = 0; i < n - 1; i++) {
            int h = heights[i + 1] - heights[i];
            if (h > 0) {
                if (ladders) {
                    pq.push(h);
                    ladders--;
                }
                else if (!pq.empty() && h > pq.top()) {
                    bricks -= pq.top();
                    pq.pop();
                    pq.push(h);
                }
                else{
                    bricks-=h;
                }
                if(bricks<0){
                    return i;
                }
            }
        }
        return n-1;
    }
};