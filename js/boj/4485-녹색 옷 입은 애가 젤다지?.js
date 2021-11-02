/*
[boj] 녹색 옷 입은 애가 젤다지?
https://www.acmicpc.net/problem/4485
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./testcase/4485.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

for (let i = 0; i < input.length; i++) {
	input[i] = input[i].split(" ").map(Number);
}
let idx = 0;
let problem = 1;
while (input[idx][0] !== 0) {
	let len = input[idx++][0];
	let map = [];
	for (let i = 0; i < len; i++) {
		map[i] = input[idx++];
	}
	let answer = [...Array(len)].map((_) => Array(len).fill(Infinity));
	let queue = [];
	queue.push([0, 0]);
	answer[0][0] = map[0][0];
	BFS();

	function BFS() {
		const dy = [-1, 0, 1, 0];
		const dx = [0, 1, 0, -1];

		while (queue.length) {
			const queue_len = queue.length;

			for (let i = 0; i < queue_len; i++) {
				const [y, x] = queue.shift();
				for (let k = 0; k < 4; k++) {
					const ny = y + dy[k];
					const nx = x + dx[k];

					if (ny < 0 || ny >= len || nx < 0 || nx >= len) continue;
					if (answer[y][x] + map[ny][nx] < answer[ny][nx]) {
						answer[ny][nx] = answer[y][x] + map[ny][nx];
						queue.push([ny, nx]);
					}
				}
			}
		}
	}
	console.log("Problem " + String(problem) + ": " + String(answer[len - 1][len - 1]));
	problem++;
}
