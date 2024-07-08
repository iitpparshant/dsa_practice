//  https://leetcode.com/problems/koko-eating-bananas/description/
//                                        875. Koko Eating Bananas


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        long long s=1;
        int n= piles.size();
        long long e= piles[n-1];
        long long ans=INT_MAX;
        while(s<=e){
            long long m= (s+e)/2;
            long long count=0;
            for(int i=0;i<n;i++){
                count+=(piles[i]+m-1)/m;
            }
            cout<<count;
            if(count<=h){
                e=m-1;
                ans= min(ans,m);
            }
            else{
                s=m+1;
            }
        }
        return s;
    }
};