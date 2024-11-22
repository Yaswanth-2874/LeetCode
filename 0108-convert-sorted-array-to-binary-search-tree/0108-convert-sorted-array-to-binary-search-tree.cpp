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
    TreeNode* createBST(vector<int>& nums, int left, int right) {
        if(left > right)
            return NULL;
        
        int mid = left + (right - left)/2;
        TreeNode* newNode = new TreeNode(nums[mid]);
        newNode -> left = createBST(nums, left, mid - 1);
        newNode -> right = createBST(nums, mid + 1, right);
        
        return newNode;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int nodes = nums.size();
        TreeNode* root = createBST(nums, 0, nodes - 1);
        
        return root;
    }
};