// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/

//                                       1190. Reverse Substrings Between Each Pair of Parentheses

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string>ch;
        string ans="";
        int n=s.size();
        string temp="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                  ch.push(temp);
                   temp="";
            }
            else if(s[i]==')'){
                // cout<<temp<<" ";
                    reverse(temp.begin(),temp.end());
                temp= ch.top()+temp;
                ch.pop();
            }
            else{
                temp+=s[i];
            }
        }
        return temp;
    }
};