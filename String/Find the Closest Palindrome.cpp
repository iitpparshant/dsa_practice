// https://leetcode.com/problems/find-the-closest-palindrome/description/

// 564. Find the Closest Palindrome

class Solution {
public:
    string nearestPalindromic(string n) {
        int l= n.size();
        if(l==1){
            return to_string(stoi(n)-1);
        }
        vector<long long>cd;
        cd.push_back(pow(10,l-1)-1);
        cd.push_back(pow(10,l)+1);
        long long pre= stoll(n.substr(0,(l+1)/2));
        for(int i=-1;i<=1;i++){
            string p= to_string(pre+i);
            string c= p+string(p.rbegin()+ (l%2),p.rend());
            // cout<<p<<" ";
            cd.push_back(stoll(c));
        }
        long long num= stoll(n);
        long long close=-1;
        for(long long it:cd){
            if(it==num){
                continue;
            }
            if(close==-1 || abs(it-num)< abs(close-num) || (abs(it-num)==abs(close-num)&& it<close)){
                close=it;
            }
        }
        return to_string(close);
    }
};