// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/

//                                              1339. Maximum Product of Splitted Binary Tree

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
unordered_map<TreeNode*,long long>mp;
int totalSum = 0;
long long maxProductValue=0;
int solve(TreeNode*root){
    if(!root){
        return 0;
    }
    long long x= solve(root->left);
    long long y= solve(root->right);
    return mp[root]= root->val+x+y;
}
void findMaxProduct(TreeNode* root) {
        if (!root) return;
        if (root->left) {
            int leftSum = mp[root->left];
            maxProductValue = max(maxProductValue, (long long)leftSum * (totalSum - leftSum));
        }
        if (root->right) {
            int rightSum = mp[root->right];
            maxProductValue = max(maxProductValue, (long long)rightSum * (totalSum - rightSum));
        }
        findMaxProduct(root->left);
        findMaxProduct(root->right);
    }
    int maxProduct(TreeNode* root) {
        solve(root);
        totalSum=mp[root];
        findMaxProduct(root);
        return maxProductValue%1000000007;
    }
};