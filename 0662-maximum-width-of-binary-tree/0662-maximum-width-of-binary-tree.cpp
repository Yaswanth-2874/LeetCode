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

// TRYING NOT TO USE LONG LONG

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> pendingNodes;
        pendingNodes.push({root, 1});
        int maxWidth = 1;
        
        while(!pendingNodes.empty()) {
            int size = pendingNodes.size();
            int minLevelValue = INT_MAX;
            int maxLevelValue = 0;
            int baseValue = pendingNodes.front().second;
            
            while(size--) {
                auto [parentNode, value] = pendingNodes.front();
                pendingNodes.pop();
                value -= baseValue;
                
                if(parentNode->left) {
                    pendingNodes.push({parentNode->left, value* 2LL});
                    minLevelValue = min(minLevelValue, (int) (value * 2LL));
                    maxLevelValue = max(maxLevelValue, (int) (value * 2LL));
                }
                if(parentNode->right) {
                    pendingNodes.push({parentNode->right, value * 2LL + 1});
                    minLevelValue = min(minLevelValue, (int) (value * 2LL + 1));
                    maxLevelValue = max(maxLevelValue, (int) (value * 2LL + 1));
                }
            }
            maxWidth = max(maxWidth, maxLevelValue - minLevelValue + 1);
        }
        
        return maxWidth;
    }
};