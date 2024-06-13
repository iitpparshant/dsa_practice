//  https://leetcode.com/problems/binary-tree-inorder-traversal/description/

//  94. Binary Tree Inorder Traversal

//   ** method 1

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
void solve(TreeNode*root, vector<int>&ans){
    if(root==NULL){
        return ;
    }
    solve(root->left,ans);
    ans.push_back(root->val);
    solve(root->right,ans);
}
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        solve(root,ans);
        return ans;
    }
};


//  method 2
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

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
        // inordertraversal(root,v);
        TreeNode* curr= root;
        while(curr!=NULL){
            if(curr->left==NULL){
                v.push_back(curr->val);
                curr= curr->right;
            }
            else{
                TreeNode* temp= curr->left;
                while(temp->right!=NULL&& temp->right!=curr){
                    temp= temp->right;
                }
                if(temp->right==NULL){
                    temp->right= curr;
                    curr=curr->left;
                }
                else{
                    temp->right=NULL;
                    v.push_back(curr->val);
                    curr= curr->right;
                }
            }
        }
        return v;
    }
};


//   method 3  

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st;
        while(root!=nullptr || !st.empty()){
            while(root!=nullptr){
                st.push(root);
                root= root->left;
            }
            root = st.top();
            st.pop();
            ans.push_back(root->val);
            root= root->right;
        }
        return ans;
    }
};