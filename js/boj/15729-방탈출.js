/*
[boj] 방탈출
https://www.acmicpc.net/problem/15729
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./testcase/15729.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");
const n = parseInt(input[0]);
const light = input[1].split(" ").map(Number);
const map = Array(n).fill(0);
let answer = 0;

for (let i = 0; i < n; i++) {
	if (light[i] === map[i]) continue;
	answer++;
	for (let j = i; j < i + 3 && j < n; j++) {
		if (map[j] === 0) map[j] = 1;
		else map[j] = 0;
	}
}
console.log(answer);
