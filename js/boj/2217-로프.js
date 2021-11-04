/*
[boj] 로프
https://www.acmicpc.net/problem/2217
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./testcase/2217.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");
const k = parseInt(input[0]);
const w = [];
for (let i = 1; i < k + 1; i++) {
	w[i - 1] = parseInt(input[i]);
}

w.sort((a, b) => a - b);
let max = Number.MIN_SAFE_INTEGER;
for (let i = 0; i < w.length; i++) {
	max = Math.max(max, w[i] * (k - i));
}
console.log(max);
