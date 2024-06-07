// https://leetcode.com/problems/replace-words/
//  ****  648. Replace Words       *****

class Trie {
public:
    Trie* children[26];
    bool isEnd;
    Trie() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isEnd = false;
    }
};
class Solution {
public:
    Trie* root;
    Solution() { root = new Trie(); }
    void insert(string word) {
        Trie* node = root;
        for (char c : word) {
            int i = c - 'a';
            if (node->children[i] == NULL) {
                node->children[i] = new Trie();
            }
            node = node->children[i];
        }
        node->isEnd = true;
    }
    string search(string word){
        Trie*node= root;
        string res;
        for(char c:word){
            int i= c-'a';
            if(node->children[i]==NULL){
                return word;
            }
            res+=c;
            if(node->children[i]->isEnd){
                return res;
            }
            node= node->children[i];
        }
        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        for (string word : dictionary) {
            insert(word);
        }
        stringstream ss(sentence);
        string word,res;
        while(ss>>word){
            if(!res.empty()){
                res+=" ";
            }
            res+= search(word);
        }
        return res;
    }
};