// https://leetcode.com/problems/grumpy-bookstore-owner/description/

//   1052. Grumpy Bookstore Owner

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum=0;
        int n= grumpy.size();
        int sum2=0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                sum+=customers[i];
            }
            else if(i<minutes){
                sum2+=customers[i];
            }
        }
        int x=sum2;
        for(int i= minutes;i<n;i++){
            sum2+= customers[i]*grumpy[i];
            sum2-=customers[i-minutes]*grumpy[i-minutes];
            x= max(x,sum2);
        }
        return sum+x;
    }
};