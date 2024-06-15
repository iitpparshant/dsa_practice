// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/description/
// 1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts


class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int n= horizontalCuts.size();
        int x=horizontalCuts[0];
        x= max(x,(h-horizontalCuts[n-1]));
        int m=verticalCuts.size();
        int y=verticalCuts[0];
        y= max(y,(w-verticalCuts[m-1]));
        for(int i=1;i<n;i++){
            x= max(x,(horizontalCuts[i]-horizontalCuts[i-1]));
        }
        for(int i=1;i<m;i++){
            y= max(y,(verticalCuts[i]-verticalCuts[i-1]));
        } 
        return (1LL*x*y)%(1000000007);
    }
};