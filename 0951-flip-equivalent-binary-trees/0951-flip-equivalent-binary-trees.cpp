/*+
 * Definition for a binar**-*y tree node.
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
    bool areTheyEqual(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2)
            return true;
        if(!root1 || !root2)
            return false;
        
        int leftChildA = -1, leftChildB = -1;
        if(root1->left)
            leftChildA = root1->left->val;
        if(root2->left)
            leftChildB = root2->left->val;
        
        int rightChildA = -1, rightChildB = -1;
        if(root1->right)
            rightChildA = root1->right->val;
        if(root2->right)
            rightChildB = root2->right->val;
        
        // cout<<leftChildA<<" left "<<leftChildB<<endl;
        // cout<<rightChildA<<" right "<<rightChildB<<endl;
        
        if(leftChildA != rightChildB && leftChildA != leftChildB)
            return false;
        if(rightChildA != leftChildB && rightChildA != rightChildB)
            return false;
        
        if(leftChildA == leftChildB) {
            // cout<<"Left Left Map"<<endl;
            return areTheyEqual(root1->left, root2->left) && areTheyEqual(root1->right, root2->right);
        }
        
        // cout<<"Left Right Map"<<endl;
        return areTheyEqual(root1->left, root2->right) && areTheyEqual(root1->right, root2->left);
    }
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 && root2 && root1->val != root2->val)
            return false;
        return areTheyEqual(root1, root2);
    }
};