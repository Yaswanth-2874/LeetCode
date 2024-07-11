/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> visited;
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        Node* clonedNode = new Node(node->val);
        visited[node] = clonedNode;
        for(int i = 0; i < node->neighbors.size(); i++) {
            Node* nxtNode = node->neighbors[i];
            if(visited.find(nxtNode) != visited.end())
                clonedNode->neighbors.push_back(visited[nxtNode]);
            else
                clonedNode->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return clonedNode;
    }
};