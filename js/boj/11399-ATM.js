/*
[boj] ATM(11399번)
https://www.acmicpc.net/problem/11399
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const filePath = process.platform === 'linux' ? '/dev/stdin' : './testcase/11399.txt';
let input = fs.readFileSync(filePath).toString().trim().split("\n");
const n = parseInt(input[0]);
let nums = [];
for (let i = 0; i < n; i++) {
    nums.push(parseInt(input[1].split(" ")[i]));
}
nums.sort((a,b) => a - b);

let tmp = 0;
let answer = 0;
for (let i = 0; i < n; i++) {
    tmp += nums[i];
    answer += tmp;
}
console.log(answer);