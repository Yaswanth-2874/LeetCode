class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& smallerArray = nums1.size() > nums2.size() ? nums2 : nums1;
        vector<int>& largerArray = nums1.size() > nums2.size() ? nums1 : nums2;
        unordered_map<int,int> freq;
        
        for(int num : smallerArray) {
            freq[num]++;
        }
        
        vector<int> ans;
        for(int num : largerArray) {
            if(freq[num]) {
                ans.push_back(num);
                freq[num]--;
            }
        }
        return ans;
    }
};