//   https://leetcode.com/problems/sum-of-square-numbers/description/
//   633. Sum of Square Numbers


class Solution {
public:
    bool judgeSquareSum(int c) {
        long long i = 1, j = sqrt(c);
        if (j * j == c) {
            return true;
        }
        while (i <= j) {
            long long sum = (i * i) + (j * j);
            if (sum == c) {
                return true;
            } else if (sum < c) {
                i++;
            } else {
                j--;
            }
        }
        return false;
    }
};