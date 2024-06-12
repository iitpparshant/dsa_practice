//  https://leetcode.com/problems/trapping-rain-water/

// 42. Trapping Rain Water

  // METHODE 1
  class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        vector<int>l(n);
        vector<int>r(n);
        l[0]=height[0];
        for(int i=1;i<n;i++){
            l[i]= max(l[i-1],height[i]);
            // cout<<l[i];
        }
        r[n-1]= height[n-1];
        for(int i=n-2;i>=0;i--){
            r[i]= max(r[i+1],height[i]);
            // cout<<r[i];
        }
        int ans=0;
        for(int i=1;i<n;i++){
            ans+= (min(l[i],r[i])- height[i]);
        }
        return ans;
    }
};


//   METHOD 2

class Solution {
public:
    int trap(vector<int>& height) {
        int s=0;
        int e=height.size()-1;
        int l= height[s];
        int r= height[e];
        int ans=0;
        while(s<e){
            if(l<r){
                s++;
                l= max(l,height[s]);
                ans+= (l-height[s]);
            }
            else{
                e--;;
                r= max(r,height[e]);
                ans+=(r- height[e]);
            }
        }
        return ans;
    }
};