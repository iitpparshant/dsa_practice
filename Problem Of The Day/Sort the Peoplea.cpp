// https://leetcode.com/problems/sort-the-people/description/

//                                        2418. Sort the People


class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n= names.size();
        vector<pair<int,string>>temp(n);
        for(int i=0;i<n;i++){
            temp[i]= {heights[i],names[i]};
        }
        sort(temp.begin(),temp.end(),greater<>());
        for(int i=0;i<n;i++){
            names[i]= temp[i].second;
        }
        return names;
    }
};