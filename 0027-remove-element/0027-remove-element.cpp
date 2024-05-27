class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for(auto& num : nums) {
            num != val && (nums[index++] = num);
        }
        return index;
    }
};