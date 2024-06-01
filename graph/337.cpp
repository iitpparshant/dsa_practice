//     House Robber III
//    https://leetcode.com/problems/house-robber-iii/description/      

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
int solve(unordered_map<TreeNode*,int>&mp,TreeNode* root){
    if(!root){
        return 0;
    }
    int sum= root->val;
    int n=0;
    if(mp.find(root)!=mp.end()){
        return mp[root];
    }
    if(root->left){
        sum+= solve(mp,root->left->left)+solve(mp,root->left->right);
    }
    if(root->right){
        sum+= solve(mp,root->right->left)+solve(mp,root->right->right);
    }
    n= solve(mp,root->left)+solve(mp,root->right);
    return mp[root]= max(sum,n);
}
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int>mp;
        return solve(mp,root);
    }
};