/*
[boj] 토마토(7576)
https://www.acmicpc.net/problem/7576
*/

// 파일로부터 값 입력 받기
const { BADFLAGS } = require("dns");
const fs = require("fs");
const filePath =
	process.platform === "linux" ? "/dev/stdin" : "./testcase/7576.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");
const m = parseInt(input[0].split(" ")[0]);
const n = parseInt(input[0].split(" ")[1]);

let board = [];
for (let i = 1; i < n + 1; i++) {
	board[i - 1] = input[i].split(" ").map((item) => +item);
}

let answer = 0;
const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];
let queue = [];
let idx = 0;

function BFS() {
	while (idx < queue.length) {
		const [y, x] = queue[idx++];

		for (let k = 0; k < 4; k++) {
			const ny = y + dy[k];
			const nx = x + dx[k];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (board[ny][nx] !== 0) continue;

			board[ny][nx] = board[y][x] + 1;
			answer = Math.max(answer, board[ny][nx]);
			queue.push([ny, nx]);
		}
	}
}

for (let i = 0; i < n; i++) {
	for (let j = 0; j < m; j++) {
		if (board[i][j] === 1) {
			queue.push([i, j]);
		}
	}
}
BFS();

for (let i = 0; i < n; i++) {
	for (let j = 0; j < m; j++) {
		if (board[i][j] === 0) {
			console.log(-1);
			return;
		}
	}
}
console.log(answer === 0 ? 0 : answer - 1);
