// https://leetcode.com/problems/maximum-score-from-removing-substrings/description/

//               1717. Maximum Score From Removing Substrings

//                                    first method 

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (x < y) {
            swap(x, y);
            for (char& c : s) {
                if (c == 'a') c = 'b';
                else if (c == 'b') c = 'a';
            }
        }
        
        int points = 0;
        stack<char> st;
        
        for (char c : s) {
            if (!st.empty() && st.top() == 'a' && c == 'b') {
                st.pop();
                points += x;
            } else {
                st.push(c);
            }
        }
        
        string remaining;
        while (!st.empty()) {
            remaining += st.top();
            st.pop();
        }
        reverse(remaining.begin(), remaining.end());
        
        for (char c : remaining) {
            if (!st.empty() && st.top() == 'b' && c == 'a') {
                st.pop();
                points += y;
            } else {
                st.push(c);
            }
        }
        
        return points;
    }
};



//                                                second method 


class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char>ch;
        int n= s.size();
        int ca=0;
        int cb=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]>'b'){
                ans+= min(ca,cb)* min(x,y);
                ca=0;
                cb=0;
            }
            else if(s[i]=='a'){
                if(x<y && cb>0){
                    cb--;
                    ans+=y;
                }
                else{
                    ca++;
                }
            }
            else{
                if(x>y && ca>0){
                    ca--;
                    ans+=x;
                }
                else{
                    cb++;
                }
            }
        }
        ans+= min(ca,cb)* min(x,y);
        return ans;
    }
};