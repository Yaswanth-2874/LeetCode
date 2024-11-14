class Solution {
    int storesRequired(int products, vector<int>& quantities) {
        int requiredStores = 0;
        
        for(int& quantity : quantities) {
            requiredStores += (quantity + products - 1) / products;
        }
        
        return requiredStores;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int minProducts = 1, maxProducts = 1e9;
        
        while(minProducts <= maxProducts) {
            int currentProducts = minProducts + (maxProducts - minProducts)/2;
            int requiredStores = storesRequired(currentProducts, quantities);
            
            // cout<<"Required "<<requiredStores<<" if i give "<<currentProducts<<" to each store"<<endl;
            if(requiredStores <= n)
                maxProducts = currentProducts - 1;
            else
                minProducts = currentProducts + 1;
        }
        
        return maxProducts + 1;
    }
};