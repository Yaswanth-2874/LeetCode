class Solution {
    //Easy but i need to learn and use Tries in this, anyone can solve it using set
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        set<string> knownFolders;
        int n = folder.size();
        sort(folder.begin(), folder.end());
        
        for(auto& location : folder) {
            string directory = "/"; 
            for(int i = 1; i < location.size(); i++) {
                while(i < location.size() && location[i] != '/') {
                    directory.push_back(location[i++]);
                }
                if(knownFolders.find(directory) != knownFolders.end())
                    break;
                if(i != location.size())
                    directory.push_back('/');
            }
            knownFolders.insert(directory);
        }
        vector<string> requiredFolders;
        for(string folder : knownFolders) {
            requiredFolders.push_back(folder);
        }
        return requiredFolders;
    }
};