class Solution {
    void dfs(int sourceRoom, vector<vector<int>>& rooms, vector<bool>& visitedRooms) {
        visitedRooms[sourceRoom] = true;
        
        for(auto& key : rooms[sourceRoom]) {
            if(!visitedRooms[key])
                dfs(key, rooms, visitedRooms);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visitedRooms(rooms.size());
        dfs(0, rooms, visitedRooms);
        for(auto visited : visitedRooms) {
            if(!visited)
                return false;
        }
        return true;        
    }
};