//   https://leetcode.com/problems/word-ladder/description/

//          127. Word Ladder

//             first method 
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.insert(wordList.begin(),beginWord);
        int n= wordList.size();
        int m= beginWord.size();
        vector<vector<int>>graph(n);
        int end=-1;
        for(int i=0;i<n;i++){
            if(wordList[i]==endWord){
                end=i;
            }
            for(int j=i+1;j<n;j++){
                int count=0;
                for(int k=0;k<m;k++){
                    if(wordList[i][k]==wordList[j][k]){
                        count++;
                    }
                }
                if(count==m-1){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        if(end==-1){
            return 0;
        }
        vector<int>dist(n,INT_MAX);
        queue<int>q;
        q.push(0);
        dist[0]=1;
        while(!q.empty()){
            int x= q.front();
            q.pop();
            for(auto it:graph[x]){
                if(dist[it]> dist[x]+1){
                    dist[it]= dist[x]+1;
                    q.push(it);
                }
            }
        }
        if(dist[end]==INT_MAX){
            return 0;
        }
        return dist[end];
    }
};

//          second method 

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s(wordList.begin(),wordList.end());
        queue<string>q;
        unordered_map<string,int>mp;
        mp[beginWord]=1;
        int count=1;
        q.push(beginWord);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string t= q.front();
                q.pop();
                if(t==endWord){
                    return count;
                }
                for(int i=0;i<t.size();i++){
                    char y= t[i];
                    for(int j=0;j<26;j++){
                        t[i] =j+97;
                        if(!mp[t]&&s.find(t)!=s.end()){
                            q.push(t);
                            mp[t]=1;
                        }
                    }
                    t[i]=y;
                }
            }
            count++;
        }
        return 0;
    }
};