class Solution {
    #define all(skill) skill.begin(), skill.end(), 0
public:
    long long dividePlayers(vector<int>& skill) {
        map<int, int> skillMap;
        long long teamChemistry = 0;
        int n = skill.size();
        int totalSkill = accumulate(all(skill));
        
        if(totalSkill % (n / 2) != 0)
            return -1;
        
        int targetSkill = totalSkill / (n / 2);
        
        for(int& playerSkill : skill) {
            int currentTarget = targetSkill - playerSkill;
            
            if(skillMap.find(currentTarget) != skillMap.end()) {
                skillMap[currentTarget]--;
                if(skillMap[currentTarget] == 0)
                    skillMap.erase(currentTarget);
                teamChemistry += ((long long)currentTarget * playerSkill);
            } else {
                skillMap[playerSkill]++;
            }
        }
        if(!skillMap.empty())
            return -1;
        return teamChemistry;
    }
};