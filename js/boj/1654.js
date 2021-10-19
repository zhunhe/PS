/*
[boj] 랜선 자르기(1654)
https://www.acmicpc.net/problem/1654
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const filePath =
	process.platform === "linux" ? "/dev/stdin" : "./testcase/1654.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");
const k = parseInt(input[0].split(" ")[0]);
const n = parseInt(input[0].split(" ")[1]);

let line = [];
for (let i = 1; i < k + 1; i++) {
	line[i - 1] = parseInt(input[i]);
}

let left = 1;
let right = Math.max(...line);

let answer = 0;
function count(len) {
	let cnt = 0;
	for (let x of line) {
		cnt += parseInt(x / len);
	}
	return cnt;
}
while (left <= right) {
	let mid = parseInt((left + right) / 2);
	if (count(mid) >= n) {
		answer = mid;
		left = mid + 1;
	} else {
		right = mid - 1;
	}
}
console.log(answer);
