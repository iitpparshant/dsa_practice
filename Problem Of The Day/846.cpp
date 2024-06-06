// https://leetcode.com/problems/hand-of-straights/description/
//    **************      846. Hand of Straights      ****

//   Method 1

class Solution {
public:
bool solve(vector<int>&a,int g,int s,int n){
    int next= a[s]+1;
    a[s]=-1;
    int count=1;
    s+=1;
    while(s<n && count<g){
        if(a[s]==next){
            next= a[s]+1;
            a[s]=-1;
            count++;
        }
        s++;
    }
    return count==g;
}
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n= hand.size();
        if(n%groupSize!=0){
            return false;
        }
        sort(hand.begin(),hand.end());
        for(int i=0;i<n;i++){
            if(hand[i]>=0){
                if(!solve(hand,groupSize,i,n)){
                    return false;
                }
            }
        }
        return true;
    }
};


//   Method 2


class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n= hand.size();
        if(n%groupSize!=0){
            return false;
        }
        unordered_map<int,int>mp;
        sort(hand.begin(),hand.end());
        for(auto it:hand){
            mp[it]++;
        }
        for(int i=0;i<n;i++){
            if(mp[hand[i]]>0){
                int s= mp[hand[i]];
                for(int j=hand[i];j<hand[i]+groupSize;j++){
                    if(mp[j]<s){
                        return false;
                    }
                    mp[j]-=s;
                }
            }
        }
        return true;
    }
};