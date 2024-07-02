// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/description/


//                              1689. Partitioning Into Minimum Number Of Deci-Binary Numbers

class Solution {
public:
    int minPartitions(string n) {
        int x=0;
        for(auto it:n){
            x= max(x,it-'0');
        }
        return x;
    }
};