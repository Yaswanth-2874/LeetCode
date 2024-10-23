class Solution {
    class DisjointSet {
        vector<int> parent, size;
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
        bool unionMerge(int nodeA, int nodeB) {
            int parentA = findParent(nodeA);
            int parentB = findParent(nodeB);
            
            if(parentA == parentB)
                return false;
            
            if(size[parentA] >= size[parentB]) {
                size[parentA] += size[parentB];
                parent[parentB] = parentA;
            } else {
                size[parentB] += size[parentA];
                parent[parentA] = parentB;
            }
            return true;
        }
    };
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSet ds(edges.size() + 1);
        
        for(auto& edge : edges) {
            int source = edge[0];
            int destination = edge[1];
            
            if(ds.unionMerge(source, destination) == false)
                return {source, destination};
        }
        return {-1, -1};
    }
};