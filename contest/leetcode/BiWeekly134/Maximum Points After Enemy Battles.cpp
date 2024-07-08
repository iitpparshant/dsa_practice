//  https://leetcode.com/problems/maximum-points-after-enemy-battles/description/

//                                                  3207. Maximum Points After Enemy Battles

class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        long long sum=currentEnergy;
        int i= 0;
        int j=enemyEnergies.size()-1;
        sort(enemyEnergies.begin(),enemyEnergies.end());
        if(enemyEnergies[0] > currentEnergy) return 0;
        int count=0;
        long long point=0;
        while(j>=0){
            if(enemyEnergies[0]<=currentEnergy){
                point+=currentEnergy/enemyEnergies[0];
                currentEnergy %= enemyEnergies[0];
            }
            else{
                currentEnergy += enemyEnergies[j];
                j--;
            }
        }
        return point;
    }
};