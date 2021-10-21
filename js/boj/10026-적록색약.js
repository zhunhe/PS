/*
[boj] 적록색약(10026)
https://www.acmicpc.net/problem/10026
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const filePath =
	process.platform === "linux" ? "/dev/stdin" : "./testcase/10026.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");
const n = parseInt(input[0]);
let board = [...Array(n)].map((_) => Array(n));
let visited = [...Array(n)].map((_) => Array(n).fill(false));
for (let i = 1; i < n + 1; i++) {
	board[i - 1] = input[i].split("");
}

const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];

const normal = 0;
const rgWeak = 1;

function DFS(i, j, mode) {
	for (let k = 0; k < 4; k++) {
		const ny = i + dy[k];
		const nx = j + dx[k];

		// Out of range
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		// 이미 방문한 좌표
		if (visited[ny][nx]) continue;
		// 정상인의 경우
		if (mode === normal) {
			if (board[i][j] !== board[ny][nx]) continue; // 다른색인 경우
			// 적록색약의 경우
		} else {
			// 다른색인 경우
			if (board[i][j] === "B") {
				if (board[i][j] !== board[ny][nx]) continue;
			} else {
				if (board[ny][nx] === "B") continue;
			}
		}
		visited[ny][nx] = true;
		DFS(ny, nx, mode);
	}
}

// 정상인의 경우
let normalPersonCnt = 0;
for (let i = 0; i < n; i++) {
	for (let j = 0; j < n; j++) {
		if (visited[i][j]) continue;

		normalPersonCnt++;
		visited[i][j] = true;
		DFS(i, j, normal);
	}
}

// visited 초기화
for (let i = 0; i < n; i++) {
	for (let j = 0; j < n; j++) {
		visited[i][j] = false;
	}
}

// 적록색약의 경우
let rgWeakPersonCnt = 0;
for (let i = 0; i < n; i++) {
	for (let j = 0; j < n; j++) {
		if (visited[i][j]) continue;

		rgWeakPersonCnt++;
		visited[i][j] = true;
		DFS(i, j, rgWeak);
	}
}

console.log(normalPersonCnt, rgWeakPersonCnt);
