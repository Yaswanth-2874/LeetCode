/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool verifyPath(ListNode* head, TreeNode* root) {
        if(!head)
            return true;
        if(!root)
            return false;
        
        if(root->val != head->val)
            return false;
        return verifyPath(head->next, root->left) || 
            verifyPath(head->next, root->right);
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root)
            return false;
        
        bool isValid = verifyPath(head, root);
        if(isValid)
            return true;
        
        return isSubPath(head, root->left) || isSubPath(head, root->right);
       
    }
};