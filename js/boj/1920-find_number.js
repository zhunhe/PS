/*
[boj] 수 찾기(1920)
https://www.acmicpc.net/problem/1920
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const filePath =
	process.platform === "linux" ? "/dev/stdin" : "./testcase/1920.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");
const N = parseInt(input[0]);
const A = input[1].split(" ").map((item) => +item);
const M = parseInt(input[2]);
const X = input[3].split(" ").map((item) => +item);

A.sort((a, b) => a - b);

for (let i = 0; i < M; i++) {
	let left = 0;
	let right = A.length - 1;
	let find = false;

	while (left <= right) {
		let mid = parseInt((left + right) / 2);
		if (A[mid] === X[i]) {
			find = true;
			break;
		}
		if (X[i] > A[mid]) left = mid + 1;
		else right = mid - 1;
	}
	if (find) console.log(1);
	else console.log(0);
}
