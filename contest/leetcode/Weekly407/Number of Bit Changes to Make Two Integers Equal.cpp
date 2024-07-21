// https://leetcode.com/problems/number-of-bit-changes-to-make-two-integers-equal/description/

// 3226. Number of Bit Changes to Make Two Integers Equal

class Solution {
public:
    int minChanges(int n, int k) {
        int count=0;
        for(int i=0;i<32;i++){
            if(((1<<i)&n)!=((1<<i)&k)){
                if(((1<<i)&n)==0){
                    return -1;
                }
                count++;
            }
        }
        return count;
    }
};