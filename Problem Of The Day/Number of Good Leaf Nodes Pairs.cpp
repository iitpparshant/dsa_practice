// https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/

//                                      1530. Number of Good Leaf Nodes Pairs

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
    unordered_map<TreeNode*, vector<TreeNode*>> adj;
    unordered_set<TreeNode*> leafNodes;

    void buildGraph(TreeNode* node) {
        if (!node) return;
        if (node->left) {
            adj[node].push_back(node->left);
            adj[node->left].push_back(node);
            buildGraph(node->left);
        }
        if (node->right) {
            adj[node].push_back(node->right);
            adj[node->right].push_back(node);
            buildGraph(node->right);
        }
        if (!node->left && !node->right) {
            leafNodes.insert(node);
        }
    }

    int dfs(TreeNode* node, TreeNode* parent, int distance, int step) {
        if (step > distance) return 0;

        int count = 0;
        if (step > 0 && step <= distance && leafNodes.count(node)) {
            count++;
        }

        for (auto neighbor : adj[node]) {
            if (neighbor != parent) {
                count += dfs(neighbor, node, distance, step + 1);
            }
        }

        return count;
    }

    int countPairs(TreeNode* root, int distance) {
        if (!root) return 0;

        // Build the adjacency list representation of the tree
        buildGraph(root);

        int totalPairs = 0;

        for (auto leaf : leafNodes) {
            totalPairs += dfs(leaf, nullptr, distance, 0);
        }

        // Each pair is counted twice, so divide by 2
        return totalPairs / 2;
    }
};