class Solution {
    // There are 2 possible edges that i could remove and only one of them is correct to remove
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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        DisjointSet ds(edges.size() + 1);
        vector<int> parents(edges.size() + 1, 0);
        pair<int, int> edge1, edge2;
        
        for(auto& edge : edges) {
            int& source = edge[0];
            int& destination = edge[1];
            
            // If parent exists, then i can tell that its value is greater than 0 (since im using 1 based index)
            if(parents[destination] > 0) {
                edge1 = {parents[destination], destination};
                edge2 = {source, destination};
                cout<<parents[destination]<<" "<<destination<<endl;
                cout<<source<<" "<<destination<<endl;
                // Remove the edge temporarily to see if this is the acutal wrong edge
                source = destination = -1;
                break;
            } else {
                parents[destination] = source;
            }
        }
        
        for(auto& edge : edges) {
            if(edge[0] == -1)
                continue;
            int source = edge[0];
            int destination = edge[1];
            
            if(ds.unionMerge(source, destination) == false) {
                if(edge1.first)
                    return {edge1.first, edge2.second};
                return {source, destination};
            }
        }
        return {edge2.first, edge2.second};
    }
};
