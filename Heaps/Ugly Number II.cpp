//  https://leetcode.com/problems/ugly-number-ii/description/

//                    264. Ugly Number II


//                                   first method 

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int count = 1;
        pq.push(1);
        unordered_set<int> s;
        s.insert(1);
        while (count < n) {
            long long x = pq.top();
            pq.pop();
            long long p = x * 2, q = x * 3, r = x * 5;
            if (p<=INT_MAX  && s.find(p) == s.end()) {
                s.insert(p);
                pq.push(p);
            }
            if (q<=INT_MAX  && s.find(q) == s.end()) {
                s.insert(q);
                pq.push(q);
            }
            if (r<=INT_MAX  && s.find(r) == s.end()) {
                s.insert(r);
                pq.push(r);
            }
            count++;
        }
        return pq.top();
    }
};




//                                     second method


class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1){
            return 1;
        }
        vector<int>ans(n);
        ans[0]=1;
        int x=2,y=3,z=5;
        int j=0,k=0,l=0;
        for(int i=1;i<n;i++){
            int p= min(x,min(y,z));
            ans[i]=p;
            if(p==x){
                j++;
                x=ans[j]*2;
            }
            if(p==y){
                k++;
                y=ans[k]*3;
            }
            if(p==z){
                l++;
                z=ans[l]*5;
            }
        }
        return ans[n-1];
    }
};