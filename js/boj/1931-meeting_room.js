/*
[boj] 회의실 배정(1931번)
https://www.acmicpc.net/problem/1931
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./testcase/1931.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");
const n = parseInt(input[0]);

// 받아온 값 세팅
let nums = [];
for (let i = 1; i < n + 1; i++) {
	nums[i - 1] = input[i].split(" ").map(Number);
}

nums.sort((a, b) => {
	if (a[1] === b[1]) return a[0] - b[0];
	else return a[1] - b[1];
});

let et = 0;
let answer = 0;
for (x of nums) {
	if (x[0] >= et) {
		answer++;
		et = x[1];
	}
}
console.log(answer);
