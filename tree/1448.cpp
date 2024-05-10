//  **********   BFS   *******   


class Solution {
public:
    int goodNodes(TreeNode* root) {
        int count=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,root->val});
        int mx= INT_MIN;
        int allmx= INT_MIN;
        while(!q.empty()){
            int s= q.size();
            while(s--){
                TreeNode* node= q.front().first;
                int mn= q.front().second;
                int mn2= q.front().second;
                q.pop();
                if(node->left){
                    if(node->left->val>=mn){
                        mn= node->left->val;
                        count++;
                    }
                    q.push({node->left,mn});
                }
                if(node->right){
                    if(node->right->val>=mn2){
                        mn2= node->right->val;
                        count++;
                    }
                    q.push({node->right,mn2});
                }
            }
            // mx= allmx;
        }
        return count+1;
    }
};


//  **********   DFS   *******   

class Solution {
public:
int count=1;
void isGood(TreeNode*root,int data){
    if(!root){
        return ;
    }
    if(root->val>=data){
        data= root->val;
        count++;
    }
    isGood(root->left,data);
    isGood(root->right,data);
}
    int goodNodes(TreeNode* root) {
        isGood(root->left,root->val);
        isGood(root->right,root->val);
        root->left= NULL;
        root->right=NULL;
        return count;
    }
};