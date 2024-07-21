// https://leetcode.com/problems/vowels-game-in-a-string/description/

// 3227. Vowels Game in a String

class Solution {
public:
    bool doesAliceWin(string s) {
        int n= s.size();
        int x=-1;
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'|| s[i]=='o'||s[i]=='u'){
                count++;
                x=i;
            }
        }
        if(count%2!=0){
            return true;
        }
        if(count==0){
            return false;
        }
        int p=-1;
        int count1=0,count2=0;
        for(int i=x+1;i<n;i++){
            if(!(s[i]=='a'||s[i]=='e'||s[i]=='i'|| s[i]=='o'||s[i]=='u')){
                count1++;
                p=i;
            }
        }
        int q=-1;
        for(int i=x-1;i>=0;i--){
            if(!(s[i]=='a'||s[i]=='e'||s[i]=='i'|| s[i]=='o'||s[i]=='u')){
                count2++;
                q=i;
            }
        }
        if(count2!=0){
            return true;
        }
        if(count1>=0){
            return true;
        }
        return false;
    }
};