// Lets say that there are N stones
// Atmost there are N individual components
// The required ans = sigma (Component.size() - 1) for all components
// required ans = total - n where n = number of provinces/components

class DisjointSet {
 public:
    vector<int> parent, size;
    DisjointSet(int size) {
        this->size.resize(size, 1);
        for(int i = 0; i < size; i++)
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
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0;
        unordered_set<int> stonePos;
        
        for(auto& position : stones) {
            int rowPos = position[0];
            int colPos = position[1] + maxRow + 1;
            maxRow = max(maxRow, rowPos);
            maxCol = max(maxCol, colPos);
        }
        
        int size = maxRow + maxCol + 2;
        int maxComponents = stones.size();
        int uniqueCount = 0;
        
        DisjointSet ds(size);
        
        for(auto& position : stones) {
            int rowPos = position[0];
            int colPos = position[1];
            colPos += maxRow + 1;
            ds.unionMerge(rowPos, colPos);
            stonePos.insert(rowPos);
            stonePos.insert(colPos);
        }
        
        for(auto& pos : stonePos) {
            if(ds.parent[pos] == pos)
                uniqueCount++;
        }
        
        return maxComponents - uniqueCount;
    }
};