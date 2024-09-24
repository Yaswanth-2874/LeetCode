class Solution {
    int n;
    vector<pair<int, int>> positions;
    
    int bfs(vector<vector<int>>& graph) {
        int distance = 0;
        queue<int> q;
        q.push(1);
        vector<bool> visited(graph.size(), false);
        visited[1] = true;
        
        while(!q.empty()) {
            distance++;
            int size = q.size();
            
            while(size--) {
                int current = q.front();
                q.pop();

                for(int child : graph[current]) {
                    if(child == n*n)
                        return distance;
                    if(!visited[child])
                        q.push(child);
                    visited[child] = true;
                }
            }
        }
        return -1;
    }    
    pair<int, int> findRowAndCol(int target) {
        int current = 0, row = -1, col = -1;
        bool leftRight = true;
        if(positions[target].first != -1)
            return positions[target];
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = 0; j <= n-1; j++) {
                current++;
                if(leftRight) {
                    // cout<<target<<" : "<<i<<", "<<j<<endl;
                    positions[current] =  {i, j};
                } else {
                // cout<<target<<" : "<<i<<", "<<n - j - 1<<endl;
                positions[current] = {i, n - j - 1};
                }
            }
            leftRight = !leftRight;
        }
        return positions[target];
    }    
    void buildGraph(vector<vector<int>>& graph, vector<vector<int>>& board, int current) {
        for(int i = 1; i <= 6; i++) {
            int target = current + i;
            target = min(target, n*n);
            auto [row, col] = findRowAndCol(target);
            if(board[row][col] != -1) {
                graph[current].push_back(board[row][col]);
            } else {
                graph[current].push_back(target);
            }
        }
    }
 public:
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        positions = vector<pair<int, int>> (n*n + 1, {-1, -1});

        
        vector<vector<int>> graph((n*n) + 1);
        
        for(int i = 1; i <= n*n; i++)
            buildGraph(graph, board, i);
        
        // for(int i = 1; i <= n*n; i++) {
        //     cout<<i<<" : ";
        //     for(int child : graph[i])
        //         cout<<child<<" ";
        //     cout<<endl;
        // }
        return bfs(graph);
    }
};

// 36 35 34 33 32 31
// 25 26 27 28 29 30
// 24 23 22 21 20 19
// 13 14 15 16 17 18
// 12 11 10 9 8 7
// 1 2 3 4 5 6