// https://leetcode.com/problems/the-kth-factor-of-n/description/

//   1492. The kth Factor of n

class Solution {
public:
    int kthFactor(int n, int k) {
        for(int i=1;i<=n;i++){
            if(n%i==0){
                k--;
            }
            if(k==0){
                return i;
            }
        }
        return -1;
    }
};