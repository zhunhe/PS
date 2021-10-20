/*
[boj] 듣보잡
https://www.acmicpc.net/problem/1764
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const filePath =
	process.platform === "linux" ? "/dev/stdin" : "./testcase/1764.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");
const n = parseInt(input[0].split(" ")[0]);
const m = parseInt(input[0].split(" ")[1]);

name1 = [];
for (let i = 1; i < n + 1; i++) {
	name1[i - 1] = input[i];
}
name2 = [];
for (let i = n + 1; i < n + m + 1; i++) {
	name2[i - n - 1] = input[i];
}

let nH = new Map();
let answer = [];

for (const x of name1) {
	nH.set(x, (nH.get(x) || 0) - 1);
}

for (const x of name2) {
	if (nH.has(x)) answer.push(x);
}
answer.sort();
console.log(answer.length);
for (const x of answer) console.log(x);
