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
vector<int>ans;
void sorted(TreeNode*root){
    if(root==NULL){
        return ;
    }
    sorted(root->left);
    ans.push_back(root->val);
    sorted(root->right);
}
TreeNode*bst(int s,int e){
    if(s>e){
        return NULL;
    }
    int m= (s+e)/2;
    TreeNode* root= new TreeNode(ans[m]);
    root->left= bst(s,m-1);
    root->right= bst(m+1,e);
    return root;
}
    TreeNode* balanceBST(TreeNode* root) {
        sorted(root);
        return bst(0,ans.size()-1);
    }
};