class Solution {
    
    void mergeSort(vector<int>& nums, int left, int right) {
        if(left >= right)
            return;
        int mid = left + (right - left)/2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);
        merge(nums, left, mid, right);
    }
    
    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> sortedList;
        int indx1 = left, indx2 = mid + 1;
        while (indx1 < mid + 1 && indx2 < right + 1) {
            if (nums[indx1] <= nums[indx2]) {
                sortedList.push_back(nums[indx1++]);
            } else {
                sortedList.push_back(nums[indx2++]);
            }
        }
        while (indx1 < mid + 1) {
            sortedList.push_back(nums[indx1++]);
        }
        while (indx2 < right + 1) {
            sortedList.push_back(nums[indx2++]);
        }
        int indx = left;
        for (auto num : sortedList) {
            nums[indx++] = num;
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};