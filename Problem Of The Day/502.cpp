//   https://leetcode.com/problems/ipo/description/

//  ********    502. IPO     *******

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
       int n= profits.size();
       vector<vector<int>>res;
       for(int i=0;i<n;i++){
        res.push_back({capital[i],profits[i]});
       } 
       sort(res.begin(),res.end());
       priority_queue<int>mx;
       int s=0;
       for(int i=0;i<k;i++){
        while(s<n && res[s][0]<=w){
            mx.push(res[s][1]);
            s++;
        }
        if(mx.empty()){
           break;
        }
        w+= mx.top();
        mx.pop();
       }
       return w;
    }
};