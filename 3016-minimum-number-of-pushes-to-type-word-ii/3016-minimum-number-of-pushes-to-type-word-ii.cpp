class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26);
        for(char& ch : word)
            freq[ch-'a']++;
        sort(freq.begin(), freq.end(), greater<int>());
        
        int count = 0, k = 0;
        for(auto& it : freq) {
            // cout<<"Freq of "<<it.first << " is "<<it.second<<endl;
            k++;
            if(k <= 8)
                count += it;
            else if (k <= 16)
                count += 2 * it;
            else if (k <= 24)
                count += 3 * it;
            else
                count += 4 * it;
        }
        return count;
    }
};