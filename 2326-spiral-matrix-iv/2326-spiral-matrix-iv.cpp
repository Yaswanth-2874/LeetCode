/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int currentDirection = 0;
        
        vector<vector<int>> matrix(m, vector<int> (n , -1));
        
        int i = 0, j = 0;
        while(head) {
            
            
            matrix[i][j] = head->val;
            head = head->next;
            int nextI = i + directions[currentDirection][0];
            int nextJ = j + directions[currentDirection][1];
            if(directions[currentDirection][0] && (nextI >= m || nextI < 0 || matrix[nextI][j] != -1)) {
                currentDirection++;
                if(currentDirection >= 4)
                    currentDirection %= 4;
                i+= directions[currentDirection][0];
                j+= directions[currentDirection][1];
                continue;
            }
            if(directions[currentDirection][1] && (nextJ >= n || nextJ < 0 || matrix[i][nextJ] != -1)) {
                currentDirection++;
                if(currentDirection >= 4)
                    currentDirection %= 4;
                i+= directions[currentDirection][0];
                j+= directions[currentDirection][1];
                continue;
            }
            i = nextI;
            j = nextJ;
        }
        
        return matrix;
    }
};