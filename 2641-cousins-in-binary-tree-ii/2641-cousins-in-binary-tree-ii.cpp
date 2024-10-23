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
    void replaceValues(TreeNode* root, vector<int>& levelSums, int depth) {
        if(!root)
            return;
        
        TreeNode* leftNode = root->left;
        TreeNode* rightNode = root->right;
        
        int childSum = 0;
        if(leftNode)
            childSum += leftNode->val;
        if(rightNode) {
            childSum += rightNode->val;
            rightNode->val = levelSums[depth + 1] - childSum;
        }
        if(leftNode)
            leftNode->val = levelSums[depth + 1] - childSum;
        
        replaceValues(leftNode, levelSums, depth+1);
        replaceValues(rightNode, levelSums, depth+1);
    }
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> levelSums;
        int level = 0;
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty()) {
            int qSize = q.size();
            int levelSum = 0;
            while(qSize--) {
                TreeNode* root = q.front();
                q.pop();
                
                levelSum += root->val;
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
            level++;
            levelSums.push_back(levelSum);
        }
        
        root->val = 0;
        replaceValues(root, levelSums, 0);
        return root;
    }
};