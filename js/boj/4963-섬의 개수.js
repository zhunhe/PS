/*
[boj] 섬의 개수
https://www.acmicpc.net/problem/4963
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const { DefaultSerializer } = require("v8");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./testcase/4963.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

let idx = 0;
let answer = 0;

while (1) {
	const [w, h] = input[idx++].split(" ").map((v) => +v);
	if (w === 0 && h === 0) break;
	const map = [];
	for (let i = 0; i < h; i++) {
		map[i] = input[idx++].split(" ").map((v) => +v);
	}
	const dy = [-1, -1, 0, 1, 1, 1, 0, -1];
	const dx = [0, 1, 1, 1, 0, -1, -1, -1];

	function DFS(y, x) {
		for (let k = 0; k < 8; k++) {
			const ny = y + dy[k];
			const nx = x + dx[k];

			if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
			if (map[ny][nx] !== 1) continue;
			map[ny][nx] = 2;
			DFS(ny, nx);
		}
	}
	for (let i = 0; i < h; i++) {
		for (let j = 0; j < w; j++) {
			if (map[i][j] !== 1) continue;
			map[i][j] = 2;
			DFS(i, j);
			answer++;
		}
	}
	console.log(answer);
	answer = 0;
}
