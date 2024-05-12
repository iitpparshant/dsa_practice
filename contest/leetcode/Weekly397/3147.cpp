class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n= energy.size();
        
        int ans= INT_MIN;
        for(int i=0;i<n;i++){
            if(i-k>=0){
                energy[i]= max(energy[i], energy[i]+energy[i-k]);
            }
            
        }
        for(int i=n-k;i<n;i++){
            ans= max(ans,energy[i]);
        }
        return ans;
    }
};