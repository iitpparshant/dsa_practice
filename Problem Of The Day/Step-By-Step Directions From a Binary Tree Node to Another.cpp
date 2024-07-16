// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/

//                                        2096. Step-By-Step Directions From a Binary Tree Node to Another

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
TreeNode*LCA(TreeNode* root, int startValue, int destValue){
    if(!root || root->val==startValue || root->val== destValue){
        return root;
    }
    TreeNode*l=LCA(root->left,startValue,destValue);
    TreeNode*r=LCA(root->right,startValue,destValue);
    if(!l){
        return r;
    }
    if(!r){
        return l;
    }
    return root;
}
bool solve(TreeNode* root, int x,string &s,bool f){
    if(!root){
        return 0;
    }
    if(root->val==x){
        return 1;
    }
    s+=(f?'U':'L');
    if(solve(root->left,x,s,f)){
        return 1;
    }
    s.pop_back();
    s+=(f?'U':'R');
    if(solve(root->right,x,s,f)){
        return 1;
    }
    s.pop_back();
    return 0;
}
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode*lca= LCA(root,startValue,destValue);
        string pathFrom="",pathTo="";
        solve(lca,startValue,pathFrom,1);
        solve(lca,destValue,pathFrom,0);
        return pathFrom+pathTo;
    }
};