//  https://leetcode.com/problems/create-binary-tree-from-descriptions/description/

//                                     2196. Create Binary Tree From Descriptions

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n= descriptions.size();
        int root=-1;
        unordered_map<int,int>par;
        unordered_map<int,TreeNode*>node;
        for(auto it:descriptions){
            int p= it[0];
            int c=it[1];
            int l=it[2];
            if(node.count(p)==0){
                node[p]= new TreeNode(p);
                if(par.count(p)==0){
                    // cout<<root<<" ";
                    root= p;
                }
            }
            if(node.count(c)==0){
                node[c]= new TreeNode(c);
            }
            par[c]=p;
            if(l==1){
                node[p]->left= node[c];
            }
            else if(l==0){
                node[p]->right= node[c];
            }
        }
        while(par.count(root)){
            root= par[root];
            // cout<<root;
        }
        return node[root];
    }
};