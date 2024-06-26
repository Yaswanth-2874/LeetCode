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
    void inorder(TreeNode* root,vector<int>& inorderTraversal) {
        if(!root)
            return;
        inorder(root->left, inorderTraversal);
        inorderTraversal.push_back(root->val);
        inorder(root->right, inorderTraversal);
    }
    
    TreeNode* createBalanceBST(vector<int>& inorder, int left, int right) {
        if(left > right) return NULL;
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left =  createBalanceBST(inorder, left, mid - 1);
        root->right = createBalanceBST(inorder, mid+1, right);
        
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorderTraversal;
        inorder(root, inorderTraversal);
        
        return createBalanceBST(inorderTraversal, 0, inorderTraversal.size()-1);
        
    }
};