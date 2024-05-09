class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        int s=0;
        long long sum=0;
        for(int i= happiness.size()-1;i>=0;i--){
            if((happiness[i]-s)>=0){
              sum+=(happiness[i]-s);  
            }
            
            k--;
            s++;
            if(k==0){
                return sum;
            }
        }
        return sum;
    }
};