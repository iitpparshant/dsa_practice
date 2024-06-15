// https://leetcode.com/problems/valid-square/description/

//    593. Valid Square

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int d1=((p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]));
        int d2=((p3[0]-p2[0])*(p3[0]-p2[0])+(p3[1]-p2[1])*(p3[1]-p2[1]));
        int d3=((p4[0]-p2[0])*(p4[0]-p2[0])+(p4[1]-p2[1])*(p4[1]-p2[1]));
        int d4=((p1[0]-p3[0])*(p1[0]-p3[0])+(p1[1]-p3[1])*(p1[1]-p3[1]));
        int d5=((p1[0]-p4[0])*(p1[0]-p4[0])+(p1[1]-p4[1])*(p1[1]-p4[1]));
        int d6=((p3[0]-p4[0])*(p3[0]-p4[0])+(p3[1]-p4[1])*(p3[1]-p4[1]));
        unordered_map<int,int>mp;
        mp[d1]++;
        mp[d2]++;
        mp[d3]++;
        mp[d4]++;
        mp[d5]++;
        mp[d6]++;
        if(mp.size()!=2){
            return false;
        }
        int x,y;
        int c=-1 ,d=-1;
        for(auto it:mp){
            if(c==-1){
                c=it.first;
                x=it.second;
            }
            else if(d==-1){
                d=it.first;
                y=it.second;
            }
        }
        if(c==0 || d==0){
            return false;
        }
        if((x==4 && y==2)||(y==4&& x==2)){
            return true;
        }
        return false;
    }
};