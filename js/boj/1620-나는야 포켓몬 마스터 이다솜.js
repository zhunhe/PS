/*
[boj] 나는야 포켓몬 마스터 이다솜(1620)
https://www.acmicpc.net/problem/1620
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./testcase/1620.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");
const n = parseInt(input[0].split(" ")[0]);
const m = parseInt(input[0].split(" ")[1]);

const book = [];
for (let i = 1; i < n + 1; i++) book[i - 1] = input[i];
const problem = [];
for (let i = n + 1; i < n + m + 1; i++) problem[i - n - 1] = input[i];

let numH = new Map();
let nameH = new Map();
for (let i = 0; i < book.length; i++) {
	numH[i + 1] = book[i];
	nameH[book[i]] = i + 1;
}

let answer = [];
for (let p of problem) {
	if (isNaN(p)) answer.push(nameH[p]);
	else answer.push(numH[String(p)]);
}
for (const a of answer) console.log(a);
