class Solution {
public:
vector<double>compute(double x,double y){
    return {x+y,x-y,y-x,x*y,x/y,y/x};
}
bool solve(vector<double>& a){
    if(a.size()==1){
        return abs(a[0]-24.0)<0.0001;
    }
    for(int i=0;i<a.size();i++){
        for(int j=i+1;j<a.size();j++){
            double x= a[i];
            double y=a[j];
            for(auto &it: compute(x,y)){
                vector<double>res;
                res.push_back(it);
                for(int k=0;k<a.size();k++){
                    if(k!=i && k!=j){
                        res.push_back(a[k]);
                    }
                }
                if(solve(res)==true){
                    return true;
                }
            }
        }
    }
    return false;
}
    bool judgePoint24(vector<int>& cards) {
        vector<double>a(cards.begin(),cards.end());
        return solve(a);
    }
};