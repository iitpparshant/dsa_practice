//   https://leetcode.com/problems/most-profit-assigning-work/description/
//   826. Most Profit Assigning Work

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int mx=0;
        for(auto it:difficulty){
            mx= max(mx,it);
        }
        vector<int>a(mx+1,0);
        for(int i=0;i<difficulty.size();i++){
            a[difficulty[i]]= max(a[difficulty[i]],profit[i]);
        }
        for(int i=1;i<=mx;i++){
            a[i]= max(a[i],a[i-1]);
        }
        int sum=0;
        for(auto it:worker){
            if(it>=mx){
                sum+=a[mx];
            }
            else{
                sum+=a[it];
            }
        }
        return sum;
    }
};