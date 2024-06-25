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
    void reverseInorder(TreeNode* root, int& currentSum ) {
        if(!root)
            return;
        reverseInorder(root->right, currentSum);
        currentSum += root->val;
        root->val = currentSum;
        reverseInorder(root->left, currentSum);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        reverseInorder(root, sum);
        return root;
    }
};