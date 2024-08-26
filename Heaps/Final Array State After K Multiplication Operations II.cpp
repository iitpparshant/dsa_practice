// https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-ii/description/

// 3266. Final Array State After K Multiplication Operations II

class Solution {
public:
long long po(long long x,long long y,long long p) {
    long long res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
long long mod = 1e9 + 7;
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
         if (multiplier == 1) return nums;
        int n= nums.size();
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        for(int i=0;i<n;i++){
	        pq.push({nums[i],i});
	    }
        unordered_map<int,int>m,m1;
        while(1){
            if((int)m.size()==n || k==0){
                break;
            }
            long long x= pq.top().first;
            long long y= pq.top().second;
            pq.pop();
            x*=multiplier;
            pq.push({x,y});
            m[y]++;
            k--;
        }
        vector<long long>v(n);
        while(!pq.empty()){
	        pair<long long ,long long>t=pq.top();
	        pq.pop();
	        v[t.second]= t.first;
	    }
        long long dist= k/n;
	    long long r= k%n;
        for(int i=0;i<n;i++){
            pq.push({v[i],i});
        }
        while(!pq.empty()){
            int x= pq.top().second;
            m1[x]= dist;
            if(r>0){
                m1[x]++;
                r--;
            }
            pq.pop();
        }
        for(int i=0;i<n;i++){
            long long mlt = po(multiplier, m1[i],mod);
            v[i] = ((v[i]%mod)*(mlt%mod))%mod;
            nums[i] = v[i];
        }
        return nums;
    }
};