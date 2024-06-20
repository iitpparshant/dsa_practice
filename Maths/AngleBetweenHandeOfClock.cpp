//   https://leetcode.com/problems/angle-between-hands-of-a-clock/description/

//    1344. Angle Between Hands of a Clock

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double m= 6.0*(double)minutes;
        double h= 30.0*(double)(hour)+ 0.5*(double)minutes;
        double ans= min(abs(m-h),360.00-abs(m-h));
        return ans;
    }
};