class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,int>>ratio;
        int n= quality.size();
        for(int i=0;i<n;i++){
            ratio.push_back({static_cast<double>(wage[i])/quality[i],i});
        }
        sort(ratio.begin(),ratio.end());
        priority_queue<int>pq;
        double maxR= 0.0;
        int qua=0;
        for(int i=0;i<k;i++){
            qua+= quality[ratio[i].second];
            maxR= max(maxR,static_cast<double>(ratio[i].first));
            pq.push(quality[ratio[i].second]);
        }
        double pay= maxR*qua;
        for(int i=k;i<n;i++){
            maxR= max(maxR,static_cast<double>(ratio[i].first));
            qua-= pq.top();
            pq.pop();
            qua+= quality[ratio[i].second];
            pq.push(quality[ratio[i].second]);
            pay= min(pay,(double)maxR*qua);
        }
        return pay;
    }
};