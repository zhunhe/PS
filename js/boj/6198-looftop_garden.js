/*
[boj] 옥상 정원 꾸미기(6198)
https://www.acmicpc.net/problem/6198
*/

const fs = require("fs");
const filePath = process.platform === 'linux' ? '/dev/stdin' : './testcase/6198.txt';
let input = fs.readFileSync(filePath).toString().trim().split("\n");

let len = input[0];
let heights = [];
for (let i = 1; i < input.length; i++) {
    heights.push(parseInt(input[i]));
}

let answer = 0;
let stack = [];

for (let i = 0; i < len; i++) {
    while (stack.length && heights[i] >= stack[stack.length - 1]) {
        stack.pop();
    }
    answer += stack.length;
    stack.push(heights[i]);
}
console.log(answer);