// Place the character with greatest count as long as streak is not 3
// If streak is about to reach 3, then place 2nd best choice

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string longestHappyString = "";
        priority_queue<pair<int, int>> pq;
        if(a > 0)
            pq.push({a, 0});
        if(b > 0)
            pq.push({b, 1});
        if(c > 0)
            pq.push({c, 2});
        vector<int> currentStreak(3, 0);
        
        while(!pq.empty()) {
            auto [count, character] = pq.top();
            // cout<<count<<" "<<(char)('a'+character)<<" before ";
            pq.pop();
            
            if(currentStreak[character] == 2) {
                if(pq.empty())
                    return longestHappyString;
                auto [secondBest, secondCharacter] = pq.top();
                pq.pop();
                longestHappyString.push_back(secondCharacter + 'a');
                secondBest--;
                if(secondBest)
                    pq.push({secondBest, secondCharacter});
                currentStreak[0] = currentStreak[1] = currentStreak[2] = 0;
                currentStreak[secondCharacter] = 1;
            } else {
                longestHappyString.push_back(character + 'a');
                count--;
                currentStreak[character]++;
                if(character != 0)
                    currentStreak[0] = 0;
                if(character != 1)
                    currentStreak[1] = 0;
                if(character != 2)
                    currentStreak[2] = 0;
            }
            if(count)
                pq.push({count, character});
            // cout<<count<<" "<<(char)('a'+character)<<" after "<<endl;
        }
        return longestHappyString;         
    }
};

// 5 4 3
// a
// 4 4 3
// ab
// 4 3 3
// aba
// 3 3 3
// abac
// 3 3 2
// abacb
// 3 2 2
// abacba
// 2 2 2
// abacbacbacba

// why wa? It should work