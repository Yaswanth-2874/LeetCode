class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> rowMin, colMax, result;
        for(auto row : matrix) {
            int minElement = *min_element(row.begin(), row.end());
            rowMin.push_back(minElement);
        }
        for(int i = 0; i < matrix[0].size(); i++) {
            int maxElement = 0;
            for(int j = 0; j < matrix.size(); j++) {
                maxElement = max(matrix[j][i], maxElement);
            }
            colMax.push_back(maxElement);
        }
        
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++)
                if(matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j])
                    result.push_back(matrix[i][j]);
        }
        return result;
    }
};

