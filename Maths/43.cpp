//    https://leetcode.com/problems/multiply-strings/

// 43. Multiply Strings

//  Method 1 

class Solution {
public:
    string findSum(string X, string Y) {
        int i = X.size() - 1;
        int j = Y.size() - 1;
        int carry = 0;
        string s = "";
        while (i >= 0 && j >= 0) {
            int a = (int)(X[i] - '0');
            int b = (int)(Y[j] - '0');
            int sum = a + b + carry;
            s += (char)((sum % 10) + 48);
            carry = sum / 10;
            i--;
            j--;
        }
        while (i >= 0) {
            int a = (int)(X[i] - '0');
            // int b= (int)(Y[i]-'0');
            int sum = a + carry;
            s += (char)((sum % 10) + 48);
            carry = sum / 10;
            i--;
        }
        while (j >= 0) {
            // int a= (int)(X[i]-'0');
            int b = (int)(Y[j] - '0');
            int sum = b + carry;
            s += (char)((sum % 10) + 48);
            carry = sum / 10;
            j--;
        }
        if (carry) {
            s += (char)(carry + 48);
        }
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                return s.substr(i);
            }
        }
        return "0";
    }
    string multiply(string num1, string num2) {
        string ans;
        vector<string> s;
        for (int i = num1.size() - 1; i >= 0; i--) {
            string a = "";
            int c = 0;
            for (int j = num2.size() - 1; j >= 0; j--) {
                int num = (num1[i] - '0') * (num2[j] - '0') + c;
                a += to_string(num % 10);
                c = num / 10;
            }
            if (c) {
                a += to_string(c);
            }
            int z = num1.size() - 1 - i;
            while (z) {
                a.insert(a.begin(), '0');
                z--;
            }
            reverse(a.begin(), a.end());
            s.push_back(a);
        }
        for (int i = 0; i < s.size(); i++) {
            cout << s[i] << " ";
        }
        if (s.size() == 1) {
            if (count(s[0].begin(), s[0].end(), '0') == s[0].size()) {
                return "0";
            }
            return s[0];
        }
        string x = s[0];
        for (int i = 1; i < s.size(); i++) {
            x = findSum(x, s[i]);
        }
        return x;
    }
};

//   method 2 


class Solution {
public:
    string multiply(string num1, string num2) {
        string ans(num1.size()+num2.size(),'0');
        for (int i = num1.size() - 1; i >= 0; i--) {
            for (int j = num2.size() - 1; j >= 0; j--) {
                int num = (num1[i] - '0') * (num2[j] - '0');
               int a= num+ (ans[i+j+1]-'0');
               ans[i+j]+= a/10;
               ans[i+j+1]= '0'+a%10;
            }
        }
        int y= ans.find_first_not_of('0');
        return y==string::npos?"0":ans.substr(y);
    }
};