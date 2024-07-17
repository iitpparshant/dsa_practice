// https://leetcode.com/problems/delete-nodes-and-return-forest/description/

//                                            1110. Delete Nodes And Return Forest

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
vector<TreeNode*>ans;
void deleteNode(TreeNode* &root,unordered_map<int,int>&mp){
    if(root){
        deleteNode(root->left,mp);
        deleteNode(root->right,mp);
        if(mp.find(root->val)!=mp.end()){
            if(root->left)ans.push_back(root->left);
            if(root->right)ans.push_back(root->right);
            root=NULL;
        }
    }
}
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int,int>mp;
        for(auto it:to_delete){
            mp[it]++;
        }
        deleteNode(root,mp);
        if(root){
            ans.push_back(root);
        }
        return ans;
    }
};