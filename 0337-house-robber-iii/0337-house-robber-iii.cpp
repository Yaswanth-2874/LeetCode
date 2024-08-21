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
    map<pair<TreeNode*, bool>, int> memo;
public:
    int rob(TreeNode* root, bool canRob = true) {
        if(!root)
            return 0;
        if(memo.find({root, canRob}) != memo.end())
            return memo[{root, canRob}];
        
        int robCurrent = -1;
        if(canRob)
            robCurrent = root->val + rob(root->left, false) + rob(root->right, false);
        
        int dontRobCurrent = rob(root->left, true) + rob(root->right, true);
        
        return memo[{root, canRob}] = max(robCurrent, dontRobCurrent);
    }
};