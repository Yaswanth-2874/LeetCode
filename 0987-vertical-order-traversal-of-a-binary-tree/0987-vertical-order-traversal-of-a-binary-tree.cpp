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
    map<int, multiset<pair<int, int>>> verticalTraversalMap;
    vector<vector<int>> verticalTraversals;
    
    void traverse(TreeNode* root, int horizontalDistance = 0, int depthLevel = 0) {
        if (!root) return;
      
        verticalTraversalMap[horizontalDistance].insert({depthLevel, root->val});
        traverse(root->left, horizontalDistance - 1, depthLevel + 1);
        traverse(root->right, horizontalDistance + 1, depthLevel + 1);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        traverse(root);
        for (auto& it : verticalTraversalMap) {
            vector<int> traversal;
            for (auto& [_, num] : it.second) {
                traversal.push_back(num);
            }
            verticalTraversals.push_back(traversal);
        }
        return verticalTraversals;
    }
};
