class Solution {
    int offset;
    vector<vector<int>> memo;

    int findTotalWays(vector<int>& nums, int target, int sum = 0, int index = 0) {
        if (index == nums.size())
            return sum == target;

        if (memo[index][sum + offset] != -1)
            return memo[index][sum + offset];

        int addCurr = findTotalWays(nums, target, sum + nums[index], index + 1);
        int subCurr = findTotalWays(nums, target, sum - nums[index], index + 1);

        memo[index][sum + offset] = addCurr + subCurr;
        return memo[index][sum + offset];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        offset = totalSum;

        memo.assign(nums.size(), vector<int>(2 * totalSum + 1, -1));

        return findTotalWays(nums, target);
    }
};
