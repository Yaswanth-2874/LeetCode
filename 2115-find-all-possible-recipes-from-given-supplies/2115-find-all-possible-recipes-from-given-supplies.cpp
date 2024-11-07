class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> recipesMap;
        int index = 0;
        int items = recipes.size();
        unordered_set<string> availableIngredients;
        
        for(auto& ingredient : supplies) {
            availableIngredients.insert(ingredient);
        }
        
        for(auto& recipe : recipes) {
            recipesMap[recipe] = index++;
        }
        
        // creating a graph considering all recipes as vertices
        vector<vector<int>> graph(items);
        vector<int> indegrees(items);
        
        for(int itemIndex = 0; itemIndex < items; itemIndex++) {
            bool skip = false;
            for(auto& ingredient : ingredients[itemIndex]) {
                if(availableIngredients.find(ingredient) == availableIngredients.end()) {
                    if(recipesMap.find(ingredient) == recipesMap.end()) {
                        // cout<<"Cannot find "<<ingredient<<endl;
                        skip = true;
                        break;
                    }
                }
            }
            if(skip) {
                indegrees[itemIndex] = INT_MAX;
                continue;
            }
            
            for(auto& ingredient : ingredients[itemIndex]) {
                if(recipesMap.find(ingredient) != recipesMap.end()) {
                    int requiredRecipe = recipesMap[ingredient];
                    // current recipe's index is itemIndex
                    indegrees[itemIndex]++;
                    graph[requiredRecipe].push_back(itemIndex);
                }
            }
        }
        
        // Now graph is created, i push everything with indegree 0 in a queue
        
        queue<int> possibleRecipes;
        
        for(int itemIndex = 0; itemIndex < items; itemIndex++) {
            if(indegrees[itemIndex] == 0)
                possibleRecipes.push(itemIndex);
        }
        
        vector<string> allPossibleRecipes;
        
        while(!possibleRecipes.empty()) {
            int recipe = possibleRecipes.front();
            allPossibleRecipes.push_back(recipes[recipe]);
            possibleRecipes.pop();
            
            for(int& neighbourRecipes : graph[recipe]) {
                indegrees[neighbourRecipes]--;
                if(indegrees[neighbourRecipes] == 0)
                    possibleRecipes.push(neighbourRecipes);
            }
        }
        
        return allPossibleRecipes;
    }
};