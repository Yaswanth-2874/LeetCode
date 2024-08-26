/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)
            return {};
        vector<vector<int>> levelOrderTraversal;
        queue<Node*> queue;
        queue.push(root);
        
        while(!queue.empty()) {
            int size = queue.size();
            vector<int> currentLevel;
            
            while(size--) {
                Node* front = queue.front();
                queue.pop();
                currentLevel.push_back(front->val);
                
                if(front->children.size())
                    for(auto& children : front->children) {
                        queue.push(children);
                    }
            }
            levelOrderTraversal.push_back(currentLevel);
        }
        return levelOrderTraversal;        
    }
};