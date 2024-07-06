// https://leetcode.com/problems/pass-the-pillow/description/

//                             2582. Pass the Pillow


class Solution {
public:
    int passThePillow(int n, int time) {
        int N = 2 * n - 2;
        int x = time % N;
        return 1 + ((x < n) ? x : N - x);
    }
};