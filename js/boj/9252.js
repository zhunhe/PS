/*
[boj] LCS2 (9252)
https://www.acmicpc.net/problem/9252
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const filePath =
	process.platform === "linux" ? "/dev/stdin" : "./testcase/9252.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");
const s1 = " " + input[0];
const s2 = " " + input[1];

let dy = [...Array(s1.length)].map((e) => Array(s2.length).fill(""));

for (let i = 1; i < s1.length; i++) {
	for (let j = 1; j < s2.length; j++) {
		if (s1[i] === s2[j]) {
			dy[i][j] = dy[i - 1][j - 1] + s1[i];
		} else {
			if (dy[i][j - 1].length >= dy[i - 1][j].length)
				dy[i][j] = dy[i][j - 1];
			else dy[i][j] = dy[i - 1][j];
		}
	}
}
console.log(dy[s1.length - 1][s2.length - 1].length);
console.log(dy[s1.length - 1][s2.length - 1]);
