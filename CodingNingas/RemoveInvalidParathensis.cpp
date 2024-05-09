#include <bits/stdc++.h> 
void solve(string &str ,int i,int count,string temp,int c,int o,set<string>&ans){
    if(i==str.size()){
        if(count==0&&c==0&& o==0){
            ans.insert(temp);
        }
        return;
    }
    if(str[i]=='('){
        if(o>0){
              solve(str,i+1,count,temp,c,o-1,ans);
        }
           solve(str,i+1,count+1,temp+'(',c,o,ans);
    }
    else if(str[i]==')'){
        if(c>0){
            solve(str,i+1,count,temp,c-1,o,ans);
        } 
        if(count>0){            
            solve(str,i+1,count-1,temp+str[i],c,o,ans);
        }
    }
    else{
        solve(str,i+1,count,temp+str[i],c,o,ans);
    }
}
vector<string> removeInvalidParentheses(string &str)
{
    // Write your code here.
    set<string>ans;
    int o=0,c=0;
    for(char ch:str){
        if(ch=='('){
            o++;
        }
        else if(ch==')'){
            if(o>0){
                o--;
            }
            else{
                c++;
            }
        }
    }
    string temp="";
    solve(str,0,0,temp,c,o,ans);
    vector<string>res(ans.begin(),ans.end());
    return res;
}
