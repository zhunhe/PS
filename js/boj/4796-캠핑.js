/*
[boj] 캠핑
https://www.acmicpc.net/problem/4796
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./testcase/4796.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

let idx = 0;
while (parseInt(input[idx]) !== 0) {
	const [l, p, v] = input[idx].split(" ").map(Number);
	const answer = parseInt(v / p) * l + Math.min(l, v % p);
	console.log("Case " + String(idx + 1) + ": " + String(answer));
	idx++;
}
