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
    TreeNode* createOrFindNode(int val, unordered_map<int, pair<TreeNode*, int>>& trees, int childOf = 0) {
        TreeNode* root;
        if(trees.find(val) == trees.end()) {
                root = new TreeNode(val);
                trees[val] = {root, childOf};
        }
            else {
                root = trees[val].first;
                trees[val].second = max(childOf, trees[val].second);
            }
        return root;
    }
    
    TreeNode* findParent(unordered_map<int, pair<TreeNode*, int>>& trees) {
        TreeNode* parent = NULL;
        for(auto it : trees) {
            if(!it.second.second)
                parent = it.second.first;
        }
        return parent;
    }
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, pair<TreeNode*, int>> trees;
        
        for(auto& description : descriptions) {
            TreeNode* parent, *child;
            parent = createOrFindNode(description[0], trees);
            child = createOrFindNode(description[1], trees, 1);
            if(description[2])
                parent->left = child;
            else
                parent->right = child;
        }
        
        return findParent(trees);
    }
};