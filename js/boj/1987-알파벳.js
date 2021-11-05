/*
[boj] 알파벳
https://www.acmicpc.net/problem/1987
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./testcase/1987.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");
const r = parseInt(input[0].split(" ")[0]);
const c = parseInt(input[0].split(" ")[1]);
const board = [];
for (let i = 1; i < r + 1; i++) {
	board[i - 1] = input[i].split("");
}

const visited = Array(26).fill(false);

let answer = 1;
function DFS(L, y, x) {
	const dy = [-1, 0, 1, 0];
	const dx = [0, 1, 0, -1];

	for (let k = 0; k < 4; k++) {
		const ny = y + dy[k];
		const nx = x + dx[k];

		if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
		if (visited[board[ny][nx].charCodeAt() - 65]) continue;

		visited[board[ny][nx].charCodeAt() - 65] = true;
		DFS(L + 1, ny, nx);
		visited[board[ny][nx].charCodeAt() - 65] = false;
	}
	answer = Math.max(answer, L);
}
visited[board[0][0].charCodeAt() - 65] = true;
DFS(1, 0, 0);
console.log(answer);
