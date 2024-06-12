// https://leetcode.com/problems/zigzag-conversion/description/

//    6. Zigzag Conversion

class Solution {
public:
    string convert(string s, int numRows) {
        int n= s.size();
        if(numRows<=1){
            return s;
        }
        int dir=-1;
        int j=0;
        vector<string>v(numRows,"");
        for(int i=0;i<s.size();i++){
            if(j==0 || j==numRows-1){
                dir*=(-1);
            }
            v[j]+= s[i];
            if(dir==1){
                j++;
            }
            else{
                j--;
            }
        }
        string ans="";
        for(auto &it:v){
            ans+=it;
        }
        return ans;
    }
};