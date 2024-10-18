class Solution {
    // MAP APPROACH WONT WORK WITH EDGE CASE LIKE {1, 2}, {3, 4}, {2, 3}
    // USE DISJOINT SET
    class DisjointSet {
        vector<int> parent, size;
    public:      
        DisjointSet(int n) {
            for(int i = 0; i < n; i++)
                parent.push_back(i);
            size.resize(n);
        }
        int findParent(int node) {
            if(parent[node] == node)
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailsMap;
        DisjointSet ds(accounts.size());
        
        for(int i = 0; i < accounts.size(); i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                string& email = accounts[i][j];
                if(emailsMap.find(email) != emailsMap.end()) {
                    ds.unionMerge(emailsMap[email], i);
                }
                emailsMap[email] = i;
            }       
        }
        
        vector<vector<string>> mergedAccounts;
        unordered_map<int, set<string>> commonEmails;
        
        for(int i = 0; i < accounts.size(); i++) {
            int parent = ds.findParent(i);
            
            for(int j = 1; j < accounts[i].size(); j++) {
                string& email = accounts[i][j];
                commonEmails[parent].insert(email);
            }
        }
        
        for(int i = 0; i < accounts.size(); i++) {
            int parent = ds.findParent(i);
            if(parent != i)
                continue;
            vector<string> mergedAccount;
            string& name = accounts[i][0];
            mergedAccount.push_back(name);
            for(auto& emails : commonEmails[i])
                mergedAccount.push_back(emails);
            mergedAccounts.push_back(mergedAccount);
        }
        
        return mergedAccounts;
    }
};