class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> edges(n);
        for(auto& road : roads) {
            edges[road[0]]++;
            edges[road[1]]++;
        }
        sort(edges.begin(), edges.end(), greater<int> ());
        long long maximumImportance = 0;
        long long value = n;
        for(int num : edges) {
            maximumImportance += num * value--;
        }
        return maximumImportance;
    }
};

