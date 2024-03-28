/**
 * @param {string} blocks
 * @param {number} k
 * @return {number}
 */
var minimumRecolors = function(blocks, k) {
    let white = 0, right = 0, ans = 100;
    for(right = 0; right < k; right++) {
        white += blocks[right] === 'W';
    }
   
    for(let left = 0; right < blocks.length; left++) {
        ans = Math.min(ans, white);
        white -= blocks[left] === 'W'; 
        white += blocks[right++] === 'W';
        // console.log(`left = ${left} & right = ${right} & white = ${white}`)
    }
    ans = Math.min(ans, white);
    return ans;
};