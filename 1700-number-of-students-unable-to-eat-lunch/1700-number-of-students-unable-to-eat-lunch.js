/**
 * @param {number[]} students
 * @param {number[]} sandwiches
 * @return {number}
 */
var countStudents = function(students, sandwiches) {
    let zeroCount = 0, oneCount = 0;
    for(const element of students) {
        element === 0 ? zeroCount++ : oneCount++;
    }
    
    for(const element of sandwiches) {
        if(element === 0) {
            if(zeroCount === 0)
                return oneCount;
            else
                zeroCount--;
        }
        else {
            if(oneCount === 0)
                return zeroCount;
            else
                oneCount--;
        }
    }
    return 0;
};