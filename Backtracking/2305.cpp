// https://leetcode.com/problems/fair-distribution-of-cookies/

class Solution {
public:
int h,res= INT_MAX;
vector<int>p= {0,0,0,0,0,0,0,0};
void solve(vector<int>& cookies, int k,int s){
    if(s==cookies.size()){
        int c=0;
        for(int i=0;i<k;i++){
            c= max(c,p[i]);
        }
        res= min(res,c);
        return ;
    }
    for(int i=0;i<k;i++){
        p[i]+= cookies[s];
        solve(cookies,k,s+1);
        p[i]-=cookies[s];
    }
    if(k<h){
        p[k]+= cookies[s];
        solve(cookies,k+1,s+1);
        p[k]-=cookies[s];
    }
}
    int distributeCookies(vector<int>& cookies, int k) {
        h=k;
        solve(cookies,0,0);
        return res;
    }
};