/**
 * @param {number[]} nums
 * @return {number}
 */
var findDuplicate = function(nums) {
    var fast = nums[nums[0]];
    var slow = nums[0];
    
    while(fast != slow) {
        fast = nums[nums[fast]];
        slow = nums[slow];
    }
    slow = 0;
    while(fast != slow) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
};