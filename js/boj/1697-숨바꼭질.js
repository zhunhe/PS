/*
[boj] 숨바꼭질(1697)
https://www.acmicpc.net/problem/1697
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const filePath =
	process.platform === "linux" ? "/dev/stdin" : "./testcase/1697.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");
const n = parseInt(input[0].split(" ")[0]);
const x = parseInt(input[0].split(" ")[1]);
let ch = Array(100001).fill(0);
let queue = [];

let L = 0;
queue.push(n);
ch[n] = 1;
function BFS() {
	while (queue.length) {
		const len = queue.length;
		for (let i = 0; i < len; i++) {
			const now = queue.shift();
			if (now === x) return L;

			for (const nx of [now - 1, now + 1, now * 2]) {
				if (nx < 0 || nx > 100000 || ch[nx] !== 0) continue;
				ch[nx] = 1;
				queue.push(nx);
			}
		}
		L++;
	}
}

console.log(BFS());
