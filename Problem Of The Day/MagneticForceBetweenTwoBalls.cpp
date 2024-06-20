//   https://leetcode.com/problems/magnetic-force-between-two-balls/description/

//  1552. Magnetic Force Between Two Balls

class Solution {
public:
bool solve(vector<int>a,int m,int x){
    int n= a.size();
    int c=1;
    int l=a[0];
    for(int i=0;i<n;i++){
        if(a[i]-l>=x){
            c++;
            l=a[i];
        }
        if(c>=m){
            return true;
        }
    }
    return false;
}
    int maxDistance(vector<int>& position, int m) {
        int n= position.size();
        int mx=0;
        sort(position.begin(),position.end());
        mx= (position[n-1]-position[0])/(m-1);
        int i=0;
        int j= mx;
        int ans=-1;
        while(i<=j){
            int mid= (i+j)/2;
            if(solve(position,m,mid)){
                ans= mid;
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return ans;
    }
};