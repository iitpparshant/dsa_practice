// https://leetcode.com/problems/satisfiability-of-equality-equations/description/

//                     990. Satisfiability of Equality Equations

int parent[26];
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        for(auto it:equations){
            int x= it[0]-'a';
            int y= it[3]-'a';
            if(it[1]=='='){
                parent[findUPar(x)]=findUPar(y); 
            }
        }
        for(auto it:equations){
            int x= it[0]-'a';
            int y= it[3]-'a';
            if(it[1]=='!'){
                if(findUPar(x)==findUPar(y)){
                    return false;
                }
            }
        }
        return true;
    }
};