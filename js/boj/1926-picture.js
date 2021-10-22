/*
[boj] 그림(1926번)
https://www.acmicpc.net/problem/1926
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const { DefaultSerializer } = require("v8");
const filePath =
	process.platform === "linux" ? "/dev/stdin" : "./testcase/1926.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

// 세로, 가로, 그림 정보 값 세팅
const height = parseInt(input[0].split(" ")[0]);
const width = parseInt(input[0].split(" ")[1]);
let board = [];
for (let i = 1; i < height + 1; i++) {
	board[i - 1] = input[i].split(" ").map((item) => +item);
}
let visited = [...Array(height)].map((e) => Array(width).fill(false));
let queue = [];

const dy = [-1, 0, 1, 0];
const dx = [0, 1, 0, -1];

let cnt = 0;
let maxArea = 0;
function BFS() {
	let area = 1;
	while (queue.length) {
		const len = queue.length;
		for (let i = 0; i < len; i++) {
			const [y, x] = queue.shift();
			for (let k = 0; k < 4; k++) {
				const ny = y + dy[k];
				const nx = x + dx[k];

				if (ny < 0 || ny >= height || nx < 0 || nx >= width) continue;
				if (visited[ny][nx] || board[ny][nx] !== 1) continue;

				visited[ny][nx] = visited[y][x] + 1;
				queue.push([ny, nx]);
				area++;
			}
		}
	}
	maxArea = Math.max(maxArea, area);
}

for (let i = 0; i < height; i++) {
	for (let j = 0; j < width; j++) {
		if (board[i][j] && !visited[i][j]) {
			visited[i][j] = true;
			queue.push([i, j]);
			cnt++;
			BFS();
		}
	}
}

console.log(cnt);
console.log(maxArea);
