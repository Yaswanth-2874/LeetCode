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
    map<int, vector<pair<int, int>>> verticalTraversalMap;
    vector<vector<int>> verticalTraversals;
    
    void traverse(TreeNode* root, int x = 0, int depth = 0) {
         if(!root)
            return;
        traverse(root->left, x-1, depth+1);
        verticalTraversalMap[x].push_back({depth, root->val});
        traverse(root->right, x+1, depth+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        traverse(root);
        for(auto& it : verticalTraversalMap) {
            vector<pair<int, int>> currentHorizontal = it.second;
            sort(currentHorizontal.begin(), currentHorizontal.end());
            vector<int> traversal;
            for(auto& [_, num] : currentHorizontal)
                traversal.push_back(num);
            verticalTraversals.push_back(traversal);
        }
        return verticalTraversals;
    }
};