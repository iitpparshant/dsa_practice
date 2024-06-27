// https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/description/

//                       381. Insert Delete GetRandom O(1) - Duplicates allowed


class RandomizedCollection {
public:
    unordered_map<int,set<int>>mp;
    vector<int>v;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        v.push_back(val);
        mp[val].insert(v.size()-1);
        return mp[val].size()<=1;
    }
    
    bool remove(int val) {
        if(mp[val].size()==0){
            return false;
        }
        int idx= *mp[val].begin();
        mp[val].erase(idx);
        int n= v.size()-1;
        int l= v.back();
        swap(v[idx],v[n]);
        mp[l].insert(idx);
        mp[l].erase(n);
        v.pop_back();
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */