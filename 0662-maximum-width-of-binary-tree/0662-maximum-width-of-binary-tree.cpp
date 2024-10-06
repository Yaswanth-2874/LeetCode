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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> pendingNodes;
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
                
                if(parentNode->left) {
                    pendingNodes.push({parentNode->left, (long long)(value - baseValue)* 2});
                    minLevelValue = min(minLevelValue, (int)((long long)(value - baseValue) * 2));
                    maxLevelValue = max(maxLevelValue, (int)((long long)(value - baseValue) * 2));
                }
                if(parentNode->right) {
                    pendingNodes.push({parentNode->right, (long long)(value - baseValue) * 2 + 1});
                    minLevelValue = min(minLevelValue, (int)((long long)(value - baseValue) * 2 + 1));
                    maxLevelValue = max(maxLevelValue, (int)((long long)(value - baseValue) * 2 + 1));
                }
            }
            maxWidth = max(maxWidth, maxLevelValue - minLevelValue + 1);
        }
        
        return maxWidth;
    }
};