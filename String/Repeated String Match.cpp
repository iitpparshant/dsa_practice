// https://leetcode.com/problems/repeated-string-match/description/

//                              686. Repeated String Match


//                                  brute froce

class Solution {
public:
int solve(string a,string b,int c){
    int n = a.size();
    int m = b.size();
        int i = c;
        int j = 0;
        int count = 0;
        int flag = 0;
        while (j < m) {
            string p = a.substr(i);
            // int x = n - i;
            string q;
            if (j + p.size() < m) {
                q = b.substr(j, p.size());
            } else {
                q = b.substr(j);
                p = a.substr(i, q.size());
            }
            i++;
            // cout << p << " " << q << "##";
            if (flag == 0) {
                if (q == p) {
                    // cout<<p;
                    j += p.size();
                    i = 0;
                    count++;
                    flag = 1;
                }
                else{
                    return -1;
                }
            } else if (flag == 1) {
                if (p == q) {
                    j += p.size();
                    i = 0;
                    count++;
                } else if (p != q) {
                    return -1;
                }
            } else if (i == n) {
                return -1;
            }
        }
        return count;
}
    int repeatedStringMatch(string a, string b) {
        int ans= INT_MAX;
        int n= a.size();
        for(int i=0;i<n;i++){
            if(solve(a,b,i)!=-1){
                return solve(a,b,i);
            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};


//                                                        using rabin karp

class Solution {
public:
int BASE = 1000000;
int rabin(string source, string target){
        if(source == "" or target == "") return -1;
        int m = target.size();
        int power = 1;
        for(int i = 0;i<m;i++){
            power = (power*31)%BASE;
        }
        int targetCode = 0;
        for(int i = 0;i<m;i++){
            targetCode = (targetCode*31+target[i])%BASE;
        }
        int hashCode = 0;
        for(int i = 0;i<source.size();i++){
            hashCode = (hashCode*31 + source[i])%BASE;
            if(i<m-1) continue;
            if(i>=m){
                hashCode = (hashCode-source[i-m]*power)%BASE;
            }
            if(hashCode<0)
                hashCode+=BASE;
            if(hashCode == targetCode){
                if(source.substr(i-m+1,m) == target)
                    return i-m+1;
            }
        }
        return -1;
    }
    int repeatedStringMatch(string a, string b) {
        if(a==b){
            return 1;
        }
        int count=1;
        string s=a;
        while(s.size()<b.size()){
            count++;
            s+=a;
        }
        if(s==b){
            return count;
        }
        if(rabin(s,b)!=-1){
            return count;
        }
        if(rabin(s+a,b)!=-1){
            return count+1;
        }
        return -1;
    }
};