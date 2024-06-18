//   https://leetcode.com/problems/invalid-transactions/description/

//      1169. Invalid Transactions


class Solution {
public:
pair<pair<string,string>,pair<int,int>>solve(string t){
    string c1,c2;
    int n1=0,n2=0;
    int a=-1,b=-1,c=-1,d=-1;
    for(int i=0;i<t.size();i++){
        if(a==-1){
            c1+=t[i];
            if(t[i+1]==','){
                a=0;
                i++;
            }
        }
        else if(b==-1){
            n1*=10;
            n1+= (t[i]-'0');
            if(t[i+1]==','){
                b=0;
                i++;
            }
        }
        else if(c==-1){
            n2*=10;
            n2+=(t[i]-'0');
            if(t[i+1]==','){
                c=0;
                i++;
            }
        }
        else if(d==-1){
            c2+=t[i];
        }
    }
    return {{c1,c2},{n1,n2}};
}
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n= transactions.size();
        sort(transactions.begin(),transactions.end());
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            pair<pair<string,string>,pair<int,int>>temp1= solve(transactions[i]);
            if(temp1.second.second>=1000){
                // cout<<i<<temp1.second.second;
                vis[i]=1;
            }
            for(int j=i+1;j<n;j++){
                pair<pair<string,string>,pair<int,int>>temp2= solve(transactions[j]);
                if((temp1.first.first==temp2.first.first) && (abs(temp1.second.first-temp2.second.first)<=60) && (temp1.first.second!=temp2.first.second)){
                    vis[i]=1;
                    vis[j]=1;
                }
            }
        }
        vector<string>ans;
        for(int i=0;i<n;i++){
            // cout<<vis[i];
            if(vis[i]==1){
                ans.push_back(transactions[i]);
            }
        }
        return ans;
    }
};