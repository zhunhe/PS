/*
[boj] 빗물(14719)
https://www.acmicpc.net/problem/14719
*/

const fs = require("fs");
const filePath =
	process.platform === "linux" ? "/dev/stdin" : "./testcase/14719.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

// 입력값 세팅
const h = parseInt(input[0].split(" ")[0]);
const w = parseInt(input[0].split(" ")[1]);
let nums = input[1].split(" ");
for (let i = 0; i < w; i++) {
	nums[i] = parseInt(nums[i]);
}

// 2차원 맵 세팅
let board = [...Array(h)].map((e) => Array(w).fill(0));
for (let i = 0; i < w; i++) {
	let cnt = nums[i];
	for (let j = h - 1; j >= 0; j--) {
		if (cnt === 0) break;
		board[j][i] = 2;
		cnt--;
	}
}

// 2차원 배열에서
// 투포인터로 빗물 갯수 카운팅
let answer = 0;
for (let i = 0; i < h; i++) {
	let left = 0;
	for (let right = 0; right < w; right++) {
		if (board[i][left] === 0) {
			left++;
		}
		if (board[i][left] === 2 && board[i][right] === 2) {
			while (left < right) {
				if (board[i][left] === 0) {
					board[i][left] = 1;
					answer++;
				}
				left++;
			}
		}
	}
}

console.log(answer);
