/*
Given an integer n, return the number of prime numbers that are strictly less than n.

Ex1)
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/

function solution(n) {
    if (n < 2)
        return 0;
    let arr = [];
    for (let i = 0; i < n; i += 1) {
        arr[i] = true;
    }
    arr[0] = false;
    arr[1] = false;
    for (let i = 2; i * i <= n; i += 1) {
        if (!arr[i])
            continue;
        for (let j = i * i; j < n; j += i) {
                arr[j] = false;
        }
    }
    let result = arr.filter(element => true === element).length;
    return result;
};

console.log(solution(10));
