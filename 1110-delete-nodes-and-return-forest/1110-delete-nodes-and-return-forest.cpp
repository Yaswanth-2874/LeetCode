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
    vector<TreeNode*> forest;
    bool deleteChild(TreeNode* root, unordered_set<int> to_delete) {
        if(!root)
            return false;
        if(deleteChild(root->left, to_delete))
            root->left = NULL;
        if(deleteChild(root->right, to_delete))
            root->right = NULL;
        if(to_delete.find(root->val) != to_delete.end()) {
            if(root->left)
                forest.push_back(root->left);
            if(root->right)
                forest.push_back(root->right);
            return true;
        }
        return false;
        
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> deleteElements;
        for(int num : to_delete)
            deleteElements.insert(num);
        deleteChild(root, deleteElements);
        
        if(deleteElements.find(root->val) == deleteElements.end())
            forest.push_back(root);
        
        return forest;
    }
};