// First method   O(n*n)

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double,pair<int,int>>>pq;
        int n= arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                pq.push({((double)arr[i]/arr[j]),{arr[i],arr[j]}});
                if(pq.size()>k){
                    pq.pop();
                }
            }
        }
        return {pq.top().second.first,pq.top().second.second};
    }
};



// Second method O(nlog(n))

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n= arr.size();
        double l=0,r=1,m;
        vector<int>res;
        while(l<=r){
            m= l+(r-l)/2;
            int j=1,total=0,num=0,d=0;
            double mx=0;
            for(int i=0;i<n;i++){
                while(j<n && arr[i]>=arr[j]*m){
                    j++;
                }
                total+= n-j;
                if(j<n && mx< arr[i]*1.0/arr[j]){
                    mx= arr[i]*1.0/arr[j];
                    num=i;
                    d=j;
                }
            }
            if(total==k){
                res= {arr[num],arr[d]};
                break;
            }
            if(total>k){
                r=m;
            }
            else{
                l=m;
            }
        }
        return res;
    }
};