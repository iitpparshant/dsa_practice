//     *************   first Method  Brute Force   ****//
class Solution {
public:
    int countSubstrings(string s, string t) {
        int n= s.size();
        int p= t.size();
        int ans=0;
        for(int i=0;i<s.size();i++){
            for(int j=0;j<p;j++){
                int l=1,m=1;
                if(s[i]!=t[j]){
                    while((i-l)>=0 && (j-l)>=0 && s[i-l]==t[j-l]){
                        l++;
                    }
                    while((i+m)<n && (j+m)>=0 && s[i+m]==t[j+m]){
                        m++;
                    }
                   ans+= (l*m);
                }
            }
        }
        return ans;
    }
};


//     *************   Second Method   ****//