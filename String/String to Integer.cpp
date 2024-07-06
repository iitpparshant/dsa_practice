// https://leetcode.com/problems/string-to-integer-atoi/description/

//                                       8. String to Integer (atoi)

class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int i=0;
        int flag=0;
        long ans=0;
        while(i<n &&s[i]==' '){
            i++;
        }
        int sign=1;
        if(s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(s[i]=='+'){
            i++;
        }
        while(i<n){
            if(s[i]>='0' && s[i]<='9'){
                ans= ans*10+ (s[i]-'0');
                if(ans>INT_MAX && sign==-1){
                    return INT_MIN;
                }
                else if(ans>INT_MAX && sign==1){
                    return INT_MAX;
                }
                i++;
            }
            else{
                return ans*sign;
            }
        }
        return ans*sign;
    }
};