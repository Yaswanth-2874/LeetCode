/**
 * @param {number[]} nums
 * @return {number[]}
 */

var findDuplicates = function(nums) {
    var ans = [];
    nums.forEach((element) => {
        if(nums[Math.abs(element)-1] < 0) 
            ans.push(Math.abs(element));
        else 
            nums[Math.abs(element)-1] *= -1;
        // console.log(Math.abs(element) + '  ' + [...nums]);
    });
    
    
    return ans;
};