//  https://leetcode.com/problems/basic-calculator-ii/

//   227. Basic Calculator II

//  method 1
class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int n= s.size();
        char opr='+';
            int num=0;
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                num= num*10+(s[i]-'0');
            }
            if((!isdigit(s[i])&& s[i]!=' ')|| i==n-1){
                if(opr=='+'){
                    st.push(num);
                }
                if(opr=='-'){
                    st.push(-num);
                }
                if(opr=='*'){
                    int x= st.top();
                    st.pop();
                    st.push(num*x);
                }
                 if(opr=='/'){
                    int x= st.top()/num;
                    st.pop();
                    st.push(x);
                }
                opr=s[i];
                num=0;
            }
        }
        int sum=0;
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};

//   method 2

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int n = s.size();
        char opr = '+';
        int num = 0;
        int sign = 1;
        int i = 0;
        int sum = 0;
        long long last = 1;
        while (i < n) {
            if (s[i] == ' ') {
                i++;
                continue;
            }
            if (s[i] == '+' || s[i] == '-') {
                sum += last * sign;
                sign = s[i++] == '+' ? 1 : -1;
                last = 1;
                opr = '+';
            } else if (s[i] == '/' || s[i] == '*') {
                opr = s[i];
                i++;
            }
            if (isdigit(s[i])) {
                num = 0;
                while (i < s.size() && isdigit(s[i])) {

                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                if (opr == '*') {
                    last *= num;
                }
                else if (opr == '/') {
                    last /= num;
                } else {
                    last = num;
                }
            }
        }
        sum += last * sign;
        return sum;
    }
};