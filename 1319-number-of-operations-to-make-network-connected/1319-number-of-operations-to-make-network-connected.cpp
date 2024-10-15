class DisjointSet {
    vector<int> size, parent;
    
    public:
    DisjointSet(int n) {
        size.resize(n, 1);
        for(int i = 0; i < n; i++)
            parent.push_back(i);
    }
    
    int findParent(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }
    
    int unionSize(int nodeA, int nodeB) {
        int parentA = findParent(nodeA);
        int parentB = findParent(nodeB);
        
        if(parentA == parentB)
            return 1;
        
        if(size[parentA] >= size[parentB]) {
            parent[parentB] = parentA;
            size[parentA] += size[parentB];
        } else {
            parent[parentA] = parentB;
            size[parentB] += size[parentA];
        }
        
        return 0;
    }
    
    int findIsolated() {
        unordered_set<int> unique;
        for(int par : parent) {
            unique.insert(findParent(par));
        }
        return unique.size() - 1;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1)
            return -1;
        
        DisjointSet ds(n);
        int extraWires = 0;
        
        for(auto& connection : connections) {
            int nodeA = connection[0];
            int nodeB = connection[1];
            
            extraWires += ds.unionSize(nodeA, nodeB);
        }
        
        int extraConnections = ds.findIsolated();
        return extraConnections;
    }
};