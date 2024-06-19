//   https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

//   1482. Minimum Number of Days to Make m Bouquets

class Solution {
public:
bool solve(vector<int>a,int m,int k,int x){
    int n= a.size();
    int i=0;
    int y=0;
    while(i<n){
        int count=0;
        if(a[i]<=x){
            while(i<n && a[i]<=x){
                count++;
                i++;
                if(count==k){
                    break;
                }
            }
        }
        else{
            i++;
        }
        if(count==k){
            y++;
        }
    }
    // cout<<y<<"mm";
    return y>=m;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n= bloomDay.size();
        int j=0;
        for(int i=0;i<n;i++){
            j= max(j,bloomDay[i]);
        }
        // if(m*k>n){
        //     return -1;
        // }
        int  i=0;
        int mid;
        int ans=-1;
        while(i<=j){
            mid= i+(j-i)/2;
            // cout<<mid<<" ";
            if(solve(bloomDay,m,k,mid)){
                ans= mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};