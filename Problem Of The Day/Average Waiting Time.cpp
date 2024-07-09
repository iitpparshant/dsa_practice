// https://leetcode.com/problems/average-waiting-time/description/

//                                       1701. Average Waiting Time

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans=0;
        int n= customers.size();
        int s=0;
        for(int i=0;i<n;i++){
            if(s>=customers[i][0]){
               s=s+customers[i][1];
            }
            else{
                s=s+customers[i][1]+customers[i][0]-s;
            }
            ans+= s-customers[i][0];
            // cout<<s;
        }
        return ans/(double(n));
    }
};