class Solution {
    // I know for sure this will work but i am not happy as my code is not fully optimised
    double findValue(vector<vector<pair<int, double>>>& graph, int source, int destination, vector<bool>& visited) {
        if(source == destination)
            return 1;
        
        if(visited[source])
            return -1;
        visited[source] = true;
        
        for(auto& [nextNode, weight] : graph[source]) {
            
            double value = findValue(graph, nextNode, destination, visited);
            if(value >= 0)
                return value * weight;
        }
        return -1;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> existingVariable;
        int assignedIndex = 1;
        int maxPossibleUniques = 2 * (int)equations.size();
        int n = values.size();
        
        vector<vector<pair<int, double>>> graph(maxPossibleUniques + 1);
        
        for(int i = 0; i < values.size(); i++) {
            string& numerator = equations[i][0];
            string& denominator = equations[i][1];
            if(existingVariable[numerator] == 0)
                existingVariable[numerator] = assignedIndex++;
            if(existingVariable[denominator] == 0)
                existingVariable[denominator] = assignedIndex++;
            
            int source = existingVariable[numerator];
            int destination = existingVariable[denominator];
            double weight = values[i];
            
            graph[source].push_back({destination, weight});
            graph[destination].push_back({source, 1.0/weight});
        }
        
        vector<double> calculatedValues;
        for(auto& query : queries) {
            int source = existingVariable[query[0]];
            int destination = existingVariable[query[1]];
            
            if(source == 0 || destination == 0) {
                calculatedValues.push_back(-1);
                continue;
            }
            vector<bool> visited(n);
            calculatedValues.push_back(findValue(graph, source, destination, visited));
        }     
        return calculatedValues;
    }
};