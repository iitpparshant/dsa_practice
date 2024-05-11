class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        int i=0;
        int n= path.size();
        while(i<n){
            int s=i;
            int e= i+1;
            while(e<n && path[e]!='/'){
                e++;
            }
            string mnPath= path.substr(s,e-s);
            i=e;
            if(mnPath=="/" || mnPath=="/."){
                continue;
            }
            else if(mnPath!="/.."){
                st.push(mnPath);
            }
            else if(!st.empty()){
                st.pop();
            }
        }
        string temp="";
        while(!st.empty()){
            temp= st.top()+temp;
            st.pop();
        }
        if(temp.size()==0){
            return "/";
        }
        return temp;
    }
};