class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int direction = 0;
        
        set<pair<int, int>> obstaclesPos;
        for(auto obstacle : obstacles) {
            obstaclesPos.insert({obstacle[0], obstacle[1]});
        }
        
        int maxDistance = 0;
        int x = 0, y = 0;
        
        for(int command : commands) {
            if(command == -1) {
                direction++;
                direction %= 4;
            } else if(command == -2) {
                direction--;
                if(direction < 0)
                    direction += 4;
            } else {
                int distance = command;
                auto [i, j] = directions[direction];
                
                while(distance--) {
                    if(obstaclesPos.find({x+i, y+j}) != obstaclesPos.end()) {
                        break;
                    }
                    x += i;
                    y += j;
                }
                // cout<<x<<" "<<y<<endl;
                maxDistance = max(maxDistance, x*x + y*y);
            }
        }
        // cout<<endl;
        
        return maxDistance;
    }
};