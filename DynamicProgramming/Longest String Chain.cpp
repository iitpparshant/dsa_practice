// https://leetcode.com/problems/longest-string-chain/description/

//                                      1048. Longest String Chain

//                                          recur+memo

class Solution {
public:
int dp[1001];
static bool cmp(string &a,string &b){
    return a.size()< b.size();
}
bool check(string &a,string &b){
    if(a.size()+1!=b.size()){
        return false;
    }
    int count=0;
    int i=0,j=0;
    while(i<a.size() && j<b.size()){
        if(a[i]!=b[j]){
            if(count==1){
                return false;
            }
            count=1;
        }
        else{
           i++;
        }
        j++;
    }
    return true;
}
int solve(int s,vector<string>& words,int n){
    if(s>=n){
        return 0;
    }
    if(dp[s]!=-1){
        return dp[s];
    }
    int ans=0;
    for(int i=s+1;i<n;i++){
        if(check(words[s],words[i])){
            ans= max(ans,1+ solve(i,words,n));
        }
    }
    return dp[s]= ans;
}
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        int n= words.size();
        int ans=0;
        for(int i=0;i<n;i++){
            memset(dp,-1,sizeof(dp));
            int cnt= solve(i,words,n);
            // cout<<words[i]<<" ";
            ans= max(ans,cnt);
        }
        return ans+1;
    }
};


//                                                  dp 

class Solution {
public:
    static bool cmp(string& a, string& b) { return a.size() < b.size(); }
    bool check(string& a, string& b) {
        if (a.size() + 1 != b.size()) {
            return false;
        }
        int count = 0;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] != b[j]) {
                if (count == 1) {
                    return false;
                }
                count = 1;
            } else {
                i++;
            }
            j++;
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        int n = words.size();
        int ans = 0;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (check(words[j], words[i]) && 1 + dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};