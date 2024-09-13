class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prefixXor(arr.size() + 1, 0);
        
        for(int i = 0; i < arr.size(); i++) {
            prefixXor[i + 1] = prefixXor[i] ^ arr[i];
        }
        
        vector<int> queryResults;
        for(auto query : queries) {
            int result = prefixXor[query[1] + 1] ^ prefixXor[query[0]];
            queryResults.push_back(result);
        }
        
        return queryResults;
    }
};