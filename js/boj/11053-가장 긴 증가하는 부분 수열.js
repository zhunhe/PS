/*
[boj] 가장 긴 증가하는 부분 수열
https://www.acmicpc.net/problem/11053
*/

const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./testcase/11053.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");
const n = parseInt(input[0]);
const nums = input[1].split(" ").map(Number);

let answer = 1;
let dy = Array(n).fill(0);
dy[0] = 1;
for (let i = 1; i < n; i++) {
	let max = 0;
	for (let j = i - 1; j >= 0; j--) {
		if (nums[j] >= nums[i]) continue;
		if (dy[j] <= max) continue;
		max = dy[j];
	}
	dy[i] = max + 1;
	answer = Math.max(answer, dy[i]);
}
console.log(answer);
