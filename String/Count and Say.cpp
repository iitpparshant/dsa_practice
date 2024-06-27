// https://leetcode.com/problems/count-and-say/description/

//                               38. Count and Say

class Solution {
public:
void solve(string &s,int n){
    if(n==1){
        return ;
    }
    char prev= s[0];
    int p= s.size();
    string ans="";
    int count=0;
    for(int i=1;i<p;i++){
        if(s[i]==prev){
            count++;
        }
        else{
            ans+= to_string(count+1)+prev;
            prev=s[i];
            count=0;
        }
    }
    ans+= to_string(count+1)+prev;
    s= ans;
    solve(s,n-1);
}
    string countAndSay(int n) {
        string s="1";
        solve(s,n);
        return s;
    }
};