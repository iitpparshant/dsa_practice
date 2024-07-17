// https://leetcode.com/problems/count-nodes-with-the-highest-score/description/

//                           2049. Count Nodes With the Highest Score

class Solution {
public:
void solve(vector<int>adj[],int node,vector<int>&s){
    s[node]++;
    for(auto it:adj[node]){
        solve(adj,it,s);
        s[node]+=s[it];
    }
}
    int countHighestScoreNodes(vector<int>& parents) {
        int n= parents.size();
        vector<int>adj[n];
        for(int i=1;i<n;i++){
            adj[parents[i]].push_back(i);
        }
        vector<int>size(n,0);
        solve(adj,0,size);
        // for(int i=0;i<n;i++){
        //     cout<<size[i]<<" ";
        // }
        int count=1;
        long long res= 0;
        for(int i=0;i<n;i++){
            long long ans=1;
            for(auto it:adj[i]){
                ans*=size[it];
            }
            if(i!=0){
                ans*= (n-size[i]);
            }
            // cout<<ans<<" ";
            if(res<ans){
                res= ans;
                count=1;
            }
            else if(res==ans){
                count++;
            }
        }
        return count;
    }
};