//  **********   first method *********//
class Solution {
public:
    bool solve(string s,int k){
        int freq1[26]={0};
        for(int i=0;i<k;i++){
            freq1[s[i]-'a']++;
        }
        for(int i=k;i<s.size();i+=k){
            int freq2[26]={0};
            for(int j=i;j<i+k;j++){
                freq2[s[j]-'a']++;
            }
            for(int l=0;l<26;l++){
                if(freq1[l]!=freq2[l]){
                    return false;
                }
            }
        }
        return true;
    }
    int minAnagramLength(string s) {
        int n= s.size();
        for(int i=1;i<=n;i++){
            if(n%i==0&& solve(s,i)){
                return i;
            }
        }
        return false;
    }
};



//    ******* second method    ************//

class Solution {
public:
    int minAnagramLength(string s) {
        vector<int>freq(26);
        for(auto it:s){
            freq[it-'a']++;
        }
        int gcd= freq[0];
        for(int i=1;i<26;i++){
            gcd= __gcd(gcd,freq[i]);
        }
        int ans=0;
        for(auto it:freq){
            ans+= it/gcd;
        }
        return ans;
    }
};