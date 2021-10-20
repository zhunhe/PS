/*
[boj] 가장 긴 바이토닉 부분 수열
https://www.acmicpc.net/problem/11054
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const filePath =
	process.platform === "linux" ? "/dev/stdin" : "./testcase/11054.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");
const n = parseInt(input[0]);
let nums = input[1].split(" ").map((item) => +item);

function solution(nums) {
	let answer = 0;

	let n = nums.length;
	let dy1 = Array(n).fill(1);
	let dy2 = Array(n).fill(1);

	for (let i = 0; i < n; i++) {
		for (let j = 0; j < i; j++) {
			if (nums[j] < nums[i]) {
				dy1[i] = Math.max(dy1[i], dy1[j] + 1);
			}
		}
	}

	for (let i = n - 1; i >= 0; i--) {
		for (let j = i + 1; j < n; j++) {
			if (nums[j] < nums[i]) {
				dy2[i] = Math.max(dy2[i], dy2[j] + 1);
			}
		}
	}

	for (let i = 0; i < n; i++) {
		answer = Math.max(answer, dy1[i] + dy2[i]);
	}
	return answer - 1;
}
console.log(solution(nums));
