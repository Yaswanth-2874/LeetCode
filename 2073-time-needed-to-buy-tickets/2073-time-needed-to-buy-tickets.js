/**
 * @param {number[]} tickets
 * @param {number} k
 * @return {number}
 */
var timeRequiredToBuy = function(tickets, k) {
    let ans = tickets[k];
    for(let i = 0; i < tickets.length; i++) {
        if(i < k) {
            ans += tickets[i] > tickets[k] ? tickets[k] : tickets[i];
        }
        else if (i > k)
            ans += tickets[i]  > tickets[k] - 1 ? tickets[k] - 1 : tickets[i];
    }
    return ans;
};

