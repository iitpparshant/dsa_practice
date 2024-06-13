// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

//   863. All Nodes Distance K in Binary Tree

//   Methode 1

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
unordered_map<TreeNode*,vector<TreeNode*>>graph;
vector<int>ans;
void makeGraph(TreeNode* root, TreeNode* prev){
    if(root==nullptr){
        return;
    }
    if(prev){
        graph[root].push_back(prev);
        graph[prev].push_back(root);
    }
    makeGraph(root->left,root);
    makeGraph(root->right,root);
}
void solve(TreeNode*node,int k,int dist,unordered_map<TreeNode*,bool>&vis){
    if(node==NULL ||vis[node]==1){
        return ;
    }
    vis[node]=1;
    if(dist==k){
        ans.push_back(node->val);
        return;
    }
    for(auto it:graph[node]){
        solve(it,k,dist+1,vis);
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        makeGraph(root,NULL);
        unordered_map<TreeNode*,bool>vis;
        solve(target,k,0,vis);
        return ans;
    }
};


//  methode 2 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
unordered_map<TreeNode*,TreeNode*>graph;
vector<int>ans;
unordered_map<TreeNode*,bool>vis;
void makeGraph(TreeNode* root, TreeNode* prev){
    if(root==nullptr){
        return;
    }
    graph[root]=prev;
    makeGraph(root->left,root);
    makeGraph(root->right,root);
}
void solve(TreeNode*node,int k,int dist){
    if(node==NULL ||vis[node]==1){
        return ;
    }
    vis[node]=1;
    if(dist==k){
        ans.push_back(node->val);
        return;
    }
    solve(node->left,k,dist+1);
    solve(node->right,k,dist+1);
    solve(graph[node],k,dist+1);
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        makeGraph(root,NULL);
        solve(target,k,0);
        return ans;
    }
};

//   methode 3

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
unordered_map<TreeNode*, TreeNode*> parent;
    vector<int> ans;
    
    void findParents(TreeNode* root, TreeNode* par) {
        if (root == nullptr) return;
        parent[root] = par;
        findParents(root->left, root);
        findParents(root->right, root);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        findParents(root, nullptr);
        unordered_map<TreeNode*, bool> visited;
        queue<pair<TreeNode*, int>> q;
        q.push({target, 0});
        visited[target] = true;
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int dist = q.front().second;
            q.pop();
            if (dist == k) {
                ans.push_back(node->val);
            }
            if (dist < k) {
                if (node->left && !visited[node->left]) {
                    q.push({node->left, dist + 1});
                    visited[node->left] = true;
                }
                if (node->right && !visited[node->right]) {
                    q.push({node->right, dist + 1});
                    visited[node->right] = true;
                }
                TreeNode* par = parent[node];
                if (par && !visited[par]) {
                    q.push({par, dist + 1});
                    visited[par] = true;
                }
            }
        }
        return ans;
    }
};