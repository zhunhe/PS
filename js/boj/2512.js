/*
[boj] 예산(2512)
https://www.acmicpc.net/problem/2512
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const filePath =
	process.platform === "linux" ? "/dev/stdin" : "./testcase/2512.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");
const n = parseInt(input[0]);
const budget = input[1].split(" ").map((item) => +item);
const m = parseInt(input[2]);

let left = 1;
let right = m;

let answer = left;
while (left <= right) {
	let mid = parseInt((left + right) / 2);
	if (sumOfBudget(mid) > m) {
		right = mid - 1;
	} else {
		left = mid + 1;
		answer = mid;
	}
}

function sumOfBudget(mid) {
	let answer = 0;
	for (x of budget) {
		if (x < mid) answer += x;
		else answer += mid;
	}
	return answer;
}

if (answer > Math.max(...budget)) console.log(Math.max(...budget));
else console.log(answer);
