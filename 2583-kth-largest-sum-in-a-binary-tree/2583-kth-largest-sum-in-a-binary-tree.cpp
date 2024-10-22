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
    // I can find sum of all elements and then sort to find the value of kth largest sum
    // The other way which is slightly better is ill use a min heap of size k
    // Time complexity would change from nlogn to nlogk
    public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        priority_queue<long long, vector<long long>, greater<long long>> levelSums;
        int level = 0;
        
        
        while(!q.empty()) {
            int size = q.size();
            long long currentSum = 0;
            
            while(size--) {
                TreeNode* node = q.front();
                q.pop();
                long long value = node->val;
                
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                
                currentSum += value;
            }
            int levelSumSize = levelSums.size();
            if(levelSumSize == k) {
                // I need to pop the least value if heap size is already k
                if(currentSum > levelSums.top()) {
                    levelSums.pop();
                    levelSums.push(currentSum);
                }                    
            } else {
                levelSums.push(currentSum);
            }
            level++;
        }
        
        if(levelSums.size() < k)
            return -1;
        
        return levelSums.top();
    }
};